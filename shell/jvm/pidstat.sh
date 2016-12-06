# pidstat:一个功能强大的性能监测工具，也是Sysstat的组件之一。不仅可以监视进程的性能情况，也可以监视线程的性能情况。
# 可以监控CPU,IO,内存资源，甚至可以将问题定位到线程，方便应用程序的故障排查
# pidstat 工具不仅可以定位到进程，甚至可以进一步定位到线程。
# pidstat也可以监控进程内线程的IO情况。

# 使用jsp查看进程及PID
jps

# -p : 指定PID即进程ID
# -u : 对CPU使用率的监控
# 每秒采样一次，共采样3次
pidstat -p PID -u 1 3

# -t : 将系统性能的监控细化到线程级别
# 由此查看进程中线程的CPU等信息
pidstat -p PID 1 3 -u -t

# 导出指定Java应用程序的所有线程
# nid : 即线程PID，16进制表示
pidstat -l PID > dstFile

# -d : 表明监控对象为磁盘IO
pidstat -p PID -d -t 1 3

# -r : 内存监控
# minflt/s:表示该进程每秒minor faults(不需要从磁盘中调出内存页)的总数
# majflt/s:表示该进程每秒major faults(需要从磁盘中调出内存页)的总数
# VSZ:表示该进程使用的虚拟内存大小，单位为:KB
# RSS:表示该进程占用的物理内存大小，单位为:KB
# %MEM:表示占用内存比率
pidstat -p PID -r 1 3
