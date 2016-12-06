# [截取字符串]
# http://www.111cn.net/sys/linux/43822.htm

# substr(aa, 0, 2)即 AB
# startIndex:0
# length=2
aa=ABCDEFG; echo ${aa:0:2}

# way2
# startIndex:0
# length=2
aa=ABCDEFG; echo substr($aa,0,2)