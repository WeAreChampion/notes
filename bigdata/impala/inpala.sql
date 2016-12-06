drop table if exists tableName;

create table tableName like templateTable;

alter table tableName add partition(pay_time_p='20160810');

alter table tableName drop partition(pay_time_p='20160811');

insert into table tableName_parquet partition(pay_time_p) select * from tableName;

insert overwrite table tableName_parquet partition(pay_time_p) select * from tableName;