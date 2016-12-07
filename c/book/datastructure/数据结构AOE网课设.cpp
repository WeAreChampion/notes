#include<iostream>
using namespace std;
typedef int InfoType;
#define MAX_VEX_NUM 50	//最大顶点数 
#define INF 32767
#define MAXSIZE 100
bool visited[MAX_VEX_NUM];
typedef struct
{
	int num;		//顶点编号 
	InfoType info;	//顶点权值 
}VertexType;
typedef struct
{
	int edges[MAX_VEX_NUM][MAX_VEX_NUM];//邻接矩阵 
	int n,e;// 图的顶点数和弧数 
	VertexType vex[MAX_VEX_NUM];//save the vex info
}MGraph;
typedef struct ArcNode
{
	int adjvex;					//该弧指向的顶点位置
	struct ArcNode *nextarc;	//指向下一条弧的指针
	InfoType info;				//存放权值
}ArcNode;
typedef struct VNode
{
	int data;					//顶点信息
	ArcNode *firstarc;			//指向第一条依附该顶点弧的指针
}VNode,AdjList[MAX_VEX_NUM];
typedef struct
{
	AdjList vertices;			//图的邻接表
	int vexnum,arcnum;			//图的当前顶点数和弧数
}AlGraph;
typedef struct
{
	int top;
	int data[MAXSIZE];
}Stack;					//定义栈存储结构 
void InitStack(Stack *&s)//Init the stack 
{
	s=new Stack();
	s->top=-1;
}
int StackEmpty(Stack *s)//判断栈释放为空 
{
	return s->top==-1;
}
void Push(Stack *&s,int e)//push 
{
	if(s->top<MAXSIZE)
	{
		s->data[++s->top]=e;
	}
}
void Pop(Stack *&s,int &e)//pop 
{
	e=s->data[s->top--];
}//构造邻接矩阵
void CreateMatrix(MGraph *&M) 
{
	M=(MGraph *)new MGraph();
	int vex_num;
	do
	{
		cout<<"请输入要构造矩阵的顶点数:  ";
		cin>>vex_num;
	}while(vex_num<=0||vex_num>MAX_VEX_NUM);
	M->n=vex_num;
	int i,j;
	for(i=0;i<vex_num;i++)//init
	{
		for(j=0;j<vex_num;j++)
		{
			M->edges[i][j]=0;
		}
		M->vex[i].num=i; 
		M->vex[i].info=0;
	}
	int arc_num;
	cout<<"请输入矩阵的弧数:  "; 
	cin>>arc_num;
	M->e=arc_num;
	while(arc_num--)
	{
		cout<<"请输入弧尾和弧头:  ";
		cin>>i>>j;
		while(i>=vex_num||j>=vex_num||i<0||j<0)
		{
			cout<<"请重新输入弧尾和弧头:  ";
			cin>>i>>j;
		}
		cout<<"请输入关于顶点的权值:  ";
		int e;
		cin>>e;
		while(e<0||e>=INF)
		{
			cout<<"请重新输入权值:  ";
			cin>>e;
		}
		M->edges[i][j]=e;
		M->vex[j].info=e;
	} 
} //释放邻接矩阵空间 
void DestroyMatrix(MGraph *&M)
{
	delete M;
}//输出邻接矩阵 
void DispMGraph(MGraph *M)
{
	cout<<"图的顶点数是:  ";
	cout<<M->n<<endl;
	cout<<"图的弧数是:  ";
	cout<<M->e<<endl;
	cout<<"图的邻接矩阵是:  \n";
	for(int i=0;i<M->n;i++)
	{
		for(int j=0;j<M->n;j++)
		{
			cout<<M->edges[i][j]<<" ";
		}
		cout<<endl;
	}
}//由邻接矩阵构造邻接表
void CreateAlGraph(AlGraph *&G,MGraph *M)
{
	G=new AlGraph();
	G->vexnum=M->n;
	G->arcnum=M->e;
	int i,j;
	for(i=0;i<G->vexnum;i++)//Init
		G->vertices[i].firstarc=NULL;
	ArcNode *p; 
	for(i=0;i<G->vexnum;i++)
	{
		for(j=G->vexnum-1;j>=0;j--)
		{
			if(M->edges[i][j]!=0)
			{
				p=new ArcNode();//p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->info=M->edges[i][j];
				G->vertices[i].data=i;
				p->nextarc=G->vertices[i].firstarc ;//前插法 
				G->vertices[i].firstarc=p ;
			}
			else
			{
				G->vertices[i].data=i;
			}
		}
	}
}//释放图存储空间 
void DestroyAlGraph(AlGraph *&G)
{
	ArcNode *q;
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
}//输出图的相关信息 
void DispAlGraph(AlGraph *G)
{
	cout<<"图的顶点数是:  ";
	cout<<G->vexnum<<endl;
	cout<<"图的弧数是:  ";
	cout<<G->arcnum<<endl;
	cout<<"图的邻接表是: \n";
	ArcNode *p;
	for(int i=0;i<G->vexnum;i++)
	{
		p=G->vertices[i].firstarc;
		cout<<"顶点V"<<i<<":\t";
		while(p!=NULL)
		{
			cout<<p->adjvex<<"   ";
			p=p->nextarc;//p下指 
		}
		cout<<endl;
	}
}//输出图顶点的权值 
void DispWeight(AlGraph *G)
{
	cout<<"图顶点的权值有：\n";
	ArcNode *p;
	for(int i=0;i<G->vexnum;i++)
	{
		p=G->vertices[i].firstarc;
		while(p!=NULL)
		{
			cout<<"顶点V"<<i<<"->顶点V"<<p->adjvex<<": weight= "<<p->info<<endl;
			p=p->nextarc;
		}
	}
}//对图进行深度优先搜索 
void DFS(AlGraph *G,int v)
{
	ArcNode *p;
	cout<<v<<" ";//or  //cout<<G->vertices[v].data<<" ";
	visited[v]=true;
	p=G->vertices[v].firstarc;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex);
		p=p->nextarc;
	}
}//对图进行BFS搜索 
void BFS(AlGraph *G,int v)
{
	ArcNode *p;
	int queue[MAX_VEX_NUM+1];//队列 
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
				rear++;		//新的节点入栈 
				queue[rear]=p->adjvex;
			}
			p=p->nextarc;//p下指 
		}
	}
	cout<<endl;
}//求顶点的入度，并存储在数组indegree中
int FindDegree(AlGraph *G,int *indegree)
{
	int i;
	ArcNode *p;
	for(i=0;i<G->vexnum;i++)
		indegree[i]=0;
	for(i=0;i<G->vexnum;i++)
	{
		p=G->vertices[i].firstarc;
		while(p!=NULL)
		{
			indegree[p->adjvex]++;
			p=p->nextarc;
		}
	}
	return G->vexnum;
}
void DispDegree(int *indegree,int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<"顶点V"<<i<<"入度是："<<indegree[i]<<endl;
	}
}//得到拓扑排序序列 
int TopologicalSort(AlGraph *G)
{
	int indegree[MAX_VEX_NUM]={0},i;
	FindDegree(G,indegree);
	Stack *s;
	InitStack(s);
	for(i=0;i<G->vexnum;i++)
		if(!indegree[i])
			Push(s,i);
	int count=0,k;
	ArcNode *p;
	cout<<"拓扑排序的序列是:  ";
	while(!StackEmpty(s))
	{
		Pop(s,i);
		cout<<"V"<<i<<"  ";
		count++;
		p=G->vertices[i].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			if(!(--indegree[k]))
				Push(s,k);
			p=p->nextarc;
		}
	}
	cout<<endl;
	if(count<G->vexnum)
		return 0;
	return 1;
} 
int TopologicalOrder(AlGraph *G,Stack *&t,int *ve)
{
	int indegree[MAX_VEX_NUM]={0},count=0,j,k,i;
	FindDegree(G,indegree);
	Stack *s;
	InitStack(s);
	for(i=0;i<G->vexnum;i++)
		if(!indegree[i])
			Push(s,i);
	ArcNode *p;
	while(!StackEmpty(s))
	{
		Pop(s,j);Push(t,j);
		count++;
		p=G->vertices[j].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			if(--indegree[k]==0)
				Push(s,k);
			if(ve[j]+p->info>ve[k])
				ve[k]=ve[j]+p->info;
			p=p->nextarc;
		}
	}
	if(count<G->vexnum)
		return 0;
	return 1;
}
int CriticalPath(AlGraph *G)//输出G的各项关键活动 
{
	Stack *t;
	int ve[MAX_VEX_NUM]={0};
	InitStack(t);
	if(!TopologicalOrder(G,t,ve))
		return 0;
	int vl[MAX_VEX_NUM],i,k,dut,ee,el;
	cout<<"各个顶点的最早发生时间是:  ";
	for(i=0;i<G->vexnum;i++)
	{
		cout<<ve[i]<<" ";
	}
	cout<<endl;
	cout<<"该工程至少需要的时间为："<<ve[G->vexnum-1]<<endl;
	for(i=0;i<G->vexnum;i++)
		vl[i]=ve[G->vexnum-1];
	ArcNode *p;
	while(!StackEmpty(t))
	{
		Pop(t,i);
		p=G->vertices[i].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			dut=p->info;
			if(vl[k]-dut<vl[i])
				vl[i]=vl[k]-dut;
			p=p->nextarc;
		}
	}
	cout<<"各个顶点的最迟发生时间是:  ";
	for(i=0;i<G->vexnum;i++)
	{
		cout<<vl[i]<<" ";
	}
	cout<<endl;
	cout<<"关键路径是：";
	cout<<"V0";
	for(i=0;i<G->vexnum;i++)
	{
		p=G->vertices[i].firstarc;
		while(p!=NULL)
		{
			k=p->adjvex;
			dut=p->info;
			ee=ve[i];
			el=vl[k]-dut;
			if(ee==el)
				cout<<"->V"<<k;
			p=p->nextarc;
		}
	}
	cout<<endl;
	return 1;
}
void menu()
{
	cout<<"\t\t#===========功能介绍============#\n";
	cout<<"\t\t#      输入0： 输 入 结 束      #\n";
	cout<<"\t\t#      输入1： 构建邻接矩阵     #\n";
	cout<<"\t\t#      输入2： 构建邻接表       #\n";
	cout<<"\t\t#      输入3： 对邻接表DFS      #\n";
	cout<<"\t\t#      输入4： 对邻接表BFS      #\n";
	cout<<"\t\t#      输入5： 求顶点的入度     #\n";
	cout<<"\t\t#      输入6： 求拓排序列       #\n";
	cout<<"\t\t#      输入7： 求关键路径       #\n";
	cout<<"\t\t#      输入8： 释放存储空间     #\n";
	cout<<"\t\t#===============================#\n";
}
int main()
{
	int n;
	menu();
	MGraph *M;
	AlGraph *G=NULL;
	int indegree[MAX_VEX_NUM],i;
	cout<<"请输入操作数:  ";
	while(cin>>n) 
	{
		switch(n)
		{
			case 0:	DestroyMatrix(M);
					DestroyAlGraph(G);
					exit(0);cout<<"输入结束\n";		//输入结束
			case 1:	
					CreateMatrix(M);				//构建邻接矩阵
					DispMGraph(M);
					break;
			case 2:									//构建邻接表
					if(G==NULL)
						CreateAlGraph(G,M);
					DispAlGraph(G);
					break;
			case 3:									//对图的邻接表DFS
					if(G==NULL)
						cout<<"邻接表未创建!\n";
					else
					{
						for(i=0;i<G->vexnum;i++)	//init visited数组 
							visited[i]=false;
						cout<<"深度优先搜索的序列是:\n";
						DFS(G,0);
						cout<<endl;
					}	
					break;
			case 4:									//对图的邻接表BFS
					if(G==NULL)
						cout<<"邻接表未创建!\n";
					else
					{
						for(i=0;i<G->vexnum;i++)	//init visited数组
							visited[i]=false;
						cout<<"广度优先搜索的序列是:\n";
						BFS(G,0);
					}
					break;
			case 5:									//求图各个顶点的入度
					if(G!=NULL)
					{
						FindDegree(G,indegree);
						DispDegree(indegree,G->vexnum);
					}
					else
						cout<<"邻接表未创建!\n";
					break;
			case 6:									//求拓扑排序并判断AOE网能否顺利进行
					if(G==NULL)
						cout<<"邻接表未创建!\n";
					else
					{
						if(TopologicalSort(G))
							cout<<"\tAOE网能够顺利进行\n"; 
						else
							cout<<"\tAOE网不能顺利进行\n";
					}
					break;
			case 7:									//求AOE网的关键活动，最早/迟发生时间
					if(G==NULL)
						cout<<"邻接表未创建!\n";
					else
					{
						CriticalPath(G);
					}
					break;
			case 8:	DestroyMatrix(M);			//释放存储空间 
					DestroyAlGraph(G);
					cout<<"邻接表和邻接矩阵已销毁！\n";
					break;
			default:cout<<"输入错误！请重新输入！\n";
		} 
		system("pause");		// 冻结屏幕 
		system("cls"); 			//清屏 
		menu();
		cout<<"请输入操作数:  ";
	}
	return 0;
} 
/*
1
5
5
0 1
3
0 2
2
2 3
7
1 3
4
3 4
6
*/