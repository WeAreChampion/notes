# jmap:生成Java应用程序的堆快照和对象的统计信息

# 生成PID为2972的Java程序的对象统计信息，并输出到文件
# 显示内存中的实例数量和合计
jmap -histo 2972 > c:test.txt

# 将应用程序的堆快照输出文件中
# 可以使用jhat与Visual VM工具查看堆快照文件
jmap -dump:format=b,file=c:heap.hprof 2972