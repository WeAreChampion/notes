--hive dynamic partition settings
--默认值：false;是否开启动态分区功能，默认false关闭。
set hive.exec.dynamic.partition=true;

--动态分区的模式，默认strict，表示必须指定至少一个分区为静态分区，nonstrict模式表示允许所有的分区字段都可以使用动态分区。一般需要设置为nonstrict
set hive.exec.dynamic.partition.mode=nonstrict;

--默认值：100,在每个执行MR的节点上，最大可以创建多少个动态分区。
set hive.exec.max.dynamic.partitions.pernode=10000;

--在所有执行MR的节点上，最大一共可以创建多少个动态分区。
set hive.exec.max.dynamic.partitions=10000;