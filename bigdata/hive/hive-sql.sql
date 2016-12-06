--show tables
show tables;

--show tables using regex
show tables '.*s';

--CREATE A TABLE using fileds and type
CREATE TABLE tableName(foo INT, bar STRING);

--create table using LIKE
CREATE TABLE tableNameBak LIKE tableName;

--创建分区表,default stored TEXTFILE
--partitione are: dt and country
CREATE TABLE tableName(ts bigint, line string) partitioned by(dt String, country String);

--load data from file into table with partition
--加载分区表数据
LOAD DATA LOCAL INPATH 'linux file or hadoop file' INTO TABLE tableName partition(dt='2016-01-01', country='GB');
LOAD DATA INPATH 'hadoop file' INTO TABLE tableName partition(dt='2016-01-01', country='GB');

--展示表中分区
show partitions tableName;

--desc table
describe tableName;

--rename
ALTER TABLE src RENAME TO dir;

--add a column
ALTER TABLE tableName ADD COLUMNS(new_col INT COMMENT 'a new column');

--drop table
DROP TABLE tableName;

--delete table's data by hive's warehouse
dfs -rmr /user/hive/warehouse/tableName;

--load data overwrite into table
LOAD DATA LOCAL INPATH 'file path' OVERWRITE INTO TABLE tableName;

--显示所有函数
show functions;

--查看函数用法
describe function substr;

--查看数组、map、结构体
select col1[0], col2['b'], col3.c from complex;

--inner join
select sales.*, things.* FROM sales JOIN things ON (sales.id = things.id);

--查看为某个查询使用多少个MR作业
Explain select sales.*,things.* FROM sales JOIN things ON (sales.id = things.id);

--外连接
select sales.*,things.* FROM sales LEFT OUTER JOIN things ON (sales.id = things.id);
select sales.*,things.* FROM sales RIGHT OUTER JOIN things ON (sales.id = things.id);
select sales.*,things.* FROM sales FULL OUTER JOIN things ON (sales.id = things.id);

--in 查询， hive不支持，但可以使用 LEFT SEMI JOIN
select sales.*,things.* FROM sales LEFT SEMI JOIN things ON (sales.id = things.id);

--map连接: hive可以把较小的表放入每个Mapper的内存来执行连接操作
select /*+ MAPJOIN(things) */ sales.*,things.* FROM sales JOIN things ON (sales.id = things.id);

--CREATE TABLE ... AS SELECT：新表预先不存在
CREATE TABLE target AS SELECT col1,col2 FROM source;

--INSERT OVERWRITE TABLE ..SELECT：新表预先存在
INSERT OVERWRITE TABLE stations_by_year SELECT year, COUNT(DISTINCT station) GROUP BY year
INSERT OVERWRITE TABLE records_by_year SELECT year, COUNT(1) GROUP BY year
INSERT OVERWRITE TABLE good_records_by_year SELECT year, COUNT(1) WHERE temperature != 9999 AND (quality = 0 OR quality = 1 OR quality = 4 OR quality = 5 OR quality = 9) GROUP BY year;  

--创建视图
CREATE VIEW viewName AS SELECT * FROM tableName WHERE temperature != 9999

--查看视图详细信息：
DESCRIBE EXTENDED viewName;

--@param start: 第二个字符
--@param len: 截取字符长度
select substr(str,2,length(str)-2) from canyin15 limit 10;

--建表和加载数据指令小结 以及使用Load data指令的注意事项
--http://www.cnblogs.com/tugeler/p/5133019.html

CREATE EXTERNAL TABLE testHiveDriverTable(hostname string,logdate string, type string,class string,demo array<string>) row format delimited fields terminated by '|' COLLECTION items terminated BY '@' stored as textfile location

--修改字段注释字符集
alter table COLUMNS_V2 modify column COMMENT varchar(256) character set utf8;

--修改表注释字符集
alter table TABLE_PARAMS modify column PARAM_VALUE varchar(4000) character set utf8;

--修改分区注释字符集
alter table PARTITION_KEYS modify column PKEY_COMMENT varchar(4000) character set utf8;