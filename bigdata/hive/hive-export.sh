#!/bin/bash
# export using hive -e
# save into table tableName_export
# save into hdfs dir
hive -e "
set dfs.replication=1;

drop table if exists tableName_export;

create table tableName_export ROW FORMAT DELIMITED FIELDS TERMINATED BY '\t' LINES TERMINATED BY '\n' LOCATION '/dir' as select * from tableName_export;
"