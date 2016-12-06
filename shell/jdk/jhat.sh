# jhat:可以用于分析Java应用程序的堆快照内存

# jhat 服务器显示了所有的非平台类信息通过链接，可以查看所有类信息(包括Java平台的类)
# 单机 instances 链接可以进一步查看 Strig 对象的实例
# 分析完成后使用url:http:127.0.0.1:7000 查看结果
jhat dstHeapFile

# jhat 还支持OQL语句对堆快照进行查询
# jhat的OQL语言与Visual VM的OQL非常接近
# 查询出当前Java程序中所有java.io.File对象的路径
select file.path.value.toString() from java.io.File file