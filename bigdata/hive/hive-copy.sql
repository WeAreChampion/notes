--hive table and data
--1. CREATE TABLE new_table LIKE old_table;
--2. 使用 hadoop fs -cp 命令，把old_table对应的HDFS目录的文件夹全部拷贝到new_table对应的HDFS目录下；
--3. 使用 MSCK REPAIR TABLE new_table;修复新表的分区元数据；

--table rename
alter table tableName rename to tableName_bak;

--copy table
CREATE TABLE tableName LIKE tableName_bak;

--hadoop copy cmd
--hadoop fs -cp /user/hive/warehouse/tableName_bak/* /user/hive/warehouse/tableName;

--refresh the table
-- hive option, repair the table
MSCK REPAIR TABLE tableName;

--chown the path's owner
--must use hdfs user to change the owner
sudo -u hdfs hadoop fs -chown -R impala /user/hive/warehouse/tableName_bak
