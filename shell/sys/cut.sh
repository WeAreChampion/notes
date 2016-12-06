# cut -d'分隔字符' -f fields <==用于有特定分隔字符
# cut -c 字符区间            <==用于排列整齐的信息
# 选项与参数：
# -d  ：后面接分隔字符。与 -f 一起使用；
# -f  ：依据 -d 的分隔字符将一段信息分割成为数段，用 -f 取出第几段的意思；
# -c  ：以字符 (characters) 的单位取出固定字符区间

# 将 PATH 变量取出，找出第五个路径
echo $PATH | cut -d ':' -f 5

# 将 PATH 变量取出，找出第三和第五个路径
echo $PATH | cut -d ':' -f 3,5

# 将 PATH 变量取出，找出第三到最后一个路径
echo $PATH | cut -d ':' -f 3-

# 将 PATH 变量取出，找出第一到第三个路径
echo $PATH | cut -d ':' -f 1-3

# 将 PATH 变量取出，找出第一到第三，还有第五个路径
echo $PATH | cut -d ':' -f 1-3,5

# 只显示file的用户和shell
cat file | cut -d ':' -f 1,7