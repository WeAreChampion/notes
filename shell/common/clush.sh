# clush : 针对免密码登入后的所有主机(/etc/hosts中配置)
# clush -a 全部  等于  clush -g all
# clush -g 指定组
# clush -w 操作主机名字
# clush -g  copy  --dest   文件分发
# 查看 -a 的帮助信息
clush -a --h

# 文件分发
clush -g --copy src --dest dst

# 查看所有主机负载
clush -a uptime

# 复制文件到所有主机的当前目录
# copy local file or directory to remote nodes
clush -a -c file

# copy file or directory from remote nodes
clush -a -rcopy file