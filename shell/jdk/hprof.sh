# hprof:hprof不是独立的监控工具，只是一个Java agent工具，可以用于监控Java应用程序在运行时的CPU信息和堆信息。
# 使用 java -agentlib:hprof=help 查看 hprof 的帮助文档

# 使用参数运行代码
# times选项将会在Java函数的调用前后记录函数的执行时间，进而计算函数的执行时间。
-agentlib:hprof=cpu=times,interval=10

# 将运用程序的堆快照保存在指定文件中
-agentlib:hprof=heap=dump,format=b,file=C:test.hprof

#  可以输出Java应用中各个类所占内存百分比
-agentlib:hprof=heap=sites