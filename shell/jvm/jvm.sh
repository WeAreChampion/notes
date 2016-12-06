# 根据端口查找相关进程
netstat -anpt | grep port

# 根据 pid 查看提交 job 的相关信息
ps -ef | grep pid

# 切换 yarn 账号
su - yarn

# 查看进程所有线程cpu，内存情况
top -Hp pid

# 查看堆栈及 gc 信息
jstat -gcutil pid miss [times]