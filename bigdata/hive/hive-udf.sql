--using
add jar hdfs:///hiveudf/udf.jar;

--drop temp udf
drop temporary function udfName;

--create udf
create temporary function udfName as 'com.sky.projects.hive.udf.TestUDF';

--using udf
select udfName(field) from tableName;