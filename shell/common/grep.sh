# grep
# 	* : 表示当前目录所有文件，也可以是某个文件名
# 	-r 是递归查找
# 	-n 是显示行号
# 	-R 查找所有文件包含子目录
# 	-i 忽略大小写

# find the keyword
grep -rn keyword *

# 不区分大小写地搜索。默认情况区分大小写
grep -i pattern files

# 只列出匹配的文件名
grep -l pattern files
grep -l keyword *.log

# 列出不匹配的文件名
grep -L pattern files
grep -L keyword *.log

# 只匹配整个单词，而不是字符串的一部分(word)
grep -w pattern files

# 匹配的上下文分别显示[number]行
grep -C number pattern files

# 显示匹配 pattern1 或 pattern2 的行
grep pattern1 | pattern2 files

# 显示既匹配 pattern1 又匹配 pattern2 的行
grep pattern1 files | grep pattern2

# count the keyword
grep -o file | wc -l