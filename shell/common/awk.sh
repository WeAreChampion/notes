# awk就是把文件逐行的读入，以空格为默认分隔符将每行切片，切开的部分再进行各种分析处理

[linux awk cmd regular]
# pattern : 表示 AWK 在数据中查找的内容
# action  : 是在找到匹配内容时所执行的一系列命令
# 花括号({})不需要在程序中始终出现，但它们用于根据特定的模式对一系列指令进行分组
# pattern就是要表示的正则表达式，用斜杠括起来。
# awk '{pattern + action}' {filenames}

[调用awk的三种方式]
1. 命令行方式
awk [-F  field-separator]  'commands'  input-file(s)
其中，commands 是真正awk命令，[-F域分隔符]是可选的。 input-file(s) 是待处理的文件。
在awk中，文件的每一行中，由域分隔符分开的每一项称为一个域。通常，在不指名-F域分隔符的情况下，默认的域分隔符是空格。

2. shell 脚本方式
将所有的awk命令插入一个文件，并使 awk 程序可执行，然后awk命令解释器作为脚本的首行，一遍通过键入脚本名称来调用。
相当于shell脚本首行的：#!/bin/sh，可以换成：#!/bin/awk

3. 将所有的awk命令插入一个单独文件，然后调用：
awk -f awk-script-file input-file(s)
其中，-f选项加载awk-script-file中的awk脚本，input-file(s)跟上面的是一样的。

# 仅取出前五行
last -n 5

# 读入有'\n'换行符分割的一条记录，然后将记录按指定的域分隔符划分域、填充域，
# $0则表示所有域,$1表示第一个域,$n表示第n个域。
# 默认域分隔符是"空白键" 或 "[tab]键",所以 $1 表示登录用户，$3表示登录用户 ip
last -n 5 | awk  '{print $1}'