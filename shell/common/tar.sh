# tar 命令详解
# 以下是独立的命令，压缩解压都要用到其中一个，可以和别的命令连用但只能用其中一个。
# -c: 建立压缩档案，产生新的包
# -x: 解压缩
# -t: 列出压缩包中的文件
# -r: 向压缩归档文件末尾追加文件
# -u: 更新原压缩包中的文件
# -f: 指定包的文件名，这个参数是最后一个参数

# 将所有.jpg的文件打成 tar 包
tar -cf dst.tar *.jpg
tar –cvf jpg.tar *.jpg

# 将所有.jpg的文件打成 tar 包，并用 gzip 压缩
tar –czf jpg.tar.gz *.jpg

# 将所有.jpg的文件打成 tar 包，并用 bzip2 压缩
tar –cjf jpg.tar.bz2 *.jpg

# 将所有.jpg的文件打成 tar 包，并用 compress 压缩
tar –cZf jpg.tar.Z *.jpg

# 将所有 .gif 的文件增加到 tar 包里
tar -rf dst.tar *.gif

# 更新原来 tar dst.tar中的文件
tar -uf dst.tar logo.gif

# 列出all.tar包中所有文件
tar -tf dst.tar

# 解压缩 tar 包
tar -xf dst.tar

# rar格式的压缩
rar a jpg.rar *.jpg

# 解压 tar包
tar –xvf file.tar

# 解压 tar.gz
tar -xzvf file.tar.gz

# 解压 tar.bz2
tar -xjvf file.tar.bz2

# 解压 tar.Z
tar –xZvf file.tar.Z

# 解压 rar
unrar e file.rar

# zip 压缩
zip jpg.zip *.jpg

# zip 解压
unzip file.zip