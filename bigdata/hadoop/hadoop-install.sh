1.修改hadoop-2.6.0/etc/hadoop/hadoop-env.sh，添加JDK支持：
	如果不知道你的JDK目录，使用命令echo $JAVA_HOME 查看。
	export JAVA_HOME=/opt/java/jdk1.8.0_20

2.修改 hadoop-2.6.0/etc/hadoop/core-site.xml
	注意：必须加在<configuration></configuration>节点内
	<configuration>
		<property>
			<!-- -->
			<name>hadoop.tmp.dir</name>
			<value>/home/hadoop/hadoop-2.6.0/tmp</value>
		</property>
		<property>
			<!--  -->
			<name>fs.default.name</name>
			<value>hdfs://master:9000</value>
		</property>
	</configuration>

3.修改hadoop-2.6.0/etc/hadoop/hdfs-site.xml
	<property>
		<!-- 名称目录 -->
		<name>dfs.name.dir</name>
		<value>/home/hadoop/hadoop-2.6.0/dfs/name</value>
	</property>
	 
	<property>
		<!-- 数据目录 -->
		<name>dfs.data.dir</name>
		<value>/home/hadoop/hadoop-2.6.0/dfs/data</value>
	</property>
	<property>
		<!-- 副本数 -->
		<name>dfs.replication</name>
		<value>1</value>
	</property>

4.修改hadoop-2.6.0/etc/hadoop/mapred-site.xml
	<property>
		<!-- job tracker -->
		<name>mapred.job.tracker</name>
		<value>master:9001</value>
	</property>

5. 修改hadoop-2.6.0/etc/hadoop/masters
	列出所有的master节点：
	master

6.修改hadoop-2.6.0/etc/hadoop/slaves
	这个是所有datanode的机器，例如：
	slave1
	slave2

7.将master结点上配置好的hadoop文件夹拷贝到所有的slave结点上
	以slave1为例：命令如下：
	scp -r  ~/hadoop-2.6.0 hadoop@slave1:~/
	安装完成后，我们要格式化HDFS然后启动集群所有节点。

8.启动Hadoop
1.格式化HDFS文件系统的namenode
	# 进入hadoop-2.6.0目录来格式化好些
	cd hadoop-2.6.0
	# 格式化
	bin/hdfs namenode -format
	
2.启动Hadoop集群
	启动hdfs命令如下：
	sbin/start-dfs.sh
	
	补充，关闭hdfs集群的命令如下：
	sbin/stop-dfs.sh
	
	启动守护系统HDFS和MapReduce
	start-dfs.sh
	start-mapred.sh
	
	必须关闭防火墙
	service iptables stop
	
	# MapReduce的页面
	http://localhost:8088
	
	# HDFS的页面
	http://localhost:50070

8. hadoop home
	vim /etc/profile
	
	# add hadoop home into profile
	export HADOOP_HOME=/opt/java/hadoop-2.6.0
	export PATH=$HADOOP_HOME/sbin:$HADOOP_HOME/bin:$PATH
	
	# use the profile
	source /etc/profile