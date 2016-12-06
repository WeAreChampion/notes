--add partition
alter table tableName add partition(partitionColumn='partitionValue');

--drop null partition
alter table tableName drop partition(partitionColumn=null);

--count where partitionColumn is null
select count(*) from tableName where partitionColumn is null;

--default paritition value in hive:__HIVE_DEFAULT_PARTITION__
--when paritition is null, export will use the default paritition value.