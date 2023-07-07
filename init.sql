-- 基本操作
create database testManagement;
use testManagement;

-- 创建读者表
create table stu(
    id int primary key comment 'id of reader',
    name varchar(10),
    gender char(1) default '男',
    tel char(11) not null comment '电话号码 ',
    borrow_num int comment '正在借阅数目数量',
    bookRead_num smallint unsigned comment '阅读量',
    defy_num int default 0 comment '违规次数',
    username varchar(20) unique comment 'username of stu',
    password varchar(20) not null
) comment '读者信息';

-- 修改读者表字段默认值
alter table stu modify borrow_num smallint default 0;
alter table stu modify bookRead_num smallint default 0;
alter table stu modify defy_num smallint default 0;

-- 创建管理员表
create table admin(
    id int primary key comment 'id of administrator',
    name varchar(20) not null,
    username varchar(20) unique comment 'username of admin',
    password varchar(20) not null
) comment '管理员信息';

-- 创建图书信息表
create table book_info(
    isbn int primary key comment 'id of book',
    name varchar(30) not null,
    author varchar(10) not null,
    publisher varchar(20) not null comment '出版社',
    addTime date not null comment '添加时间'
);

-- 创建借阅记录表
create table book_record(
    id int primary key auto_increment comment '借书信息的主键',
    stu_id int not null,
    book_id int not null,
    isOver smallint comment '此借阅是否归还结束？', -- 0代表未结束即正在借阅，1表示已经归还
    recordTime datetime comment '书本借阅时间',
    backTime datetime comment '理应归还时间',
    constraint fk_stu_id foreign key (stu_id) references stu(id),
    constraint fk_book_id foreign key (book_id) references book_info(isbn)
);

-- 创建书本评价表
create table star_book(
    id int primary key auto_increment,
    book_id int not null,
    estimate_num int unsigned not null comment '评价次数',
    star double default null comment '平均的评价等级',
    constraint fk_star foreign key (book_id) references book_info(isbn)
) comment '书本评价';

-- 创建日志记录表
create table log(
    id int primary key auto_increment,
    log_time datetime comment '日志时间',
    event varchar(50) not null
) comment '日志记录';

-- 创建自动添加借书日志的触发器
delimiter ##
create trigger trigger_record_book after insert on book_record for each row
begin
    insert into log values (NULL, NOW(), CONCAT('id号为', new.stu_id, '的读者借阅了一本书,ISBN号为', new.book_id));
    update stu set borrow_num = borrow_num + 1, bookRead_num = bookRead_num + 1 where stu.id = new.stu_id;
end;
##
delimiter ;

-- 创建自动添加归还日志/续借日志的触发器
delimiter ##
create trigger trigger_return_book after update on book_record for each row
begin
    if (new.isOver <> old.isOver and now() < new.backTime) then
        insert into log values (null, now(), concat('id号为', new.stu_id, '的读者归还了一本书，ISBN号为', new.book_id));
        update stu set borrow_num = borrow_num - 1 where stu.id = new.stu_id;
    elseif (new.backTime <> old.backTime and now() < new.backTime) then
        insert into log values (null, now(), concat('id号为', new.stu_id, '的读者续借了一本书，ISBN号为', new.book_id));
    end if;
end;
##
delimiter ;

-- 创建自动添加读者日志的触发器
create trigger trigger_add_stu after insert on stu for each row
begin
    insert into log values (NULL, NOW(), CONCAT('id号为', new.id, '的读者', new.name, '被添加了'));
end;

-- 创建自动添加书本日志的触发器
create trigger trigger_add_book after insert on book_info for each row
begin
    insert into log values (NULL, NOW(), CONCAT('isbn号为', new.isbn, '的书本', new.name, '被添加了'));
end;

-- 创建定时事件，检查逾期未还的书籍
delimiter $$
create event check_over_books
on schedule every 1 minute
starts now()
do
begin
    -- 声明变量
    declare done int default 0;
    declare stu_id_use int;
    declare book_id_use int;

    -- 声明游标，检索所有未还书
    declare cur cursor for
        select book_id, stu_id from book_record where backTime < now() and isOver = 0;
    -- 检索完就设为1退出
    declare continue handler for not found set done = 1;
    -- 打开游标
    open cur;
    -- 读取数据
    read_data: LOOP
        fetch cur into book_id_use, stu_id_use;
        if done = 1 then
            leave read_data;
        end if;
        update book_record set isOver = 1 where book_id = book_record.book_id and stu_id = book_record.stu_id;
        insert into log values (null, now(), concat('书号为', book_id_use, '的书已经到期，借书学生ID为', stu_id_use));
        update stu set stu.defy_num = stu.defy_num + 1;
    end loop read_data;
    close cur;
    set done = 0;
end$$
delimiter ;

-- 测试
insert into admin values(1, 'admin01', 'admin', '1234');
insert into stu values(1, '王小明', '男', '15995187606', 0, 0, 0, 'wmr', '123');
insert into book_info values(1, '《C程序方法设计》', '未知', '清华大学出版社', now());
-- 借书
insert into book_record(stu_id, book_id, isOver, recordTime, backTime) values(1, 1, 0, now(), date_add(now(), interval 1 month));
insert into book_record(stu_id, book_id, isOver, recordTime, backTime) values(1, 1, 0, now(), date_add(now(), interval 1 minute));
-- 续借
update book_record set backTime = backTime + interval 1 month where id = 2;
update book_record set isOver = 1 where id = 2;
