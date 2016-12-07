#include<iostream>
using namespace std;
#define MAX_VERTEX_NUM 100
typedef int infoType;
typedef int VertexType;
#define MAX_VEX_NUM 5
#define INF 32767
bool visited[MAX_VEX_NUM];
int a[MAX_VEX_NUM][MAX_VEX_NUM]={//ͼ���ڽӾ���
	{0,2,0,8,0},
	{2,0,6,0,7},
	{0,6,0,5,4},
	{8,0,5,0,0},
	{0,7,4,0,0}};
typedef struct ArcNode
{
	int adjvex;					//�û�ָ��Ķ���λ��
	struct ArcNode *nextarc;	//ָ����һ������ָ��
	infoType info;				//���Ȩֵ
}ArcNode;
typedef struct VNode
{
	VertexType data;			//������Ϣ
	ArcNode *firstarc;			//ָ���һ�������ö��㻡��ָ��
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;			//ͼ���ڽӱ�
	int vexnum,arcnum;			//ͼ�ĵ�ǰ�������ͻ���
}AlGraph;
void Create(AlGraph *&G)
{
	G=new AlGraph();
	G->vexnum=MAX_VEX_NUM;
	int i,j;
	for(i=0;i<G->vexnum;i++)
		G->vertices[i].firstarc=NULL;
	ArcNode *p; 
	for(i=0;i<G->vexnum;i++)
	{
		for(j=G->vexnum-1;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				p=new ArcNode();//p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->info=a[i][j];
				G->vertices[i].data=i;
				p->nextarc=G->vertices[i].firstarc ;//ǰ�巨 
				G->vertices[i].firstarc=p ;
			}
		}
	}
}
void Destroy(AlGraph *&G)
{
	ArcNode *p,*q;
	for(int i=0;i<G->vexnum;i++)
	{
		while(G->vertices[i].firstarc!=NULL)
		{
			q=G->vertices[i].firstarc;
			G->vertices[i].firstarc=q->nextarc;
			delete q;
		}
	}
	delete G;
}
void Disp(AlGraph *G)
{
	ArcNode *p;
	for(int i=0;i<G->vexnum;i++)
	{
		p=G->vertices[i].firstarc;
		if(p!=NULL)	cout<<"����V"<<i<<":\t";
		while(p!=NULL)
		{
			cout<<p->adjvex<<"   ";
			p=p->nextarc;
		}
		cout<<endl;
	}
}
void DFS(AlGraph *G,int v)
{
	ArcNode *p;
	visited[v]=true;
	cout<<G->vertices[v].data<<" ";
	p=G->vertices[v].firstarc;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex);
		p=p->nextarc;
	}
}
void BFS(AlGraph *G,int v)
{
	ArcNode *p;
	int queue[MAX_VEX_NUM+1];
	int rear=0,front=0;
	cout<<v<<" ";
	rear++;
	queue[rear]=v;
	visited[v]=true;//is visited
	while(front<rear)
	{
		front++;
		int w=queue[front];
		p=G->vertices[w].firstarc;
		while(p!=NULL)
		{
			if(!visited[p->adjvex])
			{
				cout<<p->adjvex<<" ";
				visited[p->adjvex]=true;
				rear++;
				queue[rear]=p->adjvex;
			}
			p=p->nextarc;//p��ָ 
		}
	}
	cout<<endl;
}
void disp()
{
	int i,j;
	cout<<"�ڽӾ���"<<endl;
	for(i=0;i<MAX_VEX_NUM;i++)
	{
		for(j=0;j<MAX_VEX_NUM;j++)
		{
			if(a[i][j]==0)
			{
				a[i][j]=INF;
				cout<<"��\t";
			}
			else
				cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}	
}
void Prim(int v)
{
	int weight[MAX_VEX_NUM],min,vex[MAX_VEX_NUM],i,j,k;
	disp();//output the matrix 
	cout<<"Prim�㷨��"<<endl;
	for(i=0;i<MAX_VEX_NUM;i++)
	{
		weight[i]=a[v][i];
		vex[i]=v;
	}
	weight[v]=0;		//mark
	for(i=1;i<MAX_VEX_NUM;i++)//��n-1������ 
	{
		min=INF;
		for(j=0;j<MAX_VEX_NUM;j++)
			if(weight[j]!=0&&weight[j]<min)
			{
				min=weight[j];
				k=j;
			}
		printf("��(%d,%d)Ȩֵ��: %d\n",vex[k],k,min);
		weight[k]=0;	//mark
		for(j=0;j<MAX_VEX_NUM;j++)
		{
			if(a[k][j]!=0&&a[k][j]<weight[j])
			{
				weight[j]=a[k][j];
				vex[j]=k;
			}
		}	
	}
}
void Dfs(AlGraph *G,int i)
{
	visited[i]=true;
	cout<<G->vertices[i].data<<" ";//output the node's information
	ArcNode *p=G->vertices[i].firstarc;
	for(int j=p->adjvex;p!=NULL;p=p->nextarc)
		if(!visited[j])
			Dfs(G,j);
}
void DFSTraverse(AlGraph *G)
{
	for(int i=0;i<G->vexnum;i++)
	{
		if(!visited[i])
			Dfs(G,i);
	}
	cout<<endl;
}
int main()
{
	AlGraph *G;
	Create(G);
	cout<<"�ڽӱ�Ϊ:"<<endl;
	Disp(G);
	int i;
	for(i=0;i<MAX_VEX_NUM;i++)
		visited[i]=false;
	cout<<"�Ӷ���0��ʼ���������������������:"<<endl;
	DFS(G,0);
	cout<<endl;
	for(i=0;i<MAX_VEX_NUM;i++)
		visited[i]=false;
	cout<<"�Ӷ���0��ʼ���������������������:"<<endl;
	DFSTraverse(G);
	for(i=0;i<MAX_VEX_NUM;i++)
		visited[i]=false;
	cout<<"�Ӷ���0��ʼ�Ĺ������������������:"<<endl;
	BFS(G,0);
	Prim(0);
	Destroy(G);
	return 0;
}