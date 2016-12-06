# jps:类似linux下的ps，但jps只列出java进程

# 查看进程ID及进程(Main函数名称)
jps

# -q:只列出java进程ID
jps -q

# -m:用于输出传递给Java进程(主函数)的参数
jps -m

# -l:输出主函数的完整路径
jps -m -l

# -v:查看进程启动参数，显示传递给JVM的参数
jps -v

# 根据关键字查看进程启动参数
jps -v | grep keyword

# 使用 yarn 用户查看进程启动参数
su yarn -c "jps -v"