# option
file [ -bchikLnNprsvz ] [ -f namefile ] [ -F separator ] [ -m magicfiles ] file ...

# -b 列出文件辨识结果时，不显示文件名称。
# -c 详细显示指令执行过程，便于排错或分析程序执行的情形
# -f 列出文件中文件名的文件类型
# -F 使用指定分隔符号替换输出文件名后的默认的“：”分隔符。
# -i 输出mime类型的字符串
# -L 查看对应软链接对应文件的文件类型
# -z 尝试去解读压缩文件的内容
# --help 显示命令在线帮助
# --version 显示命令版本信息

# file type and encoding
file dstFile

file -b dstFile

# 输出mime类型的字符串
file -i dstFile

file -f dstFile