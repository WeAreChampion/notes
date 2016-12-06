一、tar
# 解压缩 *.tar 文件
tar xvf FileName.tar

# 打包，(注：tar是打包，不是压缩！)
tar cvf FileName.tar DirName

二、gz
# 解压 *.gz 文件
gunzip FileName.gz

# 解压 *.gz 文件，方式二
gzip -d FileName.gz

# 压缩
gzip FileName

三、tar.gz and tgz
# 解压
tar zxvf FileName.tar.gz

# 压缩
tar zcvf FileName.tar.gz DirName

四、bz2
# 解压，方式1
bzip2 -d FileName.bz2

# 解压，方式2
bunzip2 FileName.bz2

# 压缩
bzip2 -z FileName

五、tar.bz2
# 解压
tar jxvf FileName.tar.bz2

# 压缩
tar jcvf FileName.tar.bz2 DirName

六、bz
# 解压，方式1
bzip2 -d FileName.bz

# 解压，方式2
bunzip2 FileName.bz

七、tar.bz
# 解压
tar jxvf FileName.tar.bz

八、Z
# 解压
uncompress FileName.Z

# 压缩
compress FileName

九、tar.Z
# 解压
tar Zxvf FileName.tar.Z

# 压缩
tar Zcvf FileName.tar.Z DirName

十、zip
# 解压
unzip FileName.zip

# 压缩
zip FileName.zip DirName

十一、rar
# 解压
rar x FileName.rar

# 压缩
rar a FileName.rar DirName

十二、lha
# 解压
lha -e FileName.lha

# 压缩
lha -a FileName.lha FileName
———————————————
十三、rpm
# 解包
rpm2cpio FileName.rpm | cpio -div

十四、deb
# 解包
ar p FileName.deb data.tar.gz | tar zxf -

十五、all
.tar .tgz .tar.gz .tar.Z .tar.bz .tar.bz2 .zip .cpio .rpm .deb .slp .arj .rar .ace .lha .lzh .lzx .lzs .arc .sda .sfx .lnx .zoo .cab .kar .cpt .pit .sit .sea
# 解压
sEx x FileName.*

# 压缩
sEx a FileName.* FileName