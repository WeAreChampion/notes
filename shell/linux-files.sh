查看文件编码
在Linux中查看文件编码可以通过以下几种方式：
1.在Vim中可以直接查看文件编码
:set fileencoding
即可显示文件编码格式。
如果你只是想查看其它编码格式的文件或者想解决用Vim查看文件乱码的问题，那么你可以在
~/.vimrc 文件中添加以下内容：

set encoding=utf-8 fileencodings=ucs-bom,utf-8,cp936

这样，就可以让vim自动识别文件编码（可以自动识别UTF-8或者GBK编码的文件），其实就是依照 fileencodings提供的编码列表尝试，如果没有找到合适的编码，就用latin-1(ASCII)编码打开。
2. enca (如果你的系统中没有安装这个命令，可以用sudo yum install -y enca 安装 )查看文件编码
$ enca filename
filename: Universal transformation format 8 bits; UTF-8
CRLF line terminators
需要说明一点的是，enca对某些GBK编码的文件识别的不是很好，识别时会出现：
Unrecognized encoding

文件编码转换
1.在Vim中直接进行转换文件编码,比如将一个文件转换成utf-8格式
:set fileencoding=utf-8

2. enconv 转换文件编码，比如要将一个GBK编码的文件转换成UTF-8编码，操作如下
enconv -L zh_CN -x UTF-8 filename

3. iconv 转换，iconv的命令格式如下：
iconv -f encoding -t encoding inputfile
比如将一个UTF-8 编码的文件转换成GBK编码
iconv -f UTF-8 -t GBK file1 -o file2
 查看文件编码file命令
file ip.txt  ip.txt: UTF-8 Unicode text, with escape sequences
一、利用iconv命令进行编码转换文件内容编码转换  iconv命令用于转换指定文件的编码,默认输出到标准输出设备,亦可指定输出文件。  用法： iconv [选项...] [文件...]  有如下选项可用:  输入/输出格式规范：  -f, --from-code=名称 原始文本编码  -t, --to-code=名称 输出编码  信息：  -l, --list 列举所有已知的字符集    输出控制：  -c 从输出中忽略无效的字符  -o, --output=FILE 输出文件  -s, --silent 关闭警告  --verbose 打印进度信息  -?, --help 给出该系统求助列表  --usage 给出简要的用法信息  -V, --version 打印程序版本号    例子:  iconv -f utf-8 -t gb2312 aaa.txt >bbb.txt  这个命令读取aaa.txt文件，从utf-8编码转换为gb2312编码,其输出定向到bbb.txt文件。
二、文件名编码转换
因为现在用linux,原来在windows里的文件都是用GBK编码的。所以copy到linux下是乱码，文件内容可以用iconv来转换可是好多中文的文件名还是乱码，找到个可以转换文件名编码的命令，就是convmv。
convmv命令详细参数  例如
convmv -f GBK -t UTF-8 *.mp3
不过这个命令不会直正的转换，你可以看到转换前后的对比。如果要直正的转换要加上参数 --notest
convmv -f GBK -t UTF-8 --notest *.mp3
-f 参数是指出转换前的编码，-t 是转换后的编码。这个千万不要弄错了。不然可能还是乱码哦。还有一个参数很有用。就是 -r 这个表示递归转换当前目录下的所有子目录。
* 需要安装 convmv-1.10-1.el5.noarch.rpm  
三、  更好的傻瓜型命令行工具enca，它不但能智能的识别文件的编码，而且还支持成批转换。  　　1.安装  　　
$sudo apt-get install enca  　　
2.查看当前文件编码  　　
enca -L zh_CN ip.txt     Simplified Chinese National Standard; GB2312     Surrounded by/intermixed with non-text data  　　
3.转换  　　命令格式如下  　　
$enca -L 当前语言 -x 目标编码 文件名  　　
例如要把当前目录下的所有文件都转成utf-8  　　
enca -L zh_CN -x utf-8 *     
检查文件的编码　enca -L zh_CN file   　　
 将文件编码转换为"UTF-8"编码　 enca -L zh_CN -x UTF-8 file
如果不想覆盖原文件可以这样         enca -L zh_CN -x UTF-8 < file1 > file2 