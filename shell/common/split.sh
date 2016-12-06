linux split 命令
　　功能说明：切割文件。
　　语　　法：split [--help][--version][-<行数>][-b <字节>][-C <字节>][-l <行数>][要切割的文件][输出文件名]
　　补充说明：split可将文件切成较小的文件，预设每1000行会切成一个小文件。
　　参　　数：
　　-<行数>或-l<行数> 　指定每多少行就要切成一个小文件。
　　-b<字节> 　指定每多少字就要切成一个小文件。支持单位:m,k
　　-C<字节> 　与-b参数类似，但切割时尽量维持每行的完整性。
　　--help 　显示帮助。
　　--version 　显示版本信息。
　　[输出文件名] 　设置切割后文件的前置文件名，split会自动在前置文件名后再加上编号。
　　使用例子：
　　split -b 100m filename

linux下文件分割可以通过split命令来实现，可以指定按行数分割和安大小分割两种模式。Linux下文件合并可以通过cat命令来实现，非常简单。

　　在Linux下用split进行文件分割：

　　模式一：指定分割后文件行数

　　对与txt文本文件，可以通过指定分割后文件的行数来进行文件分割。

　　命令：split -l 300 large_file.txt new_file_prefix

　　模式二：指定分割后文件大小

 split -b 10m server.log waynelog

对二进制文件我们同样也可以按文件大小来分隔。

 

在Linux下用cat进行文件合并：

　　命令：cat small_files* > large_file


命令：split，例子：
以行数拆分 -l参数：
split –l 50 原始文件 拆分后文件名前缀
说明：以50行对文件进行拆分，最后一个文件的行数没有50行以实际行数进行分配，比如有一个名为 wlan_date.txt的文件，公有120行，进行拆分：
split -l 50 wlan_date.txt wlan
拆分后会生成 wlanaa wlanab wlanac 三个文件，wlanaa wlanab两个文件分别50行，wlanac文件剩下20行
以大小拆分 -b参数：
split –b 50 原始文件 拆分后文件名前缀