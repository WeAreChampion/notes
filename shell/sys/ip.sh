1. 进入ip编辑页面
    vim /etc/sysconfig/network-scripts/ifcfg-eth0
 
2. ip配置信息
    DEVICE="eth0"
    BOOTPROTO="static"
    HWADDR="00:0C:29:3C:BF:E7"
    IPV6INIT="yes"
    NM_CONTROLLED="yes"
    ONBOOT="yes"
    TYPE="Ethernet"
    UUID="ce22eeca-ecde-4536-8cc2-ef0dc36d4a8c"
    IPADDR="192.168.1.44"
    NETMASK="255.255.255.0"
    GATEWAY="192.168.1.1"
 
3. 重启网络服务
service network restart
/etc/init.d/network restart

4. linux查看ip地址详情
    ifconfig[-a]

5. 进入 hosts
vim /etc/hosts

6. 修改Ip地址映射
# 形式
ip-address        ip-name
