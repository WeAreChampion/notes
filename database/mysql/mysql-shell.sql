--�鿴 mysql ���������:
show variables like '%max_connections%';

--�޸����������
--����һ: �޸������ļ���
--����MySQL��װĿ¼ ��MySQL�����ļ� my.ini �� my.cnf
--���� max_connections=100�޸�Ϊ max_connections=1000 ����������MySQL����
--������: �������޸ġ����Ƽ�������
--�����е�¼MySQL�������µ�MySQL���������Ϊ200
--һ�� mysql �������ֻ�ָ�����ʼ״̬
set global max_connections=200

-- show all connections
show processlist;
show full processlist

--insert the select column
INSERT INTO tableName_bak values(t.c1,t.c2,t.c3) SELECT t.c1,t.c2,t.c3 FROM tableName t;

--���ݱ�(������ṹ)
CREATE TABLE tableName_bak SELECT * FROM tableName;

--���ݵ���
INSERT INTO tableName_bak SELECT * FROM tableName;

-- copy table
create table tableName_bak like tableName;