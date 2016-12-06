# 之前的工具只涉及本地Java应用程序的监控，在这些工具中有些监控工具也支持对远程计算机的监控(jps,jstat)；
# 为了启用远程监控，需要配合使用jstatd工具。
# jstatd:RMI服务端程序，作用相当于代理服务器，建立本地计算机与远程监控工具的通信。
# jstatd 服务器将本机的Java应用程序信息传递到远程计算机。

# 直接打开jstatd服务器可能会抛出访问拒绝异常
# 因为 jstatd 程序没有足够的权限所致；可以使用Java的安全策略，为其分配相应的权限；
# 以下代码为 jstatd 分配了最大权限，将其保存在 jstatd.all.policy 文件中
# grant codebase "file:E:/tools/jdk1.6.2/lib/tools.jar" {
# 	permission java.security.AllPermission;
# };
# 然后使用以下命令再次开启 jstatd 服务器
# 指向保存的 policy 文件
#-J:是一个公共参数，如jsp,jstat等命令都可以接受这个参数。由于jsp,jstat命令本身也是Java应用程序，-J参数可以为jps等命令本身设置其JVM参数
# 默认情况下,jstatd将在1099端口开启RMI服务
jstatd -J-Djava.security.policy=C:jstatd.all.policy

# windows 查看端口
netstat -an | findstr 1099

# 使用jsp显示远程计算机的Java进程
# localhost:host
jps localhost:1099

# 使用 jstat 命令显示远程进程460的GC情况
# localhost:host
jstat -gcutil 460@localhost:1099