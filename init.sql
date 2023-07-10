create database LibraryManagement;
use LibraryManagement;

create table stu(
    id int primary key,
    name varchar(10),
    gender char(1) default  '男',
    tel char(11) not null,
    borrow_num smallint default 0,
    bookRead_num smallint default 0,
    defy_num smallint  default 0,
    username varchar(20) unique,
    password varchar(20) not null
);

create table admin(
    id int primary key,
    name varchar(20) not null,
    username varchar(20) unique,
    password varchar(20) not null
);

create table book_info(
    isbn int primary key,
    name varchar(30) not null,
    author varchar(50) not null,
    publisher varchar(20) not null,
    addTime date not null
);

create table book_record(
    id int primary key auto_increment,
    stu_id int not null,
    book_id int not null,
    isOver smallint,
    recordTime datetime,
    backTime datetime,
    constraint fk_stu_id foreign key (stu_id) references stu(id),
    constraint fk_book_id foreign key (book_id) references book_info(isbn)
);

create table log(
    id int primary key auto_increment,
    log_time datetime,
    event varchar(50) not null
);

create table unreturn_log(
    id int primary key auto_increment,
    stu_id int unique ,
    stu_name varchar(30),
    book_id int,
    book_name varchar(30),
    log_time datetime           -- 时间
);
#自动加入借书日志的
delimiter ##
create trigger trigger_record_book after insert on book_record for each row
    begin
        INSERT INTO log VALUES (NULL, NOW(), CONCAT('id号为', new.stu_id, '的读者借阅了一本书,ISBN号为', new.book_id));
        update stu set borrow_num=borrow_num+1,bookRead_num=bookRead_num+1 where stu.id=new.stu_id;
    end;
##
delimiter ;
drop trigger  trigger_record_book;

drop trigger trigger_return_book;
#自动添加读者日志
create trigger trigger_add_stu after insert on stu for each row
    begin
        INSERT INTO log VALUES (NULL, NOW(), CONCAT('id号为',new.id,'的读者',new.name,'被添加了'));
    end;
#自动删除读者日志
create trigger trigger_del_stu after delete on stu for each row
    begin
        INSERT INTO log VALUES (NULL, NOW(), CONCAT('id号为',old.id,'的读者',old.name,'资格被取消了'));
    end;
#自动更新读者日志
create trigger trigger_update_stu after update on stu for each row
    begin
        if (new.name<>old.name or new.tel<>old.tel or new.gender<>old.gender ) then
             INSERT INTO log VALUES (NULL, NOW(), CONCAT('id号为',old.id,'的读者',old.name,'信息被更新了'));
        end if;
    end;
#自动添加书本日志
create trigger trigger_add_book after insert on book_info for each row
    begin
        INSERT INTO log VALUES (NULL, NOW(), CONCAT('isbn号为',new.isbn,'的书本',new.name,'被添加了'));
    end;
#自动删除书本日志
DELIMITER ##

create trigger trigger_delete_book
before delete on book_info for each row
begin
    -- 更新学生借书信息
    update stu set borrow_num = borrow_num - 1 where id IN (
        select DISTINCT stu_id FROM book_record where book_id = OLD.isbn and isOver = 0
    );
    -- 删除book_record中对应的记录
    delete from book_record where book_id = old.isbn;
    INSERT INTO log VALUES (NULL, NOW(), CONCAT('isbn号为',old.isbn,'的书本',old.name,'被删除了'));

END##

DELIMITER ;
#自动更新书本日志
create trigger trigger_update_book after update on book_info for each row
    begin
        INSERT INTO log VALUES (NULL, NOW(), CONCAT('isbn号为',old.isbn,'的书本',old.name,'被更新了'));
    end;

delimiter ##
create trigger trigger_return_book after update on book_record for each row
    begin
        if (new.isOver<>old.isOver and now()<new.backTime) then
            insert into log values(null,now(),concat('id号为',new.stu_id,'的读者归还了一本书，ISBN号为',new.book_id));
            update stu set borrow_num=borrow_num-1 where stu.id=new.stu_id;
       elseif (new.backTime<>old.backTime and now()<new.backTime) then
            insert into log values(null,now(),concat('id号为',new.stu_id,'的读者续借了一本书，ISBN号为',new.book_id));
       end if;
    end;
##
delimiter ;

#时间调度事件
delimiter $$
create event check_over_books
on schedule every 1 minute
starts now()
do
    begin
        #声明变量
        declare done int default 0;
        declare stu_id_use int ;
        declare book_id_use int ;

        #声明游标,检索所有未还书
        declare cur cursor for
            select book_id,stu_id from book_record where backTime<now() and isOver=0;
        #检索完就设为1退出
        declare continue handler for not found set done=1;
        #打开游标
        open cur;
        #读取数据
        read_data:LOOP
            fetch cur into book_id_use,stu_id_use;
            if done=1 then
                leave read_data;
            end if;
            update book_record set isOver=1 where book_id=book_record.book_id and stu_id=book_record.stu_id;
            insert into log values(null,now(),concat('书号为', book_id_use, '的书已经到期，借书学生ID为', stu_id_use));
            update stu set stu.defy_num=stu.defy_num+1 ,stu.borrow_num=stu.borrow_num-1 where stu.id=stu_id_use;

            insert into unreturn_log(stu_id, stu_name, book_id, book_name, log_time)select stu_id_use, stu.name, book_id_use, book_info.name, NOW()
            from stu  join book_info on stu.id = stu_id_use and book_info.isbn = book_id_use;
        end loop read_data;
        close cur;
        set done=0;
    end$$
delimiter ;

#视图1
create VIEW book_record_view AS
select b.name, r.recordTime, r.backTime, s.id AS stu_id
from book_info AS b
inner join book_record AS r ON b.isbn = r.book_id
inner join stu AS s ON r.stu_id = s.id
where r.isOver = 0;

#视图2
create view book_view as
select b.isbn, b.name, b.author, b.publisher,
       case
           when r.id IS NULL then '未被借阅'
           else '已被借阅'
        end AS status
from book_info b
left join (
  select book_id, MAX(id) as max_id
  from book_record
  where isOver = 0
  group by book_id
) as latest on b.isbn = latest.book_id
left join book_record r on latest.book_id = r.book_id and latest.max_id = r.id;

#视图3
create view stuRating as
    select stu.name,stu.gender,stu.bookRead_num from stu;
