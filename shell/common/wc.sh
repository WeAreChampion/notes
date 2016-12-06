# wc [option] command
# -l, --lines : 打印行数
# -L, --max-line-length : 打印最长行的长度
# -w, --words : 打印单词数
# -m, --chars : 打印字符数
# -c, --bytes : 打印字节数

# 文件信息，包括行数，单词数，字节数
wc dstFile
cat dstFile | wc

# 文件行数与文件名
wc -l dstFile

# 文件行数
cat dstFile | wc -l

# 单词数与文件名
wc -w dstFile

# 单词数
cat dstFile | wc -w

# 字节数及文件名
wc -c dstFile

# 字节数
cat dstFile | wc -c

# 打印字符数与文件名
wc -m dstFile

# 字符数
cat dstFile | wc -m

# 用来统计当前目录下的文件数
# 数量中包含当前目录
ls -l | wc -l

# line counts
wc -l

# word counts
wc -w

# char counts
wc -m

# bytes
wc -c

# 打印最长行的长度
wc -L

# 计某文件夹下文件的个数
ls -l |grep "^-"| wc -l

# 统计某文件夹下目录的个数
ls -l |grep "^ｄ"| wc -l

# 统计文件夹下文件的个数，包括子文件夹里的
ls -lR|grep "^-"| wc -l

# 如统计目录(包含子目录)下的所有js文件
ls -lR dir | grep .js | wc -l
ls -l "dir" | grep ".js" | wc -l

# 统计文件夹下目录的个数，包括子文件夹里的
ls -lR|grep "^d"|wc -l

# 长列表输出该目录下文件信息(R代表子目录注意这里的文件，不同于一般的文件，可能是目录、链接、设备文件等)
ls -lR

# 这里将长列表输出信息过滤一部分，只保留一般文件，如果只保留目录就是 ^d
grep "^-"

# 统计输出信息的行数
wc -l

# 如果只查看文件夹, 只能显示一个
ls -d

# 可以看到子文件夹
find -type d

# 只看当前目录下的文件夹，不包括往下的文件夹
ls -lF |grep /

ls -l |grep '^d'