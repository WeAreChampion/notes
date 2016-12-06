--list hdfs dir "/user/impala"
--hadoop fs -ls /user/impala

--chown hadoop's "/user/impala" dir to user
-- must use hdfs user op
--hadoop fs -chown user /user/impala
-- or
--sudo hdfs hadoop fs -chown user /user/impala

-- load data from hive
invalidate metadata;

--invalidate the table
invalidate metadata tableName_test;

--drop partition
alter table tableName drop partition(create_time_p='20160720');

--insert overwrite sql must execute add partition sql
--add partition
alter table tableName add partition(create_time_p='20160720');

--create table with partition and stored with TEXTFILE(default)
--适合从文件中加载数据读取，即 LOAD DATA
CREATE TABLE tableName(CERTIFICATE_CODE STRING, NAME STRING, MOBILE STRING, QQ STRING, SOURCE INT, SYS_SOURCE TINYINT, CREATE_TIME BIGINT) PARTITIONED BY (CREATE_TIME_P STRING);

--create table with partition and stored with RCFILE
CREATE TABLE tableName(CERTIFICATE_CODE STRING, NAME STRING, MOBILE STRING, QQ STRING, SOURCE INT, SYS_SOURCE TINYINT, CREATE_TIME BIGINT) PARTITIONED BY (CREATE_TIME_P STRING) STORED AS RCFILE;

--create table with delimited and store with TEXTFILE
CREATE TABLE tableName(CERTIFICATE_CODE STRING, NAME STRING, MOBILE STRING, QQ STRING) partitioned by (CREATE_TIME_P STRING) ROW FORMAT DELIMITED FIELDS TERMINATED BY '\t' STORED AS TEXTFILE;

INSERT OVERWRITE TABLE SD_PERSON partition(create_time_p="20160720") select CERTIFICATE_CODE,NAME,MOBILE,QQ from tableName_TEST4 where create_time_p="20160720";

--create table STORED with PARQUET
--PARQUET 格式适合 从 RCFILE or TEXTFILE 使用 INSERT OVERWRITE 转换写入
CREATE TABLE SD_PERSON(CERTIFICATE_CODE STRING, NAME STRING, MOBILE STRING, QQ STRING) partitioned by (CREATE_TIME_P STRING) STORED AS PARQUET;
alter table SD_PERSON add partition(create_time_p='20160720');

--create table with partition and stored PARQUET
--store path: {hive.warehouse}/tableName/partitionName=partitionValue
CREATE TABLE tableName(CERTIFICATE_CODE STRING, NAME STRING, MOBILE STRING, QQ STRING) partitioned by (CREATE_TIME_P STRING) STORED AS PARQUET;

--table add partition
alter table tableName add partition(create_time_p='20160720');

--insert OVERWRITE into table with partition from the results.
--the results must select the columns exclude partition filed and must with partition
INSERT OVERWRITE TABLE tableName partition(create_time_p="20160720") select CERTIFICATE_CODE,NAME,MOBILE,QQ from tableName_TEST4 where create_time_p="20160720";