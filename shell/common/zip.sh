# unzip
unzip filename.zip

# zip an dir to an zipFile
zip -r dirZipName.zip srcDir

# 同时处理多个文件和目录
zip -r filename.zip dir1 dir2 dir3[...]

# zip current dir to dst.zip
zip -r dst.zip ./*

# -o:不提示的情况下覆盖文件；
# -d:-d dstDir,unzip save into dstDir.
unzip -o -d dstDir src.zip

# 删除压缩文件中 file
zip -d src.zip file