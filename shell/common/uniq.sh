# uniq [-icu]
# 选项与参数：
# -i   ：忽略大小写字符的不同；
# -c  ：进行计数
# -u  ：只显示唯一的行

# 去重相邻行
uniq file

# 先排序再去重行
cat file | sort | uniq

# 排序之后删除了重复行，同时在行首位置输出该行重复的次数
sort testfile | uniq -c

# 仅显示存在重复的行，并在行首显示该行重复的次数
sort testfile | uniq -dc

# 仅显示不重复的行
sort testfile | uniq -u

