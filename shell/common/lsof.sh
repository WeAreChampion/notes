# lsof(list open files)是一个列出当前系统打开文件的工具。在linux环境下，任何事物都以文件的形式存在，通过文件不仅仅可以 访问常规数据，还可以访问网络连接和硬件。所以如传输控制协议(TCP)和用户数据报协议(UDP) 套接字等，系统在后台都为该应用程序 分配了一个文件描述符，无论这个文件的本质如何，该文件描述符为应用程序与基础操作系统之间的交互提供了通用接口。因为应用程序打开文件的描述符列表提供了大量关于这个应用程序本身的信息，因此通过lsof工具能够查看这个列表对系统监测以及排错将是很有帮助的。
# 在终端下输入lsof即可显示系统打开的文件，因为 lsof 需要访问核心内存和各种文件，所以必须以root身份运行

# lsof 输出各列信息的意义如下：
# COMMAND: 进程的名称
# PID: 进程标识符
# USER: 进程所有者
# FD: 文件描述符，应用程序通过文件描述符识别该文件。如cwd、txt等 TYPE：文件类型，如DIR、REG等
# DEVICE: 指定磁盘的名称
# SIZE: 文件的大小
# NODE: 索引节点（文件在磁盘上的标识）
# NAME: 打开文件的确切名称

# lsof 内容输出到 less
lsof | less

# 显示开启文件abc.txt的进程
lsof abc.txt
lsof | grep abc.txt

# 显示abc进程现在打开的文件
lsof -c abc

# 列出进程号为 pid 的进程所打开的文件
lsof -p pid

# 显示归属gid的进程情况
lsof -g gid

# 显示目录下被进程开启的文件
lsof +d dir

# 显示目录及子目录下被进程开启的文件
lsof +D dir

# 显示使用fd为4的进程
lsof -d 4

# 用以显示符合条件的进程情况
lsof -i
# [4|6]--> IPv4 or IPv6
# protocol --> TCP or UDP
# hostname --> Internet host name
# hostaddr --> IPv4地址
# service --> /etc/service中的 service name (可以不止一个)
# port --> 端口号(可以不止一个)
lsof -i [4|6][protocol][@hostname|hostaddr][:service|port]

# IPv6 and TCP,hostname:localhost,service:ipp
lsof -i 6TCP@localhost:ipp

# IPv6 and TCP,port:37857
lsof -i 6TCP:37857

############ demos
# 那个进程在使用apache的可执行文件
lsof `which httpd`
# 那个进程在占用/etc/passwd
lsof /etc/passwd
# 那个进程在占用hda6
lsof /dev/hda6
# 那个进程在占用光驱
lsof /dev/cdrom
# 查看sendmail进程的文件使用情况
lsof -c sendmail
# 显示出那些文件被以courier打头的进程打开，但是并不属于用户zahn
lsof -c courier -u ^zahn
# 显示那些文件被pid为30297的进程打开
lsof -p 30297
# 显示所有在/tmp文件夹中打开的instance和文件的进程。但是symbol文件并不在列
lsof -D /tmp 
# 查看uid是100的用户的进程的文件使用情况
lsof -u1000
# 查看用户tony的进程的文件使用情况
lsof -utony
# 查看不是用户tony的进程的文件使用情况(^是取反的意思)
lsof -u^tony
# 显示所有打开的端口
lsof -i
# 显示所有打开80端口的进程
lsof -i:80
# 显示所有打开的端口和UNIX domain文件
lsof -i -U
# 显示那些进程打开了到www.akadia.com的UDP的123(ntp)端口的链接
lsof -i UDP@[url]www.akadia.com:123
# 不断查看目前ftp连接的情况(-r，lsof会永远不断的执行，直到收到中断信号,+r，lsof 会一直执行，直到没有档案被显示,缺省是 15s刷新)
lsof -i tcp@ohaha.ks.edu.tw:ftp -r
# lsof -n 不将IP转换为hostname，缺省是不加上-n参数
lsof -i tcp@ohaha.ks.edu.tw:ftp -n