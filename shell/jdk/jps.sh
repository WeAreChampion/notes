# jps:����linux�µ�ps����jpsֻ�г�java����

# �鿴����ID������(Main��������)
jps

# -q:ֻ�г�java����ID
jps -q

# -m:����������ݸ�Java����(������)�Ĳ���
jps -m

# -l:���������������·��
jps -m -l

# -v:�鿴����������������ʾ���ݸ�JVM�Ĳ���
jps -v

# ���ݹؼ��ֲ鿴������������
jps -v | grep keyword

# ʹ�� yarn �û��鿴������������
su yarn -c "jps -v"