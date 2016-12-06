# gunzip help
# 1.作用，gunzip 作用是解压文件，使用权限是所有用户。
#2.格式，gunzip [-acfhlLnNqrtvV][-s ][file...] or gunzip [-acfhlLnNqrtvV][-s ][dir]
# 3.主要参数
# 	-a[--ascii]]: using ASCII text.
# 	-c[--stdout]: 把解压后的文件输出到标准输出设备。
# 	-f[--force]: 强行解开压缩文件，不理会文件名称或硬连接是否存在，以及该文件是否为符号连接。
# 	-h[--help]: help
# 	-l[--list]: list the files info.
# 	-L[--license]: license
# 	-n[--no-name]: 解压缩时，若压缩文件内含有原来的文件名称及时间戳记，则将其忽略不予处理。
# 	-N[--name]: 解压缩时，若压缩文件内含有原来的文件名称及时间戳记，则将其回存到解开的文件上。
# 	-q[--quiet]: 不显示警告信息。
# 	-r[--recursive]: 递归处理，将指定目录下的所有文件及子目录一并处理。
# 	-S[--suffix]: 更改压缩字尾字符串。
# 	-t[--test]: 测试压缩文件是否正确无误。
# 	-v[--verbose]: 显示指令执行过程。
# 	-V[--version]: version
# 4.说明,gunzip 解压扩展名.gz，gunzip 就是 gzip 的硬连接，支持压缩或解压缩
	
# 压缩保留源文件的方法]: 
gzip –c filename > filename.gz

# 解压缩保留源文件的方法
gunzip –c filename.gz > filename

# gunzip the dir using -r
gunzip -r dir
