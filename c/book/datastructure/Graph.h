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
}MGraph;//图的邻接矩阵 
typedef struct	ANode//弧的节点类型 
{
	int adjex;//弧的终点位置
	struct ANode * nextarc; //指向下一条弧的指针 
	InfoType info; //弧相关信息 
}ArcNode;
typedef int Vertex;
typedef struct Vnode//邻接表表示头结点的类型 
{
	Vertex data;//顶点信息 
	ArcNode *firstarc;//指向第一条弧 
}VNode;
typedef VNode AdjList[MAXV];//Adjust是邻接表类型 
typedef struct
{
	AdjList adjust;//邻接表 
	int n,e;//顶点数n和边数e 
}ALGraph;//图的邻接表类型 