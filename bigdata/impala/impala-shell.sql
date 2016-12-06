--impala driver and url
--driver=org.apache.hive.jdbc.HiveDriver
--url=jdbc:hive2://url:port/;auth=noSasl
--into impala
impala-shell

--show tables
show tables;

--desc table
desc tableName;

--show create table sql by tableName
show create table tableName;

--refresh table
refresh tableName;

--select 3 records by partitionValue
select * from tableName where auth_time_p='20160517' limit 3;

--show partitions
show partitions tableName;

--add pardition with partitionValue
ALTER TABLE tableName ADD PARTITION(partitionName='partitionValue');

--drop pardition by partitionValue
ALTER TABLE tableName DROP PARTITION(partitionName='partitionValue');

--count by partitionValue
select count(*) from tableName where auth_time_p='partitionValue';
select count(*) from tableName where auth_time_p='partitionValue1' or auth_time_p='partitionValue2';

--计算分区
compute stats tableName;

--增量计算分区
compute incremental stats tableName;

--group by
select count(*),auth_type from tableName where auth_time_p='20160524' group by auth_type;