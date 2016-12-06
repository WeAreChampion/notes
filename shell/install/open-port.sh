# 开启端口
vim /etc/sysconfig/iptables

# 允许80端口通过防火墙
-A INPUT -m state --state NEW -m tcp -p tcp --dport 80 -j ACCEPT
# 允许3306端口通过防火墙
-A INPUT -m state --state NEW -m tcp -p tcp --dport 3306 -j ACCEPT

# open hadoop 9000 port
-A INPUT -m state --state NEW -m tcp -p tcp --dport 9000 -j ACCEPT

# open hadoop 9001 port
-A INPUT -m state --state NEW -m tcp -p tcp --dport 9001 -j ACCEPT

#最后重启防火墙使配置生效
/etc/init.d/iptables restart

# find the 8033 port info if open
lsof -i:8033

# start
service iptables start

# stop
service iptables stop

# see the tcp port open and listen info
netstat -ntpl