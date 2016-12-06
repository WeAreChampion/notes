--查看 mysql 最大连接数:
show variables like '%max_connections%';

--修改最大连接数
--方法一: 修改配置文件。
--进入MySQL安装目录 打开MySQL配置文件 my.ini 或 my.cnf
--查找 max_connections=100修改为 max_connections=1000 服务里重起MySQL即可
--方法二: 命令行修改。不推荐方法二
--命令行登录MySQL后。设置新的MySQL最大连接数为200
--一旦 mysql 重启，又会恢复到初始状态
set global max_connections=200

-- show all connections
show processlist;
show full processlist

--insert the select column
INSERT INTO tableName_bak values(t.c1,t.c2,t.c3) SELECT t.c1,t.c2,t.c3 FROM tableName t;

--备份表(数据与结构)
CREATE TABLE tableName_bak SELECT * FROM tableName;

--数据导入
INSERT INTO tableName_bak SELECT * FROM tableName;

-- copy table
create table tableName_bak like tableName;