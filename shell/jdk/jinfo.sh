# jinfo:查看正在运行的Java应用程序的扩展参数，甚至支持在运行时修改部分参数
# 通过 jinfo命令可以很方便地找到JVM参数的当前值
# 语法:jinfo <option> <pid>
# option可以是:
# -flag<name>:打印指定JVM的参数值
# -flag[+|-]<name>:设置指定JVM参数的布尔值
# -flag<name>=<value>:设置指定JVM参数的值

# 输出 -XX:MaxTenuringThreshold 的值
# 显示新生对象晋升老年代对象的最大年龄
jinfo -flag MaxTenuringThreshold 2972

# 显示是否打印GC详细信息，有则输出 -XX:+PrintGCDetails;否则输出:-XX:-PrintGCDetails
jinfo -flag PrintGCDetails 2972

# 除了查找参数，还支持修改部分参数立即生效，修改能力及其有限
# 打开打印GC详细信息的开关
jinfo -flag +PrintGCDetails 2972