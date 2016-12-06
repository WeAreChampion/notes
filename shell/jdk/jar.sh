# jar use
# -c　创建新jar文件包
# -t　列出 jar 文件包的内容列表
# -x　展开 jar 文件包的指定文件或者所有文件
# -u　更新已存在的 jar 文件包 (添加文件到 jar 文件包中)
# [vfm0M] 中的选项可以任选，也可以不选，它们是 jar 命令的选项参数
# -v　生成详细报告并打印到标准输出
# -f　指定 jar 文件名，通常这个参数是必须的
# -m　指定需要包含的 MANIFEST 清单文件
# -0　只存储，不压缩，这样产生的 jar 文件包会比不用该参数产生的体积大，但速度更快
# -M　不产生所有项的清单（MANIFEST〕文件，此参数会忽略 -m 参数

# 把当前目录下的所有文件打包成 demo.jar
jar -cvfM0 demo.jar ./

# 解压 demo.jar,解压到当前目录,注意,不会创建一个文件夹,而是将所有jar包的内容全部解压到当前文件夹.
jar -xvf demo.jar

# 生成 META-INF/MANIFEST.MF 文件信息
jar cvfm First.jar a.txt -C classes/ dstDir

# 该命令将源目录下全部内容生成一个名为dst.jar的文件
# 如果当前目录已经存在dst.jar，那么该文件将被覆盖
# -cvf : 显示详细的打包过程
jar -cf dst.jar -C srcDir dstDir

# 查看 jar 包内容
jar -tf dst.jar
