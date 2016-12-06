# -d32 使用 32 位数据模型 (如果可用)
# -d64 使用 64 位数据模型 (如果可用)
# -client 选择 "client" VM默认 VM 是 client.
# -server 选择 "server" VM
# -cp 目录和zip/jar文件的类搜索路径
# -classpath 目录和zip/jar文件的类搜索路径;用';'分隔的jar文件和ZIP档案列表,用于搜索类文件
# -D<名称>=<值> 设置系统属性
# -verbose:[class|gc|jni] 启用详细输出
# -ea[:<packagename>...|:<classname>]
# -enableassertions[:<packagename>...|:<classname>] 按指定的粒度启用断言
# -da[:<packagename>...|:<classname>]
# -disableassertions[:<packagename>...|:<classname>] 禁用具有指定粒度的断言
# -agentlib:<libname>[=<选项>] 加载本机代理库 <libname>,例如-agentlib:hprof;另请参阅-agentlib:jdwp=help 和 -agentlib:hprof=help
# -agentpath:<pathname>[=<选项>] 按完整路径名加载本机代理库
# -javaagent:<jarpath>[=<选项>] 加载Java编程语言代理,请参阅 java.lang.instrument
# -esa|-enablesystemassertions 启用系统断言
# -dsa|-disablesystemassertions 禁用系统断言
# -splash:<imagepath> 使用指定的图像显示启动屏幕

# 查看帮助
java -help
# 输出环境变量 JAVA_HOME值
echo $JAVA_HOME

# 查看java版本信息
java -version

# 启动runnable jar
java -jar demo.jar

# @param HEAP_OPTS : Java Options
# @param CLASSPATH : conf dir and jars
# @param CLASS : main class full name
# @param STREAM_HOME : params for main
# @param STREAM_TYPE : params for main
# @param YARN_JAR : params for main
# @param ST_LIBS : params for main
java -Djava.awt.headless=true $HEAP_OPTS -classpath "$CLASSPATH" $CLASS $STREAM_HOME $STREAM_TYPE $YARN_JAR $ST_LIBS

# 输出java加载类信息
java -verbose:class -version