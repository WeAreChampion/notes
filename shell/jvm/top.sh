# top:实时显示系统中各个进程的资源占用情况。
# 信息分为两部分:前半部分是系统统计信息，后半部分是进程信息
# 第一行是任务队列信息:结果等于uptime命令;从左到右依次表示:系统当前时间,系统运行时间,当前登入用户数.最后的load average 表示系统的平均负载，即任务队列的平均长度.这三个值分别表示1分钟,5分钟,15分钟到现在的平均值.
# 第二行是进程统计信息:分别有正在运行的进程数,睡眠进程数,停止的进程数,僵尸进程数.
#第三行是CPU统计信息:us表示用户CPU占用率,sy表示内核空间CPU占用率,ni表示用户进程空间改变过优先级的进程CPU的占用率,id表示空闲CPU占用率,wa表示等待输入输出的CPU时间百分比,hi表示硬件中断请求,si表示软件中断请求.在Mem行中，从左到右，依次表示物理内存总量,已使用的物理内存,空闲物理内存，内核缓存使用量.Swap行依次表示交换区总量,空闲交换区大小,缓冲交换区大小.
# 第二部分是进程信息，显示了系统各个进程的资源使用情况.
# 默认情况下仅显示比较重要的PID,USER,PR,NI,VIRT,RES,SHR,S,%CPU,%MEM,TIME+,COMMAND列。
# 在这张表中，可能出现的列及其含义如下:
# PID:进程id
# PPID:父进程id
# RUSER:Real user name
# UID:进程所有者的用户id
# USER:进程所有者的用户名
# GROUP:进程所有者的组名
# TTY:启动进程的终端名。不是从终端启动的进程则显示为 ?
# PR:优先级
# NI:nice值。负值表示高优先级，正值表示低优先级
# P:最后使用的CPU，仅在多CPU环境下有意义
# %CPU:上次更新到现在的CPU时间占用百分比
# TIME:进程使用的CPU时间总计，单位秒
# TIME+:进程使用的CPU时间总计，单位1/100秒
# %MEM:进程使用的物理内存百分比
# VIRT:进程使用的虚拟内存总量，单位kb。VIRT=SWAP+RES
# SWAP:进程使用的虚拟内存中，被换出的大小，单位kb。
# RES:进程使用的、未被换出的物理内存大小，单位kb。RES=CODE+DATA
# CODE:可执行代码占用的物理内存大小，单位kb
# DATA:可执行代码以外的部分(数据段+栈)占用的物理内存大小，单位kb
# SHR:共享内存大小，单位kb
# nFLT:页面错误次数
# nDRT:最后一次写入到现在，被修改过的页面数。
# S:进程状态D=不可中断的睡眠状态;R=运行;S=睡眠;T=跟踪/停止;Z=僵尸进程
# COMMAND:命令名/命令行
# WCHAN:若该进程在睡眠，则显示睡眠中的系统函数名
# Flags:任务标志，参考 sched.h

# 更改显示内容通过f键可以选择显示的内容:按f键之后会显示列的列表，按a-z即可显示或隐藏对应的列，最后按回车键确定。
#按o键可以改变列的显示顺序:按小写的a-z可以将相应的列向右移动，而大写的A-Z可以将相应的列向左移动。最后按回车键确定。按大写的F或O键，然后按a-z可以将进程按照相应的列进行排序。而大写的R键可以将当前的排序倒转。设置完按回车返回界面。

# use
# 命令格式：
# top [-][d][p][q][c][C][S] [n]
# 参数说明：
# d : 指定每两次屏幕信息刷新之间的时间间隔。当然用户可以使用s交互命令来改变之。
# p : 通过指定监控进程ID来仅仅监控某个进程的状态。
# q : 该选项将使top没有任何延迟的进行刷新。如果调用程序有超级用户权限，那么top将以尽可能高的优先级运行。
# S : 指定累计模式
# s : 使top命令在安全模式中运行。这将去除交互命令所带来的潜在危险。
# i : 使top不显示任何闲置或者僵死进程。
# c : 显示整个命令行而不只是显示命令名

# h|? : 显示帮助画面，给出一些简短的命令总结说明。
# k : 终止一个进程。系统将提示用户输入需要终止的进程PID，以及需要发送给该进程什么样的信号。 一般的终止进程可以使用15信号；如果不能正常结束那就使用信号9强制结束该进程。默认值是信号15。在安全模式中此命令被屏蔽
# i : 忽略闲置和僵死进程。这是一个开关式命令。
# q : 退出程序。
# r : 重新安排一个进程的优先级别。系统提示用户输入需要改变的进程PID以及需要设置的进程优先级值。 输入一个正值将使优先级降低，反之则可以使该进程拥有更高的优先权。默认值是10。
# S : 切换到累计模式。
# s : 改变两次刷新之间的延迟时间。系统将提示用户输入新的时间，单位为s。如果有小数，就换算成ms。 输入0值则系统将不断刷新，默认值是5s。需要注意的是如果设置太小的时间，很可能会引起不断刷新，从而根本来不及看清显示的情况，而且系统负载也会大大增加。
# f或者F :从当前显示中添加或者删除项目。
# o|O : 改变显示项目的顺序。
# l : 切换显示平均负载和启动时间信息。即显示影藏第一行
# m : 切换显示内存信息。即显示影藏内存行
# t : 切换显示进程和CPU状态信息。即显示影藏CPU行
# c : 切换显示命令名称和完整命令行。 显示完整的命令。 这个功能很有用。
# M : 根据驻留内存大小进行排序。
# P : 根据CPU使用百分比大小进行排序。
# T : 根据时间/累计时间进行排序。
# W : 将当前设置写入~/.toprc文件中。这是写top配置文件的推荐方法。
top