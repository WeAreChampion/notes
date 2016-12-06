# sar [options] [-A] [-o file] t [n]
# t 为采样间隔， n 为采样次数，默认值是1
# -o file表示将命令结果以二进制格式存放在文件中，file 是文件名
# -A：所有报告的总和
# -u：输出CPU使用情况的统计信息
# -v：输出inode、文件和其他内核表的统计信息
# -d：输出每一个块设备的活动信息
# -r：输出内存和交换空间的统计信息
# -b：显示I/O和传送速率的统计信息
# -a：文件读写情况
# -c：输出进程统计信息，每秒创建的进程数
# -R：输出内存页面的统计信息
# -y：终端设备活动情况
# -w：输出系统交换活动信息

# -u 输出项说明：
# CPU：all 表示统计信息为所有 CPU 的平均值。
# %user：显示在用户级别(application)运行使用 CPU 总时间的百分比。
# %nice：显示在用户级别，用于nice操作，所占用 CPU 总时间的百分比。
# %system：在核心级别(kernel)运行所使用 CPU 总时间的百分比。
# %iowait：显示用于等待I/O操作占用 CPU 总时间的百分比。
# %steal：管理程序(hypervisor)为另一个虚拟进程提供服务而等待虚拟 CPU 的百分比。
# %idle：显示 CPU 空闲时间占用 CPU 总时间的百分比。
# 1. 若 %iowait 的值过高，表示硬盘存在I/O瓶颈
# 2. 若 %idle 的值高但系统响应慢时，有可能是 CPU 等待分配内存，此时应加大内存容量
# 3. 若 %idle 的值持续低于1，则系统的 CPU 处理能力相对较低，表明系统中最需要解决的资源是 CPU 

# using sar counts the cpu infos, every second count once,all counts are 3.
# 使用 sar统计 cpu 使用情况，每秒统计一次，共采样三次
sar -u 1 3

# CPU 的使用情况，每秒统计一次，共采样三次，并将结果以二进制形式存入当前目录下的test文件
sar -u -o test 10 3

# 要查看二进制文件test中的内容
sar -u -f test

# -v 输出项说明：
# dentunusd：目录高速缓存中未被使用的条目数量
# file-nr：文件句柄（file handle）的使用数量
# inode-nr：索引节点句柄（inode handle）的使用数量
# pty-nr：使用的pty数量

# inode、文件和其他内核表监控
sar -v 1 3

# 查看内存使用情况
sar -r 1 3

# 查看 I/O 信息
sar -b 1 3

# 内存分页信息
sar -B 1 3

# 监控进程队列长度和平均负载状态
sar -q 1 3
