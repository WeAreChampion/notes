cd $HIVE_HOME

# 在终端上显示mapreduce的进度，执行完毕后，最后把查询结果输出到终端上
# 接着hive进程退出，不会进入交互模式
bin/hive -e 'select a.col from tab1 a'

# 使用静音模式执行一个查询,加入-S
# 终端上的输出不会有mapreduce的进度，执行完毕，只会把查询结果输出到终端上。
# 这个静音模式很实用，通过第三方程序调用，第三方程序通过hive的标准输出获取结果集。
bin/hive -S -e 'select a.col from tab1 a'

# 使用静音模式执行一个查询，把结果集导出
bin/hive -S -e 'select a.col from tab1 a' > tab1.csv

# 不进入交互模式，执行一个hive script
# hive-script.sql是使用hive sql语法编写的脚本文件，执行的过程和-e类似，区别是从文件加载sql.
# 但是sql文件,对于bash来说，不能使用变量
# 而使用-e的方式，可以在bash里使用变量(但是对于sql文件的形式，可以利用程序基于变量动态生成sql文件，再执行)
# 可以和静音模式-S联合使用,通过第三方程序调用，第三方程序通过hive的标准输出获取结果集
bin/hive -f /home/my/hive-script.sql

# hive交互式模式,没有-e或者-f选项，会进入交互式shell模式。
bin/hive

# 退出交互式shell
quit
exit

# 重置配置为默认值
reset

# 修改特定变量的值
# 注意: 如果变量名拼写错误，不会报错
set <key>=<value>

# 输出用户覆盖的hive配置变量
set

# 输出所有Hadoop和Hive的配置变量
set -v

# 添加 一个或多个 file, jar,  archives到分布式缓存
dd FILE[S] <filepath> <filepath>*
add JAR[S] <filepath> <filepath>*
add ARCHIVE[S] <filepath> <filepath>*

# 输出已经添加到分布式缓存的资源。
list FILE[S]
list JAR[S]
list ARCHIVE[S]

# 检查给定的资源是否添加到分布式缓存
list FILE[S] <filepath>*
list JAR[S] <filepath>*
list ARCHIVE[S] <filepath>*

# 从分布式缓存删除指定的资源
delete FILE[S] <filepath>*
delete JAR[S] <filepath>*
delete ARCHIVE[S] <filepath>*

# 从Hive shell执行一个shell命令
! <command>

# 从Hive shell执行一个dfs命令
dfs <dfs command>

# 执行一个Hive 查询，然后输出结果到标准输出
<query string>

# 在CLI里执行一个hive脚本文件
source FILE <filepath>

# demo
set mapred.reduce.tasks=32;
set;
select a.* from tab1;
!ls;
dfs -ls;