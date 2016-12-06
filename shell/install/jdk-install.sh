# copy java dir to zt93 machine's /opt/java dir
scp -r jdk-1.8.0 zt93:/opt/java

vim /etc/profile

# set java home
export JAVA_HOME=/opt/java/jdk1.8.0_20
export PATH=$JAVA_HOME/bin:$PATH
export CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar

source /etc/profile