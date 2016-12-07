#include<iostream>
using namespace std;
typedef int InfoType;
#define MAXV 100
typedef struct
{
	int no;//the vertex's number
	InfoType info;//the vertex's others info
}VertexType;
typedef struct
{
	int edges[MAXV][MAXV];
	int n,e;//the vertex's vertex_number and arc
	VertexType vex[MAXV];//save the vertex's info
}MGraph;//ͼ���ڽӾ��� 
typedef struct	ANode//���Ľڵ����� 
{
	int adjex;//�����յ�λ��
	struct ANode * nextarc; //ָ����һ������ָ�� 
	InfoType info; //�������Ϣ 
}ArcNode;
typedef int Vertex;
typedef struct Vnode//�ڽӱ��ʾͷ�������� 
{
	Vertex data;//������Ϣ 
	ArcNode *firstarc;//ָ���һ���� 
}VNode;
typedef VNode AdjList[MAXV];//Adjust���ڽӱ����� 
typedef struct
{
	AdjList adjust;//�ڽӱ� 
	int n,e;//������n�ͱ���e 
}ALGraph;//ͼ���ڽӱ����� 