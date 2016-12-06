# xxd [options] [infile [outfile]]
# 查看二进制文件
xxd file

# 以二进制格式输出
xxd -b file

# 每行输出多少个字节(4)
xxd -c4 file

# 几个字节组成一组(4)
xxd -g4 file

# 将文件内容输出成 c的一个数组格式
xxd -i file

# 输出几个字节后结束(22)
xxd -l22 file

# 以一个整块输出所有的hex，不使用空格进行分割
xxd -p file

# -r: 反转操作，将16进制转成 2 进制

# -s [+][-]seek ： 从第几个字符开始
xxd -s5 file

# -u : 输出采用大写