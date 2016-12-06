--execute the sql's path, file is sql
--source an sql in mysql's shell
--mysql执行sql文件,like:source /root/test.sql
source sqlPath

--chown the path to mysql
--赋予导出目录权限给 mysql 用户,like:chown mysql:mysql /root/export
chown mysql:mysql /opt

--导出数据到指定文件
--export the results to file
--export query from mysql to local file
select * from tableName into outfile "/opt/tableName.txt";
select filed1[,filed2...] from tableName into outfile "/root/export/export.txt";