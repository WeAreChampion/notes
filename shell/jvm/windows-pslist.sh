# pslist:一款Windows下的命令行工具
# 基本用法
# pslist [-d][-m][-x][-t][-s [n] [-r n] [name|pid]]
# -d:显示线程详细信息
# -m:显示内存详细信息
# -x:显示进程、内存和线程信息
# -t:显示进程间父子关系
# -s[n]:进入监控模式。n指定程序运行时间，使用Esc键退出。
# -rn:指定监控模式下的刷新时间，单位秒
# name:指定监控的进程名称，pslist 将监控所有以给定名字开头的进程
# -e:使用精确匹配，打开了这个开关，pslist 将只监控name参数指定的进程
# pid:指定进程ID

# 使用 pslist 列出所有Java应用程序进程
pslist java

# 使用-d显示进程详细信息
# 找到运行中具有最高Cswtch 上下文切换值的线程PID，换算成16进程，再到线程快照中查找这个线程ID
pslist java -d