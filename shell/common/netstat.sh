# Netstat命令用于显示各种网络相关信息，如网络连接，路由表，接口状态(Interface Statistics),masquerade 连接，多播成员 (Multicast Memberships)等等。

# netstat 的输出结果可以分为两个部分：
# 一个是Active Internet connections，称为有源TCP连接，其中"Recv-Q"和"Send-Q"指%0A的是接收队列和发送队列。 这些数字一般都应该是0。如果不是则表示软件包正在队列中堆积。这种情况只能在非常少的情况见到。
# 另一个是Active UNIX domain sockets，称为有源Unix域套接口(和网络套接字一样，但是只能用于本机通信，性能可以提高一倍)。 
# 列: Proto[协议,tcp,unix],Recv-Q,Send-Q,Local Address,Foreign Address,State
# Proto 显示连接使用的协议, RefCnt 表示连接到本套接口上的进程号,Types 显示套接口的类型,State 显示套接口当前的状态, Path 表示连接到套接口的其它进程使用的路径名。
netstat

# -a (all)显示所有选项，默认不显示LISTEN相关
# -t (tcp)仅显示tcp相关选项
# -u (udp)仅显示udp相关选项
# -n 拒绝显示别名，能显示数字的全部转化成数字。
# -l 仅列出有在 Listen (监听) 的服務状态
# -p 显示建立相关链接的程序名
# -r 显示路由信息，路由表
# -e 显示扩展信息，例如uid等
# -s 按各个协议进行统计
# -c 每隔一个固定时间，执行该netstat命令。
# 提示：LISTEN和LISTENING的状态只有用-a或者-l才能看到

# 列出所有端口(包括监听和未监听的),列出所有tcp端口:-at,列出所有udp端口:-au
netstat -a

# 只显示监听端口,列出所有监听tcp端口:-lt,列出所有监听udp端口:-lu,列出所有监听UNIX端口:-lx
netstat -l

# 显示所有端口的统计信息,显示TCP或UDP端口的统计信息-st或-su
netstat -s

# 显示PID和进程名称, -pt
netstat -p

# 在 netstat 输出中不显示主机，端口和用户名 (host, port or user)
# 当你不想让主机，端口和用户名显示，使用 netstat -n。将会使用数字代替那些名称
netstat -an

# netstat 将每隔一秒输出网络信息
netstat -c

# 显示核心路由信息
# 使用 netstat -rn 显示数字格式，不查询主机名称
netstat -r

# 找出程序运行的端口,并不是所有的进程都能找到，没有权限的会不显示，使用root权限查看所有的信息
netstat -ap | grep ssh
# 找出运行在指定端口的进程
netstat -an | grep ':80'

# 显示网络接口列表,显示详细信息，像是ifconfig使用netstat -ie
netstat -i

# 查看连接某服务端口最多的的IP地址
netstat -nat | grep "192.168.1.15:22" |awk '{print $5}'|awk -F: '{print $1}'|sort|uniq -c|sort -nr|head -20

# TCP各种状态列表
netstat -nat |awk '{print $6}'

netstat -nat |awk '{print $6}'|sort|uniq -c|sort -rn

# 分析access.log获得访问前10位的ip地址
awk '{print $1}' access.log |sort|uniq -c|sort -nr|head -10