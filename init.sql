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
    author varchar(10) not null,
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

create table star_book(
    id int primary key auto_increment,
    book_id int not null,
    estimate_num int unsigned not null,
    star double default null,
    constraint fk_star foreign key (book_id) references book_info(isbn)
);

create table log(
    id int primary key auto_increment,
    log_time datetime,
    event varchar(50) not null
);

delimiter ##
create trigger trigger_record_book after insert on book_record for each row
    begin
        INSERT INTO log VALUES (NULL, NOW(), CONCAT('id号为', new.stu_id, '的读者借阅了一本书,ISBN号为', new.book_id));
        update stu set borrow_num=borrow_num+1,bookRead_num=bookRead_num+1 where stu.id=new.stu_id;
    end;
##
delimiter ;

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

delimiter $$
create event check_over_books
on schedule every 1 minute
starts now()
do
    begin
        declare done int default 0;
        declare stu_id_use int ;
        declare book_id_use int ;

        declare cur cursor for
            select book_id,stu_id from book_record where backTime<now() and isOver=0;
        declare continue handler for not found set done=1;

        open cur;

        read_data:LOOP
            fetch cur into book_id_use,stu_id_use;
            if done=1 then
                leave read_data;
            end if;
            update book_record set isOver=1 where book_id=book_record.book_id and stu_id=book_record.stu_id;
            insert into log values(null,now(),concat('书号为', book_id_use, '的书已经到期，借书学生ID为', stu_id_use));
            update stu set stu.defy_num=stu.defy_num+1;
        end loop read_data;

        close cur;
        set done=0;
    end$$
delimiter ;
