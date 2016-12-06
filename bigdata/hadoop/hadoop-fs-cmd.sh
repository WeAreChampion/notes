# create input dir in hadoop
# 创建 hadoop 文件夹
hadoop fs -mkdir input

# list the hadoop file or dirs in hadoop
# 列出 hadoop 文件
hadoop fs -ls /

# hadoop put files into hadoop dir
# 上传文件到 hadoop 到 hadoop /input 目录
hadoop fs -put /opt/java/input/*.txt /input

# list hadoop /input dir files
# 列出 hadoop /input 目录
hadoop fs -ls /input

# run the wordcount app test
# @param hadoop 
# @param jar
# @param the run app jar : share/hadoop/mapreduce/hadoop-mapreduce-examples-2.6.0.jar
# @param the app name : wordcount
# @param the app input dir : /input
# @param the app output dir : /output/wordcount1
# 运行 hadoop 自带的 HelloWorld
hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.6.0.jar wordcount /input /output/wordcount1

# see the results
# 查看结果
hdfs dfs -cat /output/wordcount1/*

# download file data from hadoop and save with data in linux
# 从 hadoop 中下载文件并保存
hadoop fs -get data ./data

# 删除 hadoop 文件
hadoop fs -rmr abc
