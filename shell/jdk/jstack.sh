# jstack:用于导出Java应用程序的堆栈
# 不仅可以得到线程堆栈，还能自动进行死锁检查，输出死锁信息

# -l:用于打印锁的附加信息
# 语法:jstack [-l] <PID>

# 导出 PID=2472 的线程堆栈锁信息
jstack -l 2472 > C:test.txt