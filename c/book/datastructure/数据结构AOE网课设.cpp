#include<iostream>
using namespace std;
typedef int InfoType;
#define MAX_VEX_NUM 50	//��󶥵��� 
#define INF 32767
#define MAXSIZE 100
bool visited[MAX_VEX_NUM];
typedef struct
{
	int num;		//������ 
	InfoType info;	//����Ȩֵ 
}VertexType;
typedef struct
{
	int edges[MAX_VEX_NUM][MAX_VEX_NUM];//�ڽӾ��� 
	int n,e;// ͼ�Ķ������ͻ��� 
	VertexType vex[MAX_VEX_NUM];//save the vex info
}MGraph;
typedef struct ArcNode
{
	int adjvex;					//�û�ָ��Ķ���λ��
	struct ArcNode *nextarc;	//ָ����һ������ָ��
	InfoType info;				//���Ȩֵ
}ArcNode;
typedef struct VNode
{
	int data;					//������Ϣ
	ArcNode *firstarc;			//ָ���һ�������ö��㻡��ָ��
}VNode,AdjList[MAX_VEX_NUM];
typedef struct
{
	AdjList vertices;			//ͼ���ڽӱ�
	int vexnum,arcnum;			//ͼ�ĵ�ǰ�������ͻ���
}AlGraph;
typedef struct
{
	int top;
	int data[MAXSIZE];
}Stack;					//����ջ�洢�ṹ 
void InitStack(Stack *&s)//Init the stack 
{
	s=new Stack();
	s->top=-1;
}
int StackEmpty(Stack *s)//�ж�ջ�ͷ�Ϊ�� 
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
}//�����ڽӾ���
void CreateMatrix(MGraph *&M) 
{
	M=(MGraph *)new MGraph();
	int vex_num;
	do
	{
		cout<<"������Ҫ�������Ķ�����:  ";
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
	cout<<"���������Ļ���:  "; 
	cin>>arc_num;
	M->e=arc_num;
	while(arc_num--)
	{
		cout<<"�����뻡β�ͻ�ͷ:  ";
		cin>>i>>j;
		while(i>=vex_num||j>=vex_num||i<0||j<0)
		{
			cout<<"���������뻡β�ͻ�ͷ:  ";
			cin>>i>>j;
		}
		cout<<"��������ڶ����Ȩֵ:  ";
		int e;
		cin>>e;
		while(e<0||e>=INF)
		{
			cout<<"����������Ȩֵ:  ";
			cin>>e;
		}
		M->edges[i][j]=e;
		M->vex[j].info=e;
	} 
} //�ͷ��ڽӾ���ռ� 
void DestroyMatrix(MGraph *&M)
{
	delete M;
}//����ڽӾ��� 
void DispMGraph(MGraph *M)
{
	cout<<"ͼ�Ķ�������:  ";
	cout<<M->n<<endl;
	cout<<"ͼ�Ļ�����:  ";
	cout<<M->e<<endl;
	cout<<"ͼ���ڽӾ�����:  \n";
	for(int i=0;i<M->n;i++)
	{
		for(int j=0;j<M->n;j++)
		{
			cout<<M->edges[i][j]<<" ";
		}
		cout<<endl;
	}
}//���ڽӾ������ڽӱ�
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
				p->nextarc=G->vertices[i].firstarc ;//ǰ�巨 
				G->vertices[i].firstarc=p ;
			}
			else
			{
				G->vertices[i].data=i;
			}
		}
	}
}//�ͷ�ͼ�洢�ռ� 
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
}//���ͼ�������Ϣ 
void DispAlGraph(AlGraph *G)
{
	cout<<"ͼ�Ķ�������:  ";
	cout<<G->vexnum<<endl;
	cout<<"ͼ�Ļ�����:  ";
	cout<<G->arcnum<<endl;
	cout<<"ͼ���ڽӱ���: \n";
	ArcNode *p;
	for(int i=0;i<G->vexnum;i++)
	{
		p=G->vertices[i].firstarc;
		cout<<"����V"<<i<<":\t";
		while(p!=NULL)
		{
			cout<<p->adjvex<<"   ";
			p=p->nextarc;//p��ָ 
		}
		cout<<endl;
	}
}//���ͼ�����Ȩֵ 
void DispWeight(AlGraph *G)
{
	cout<<"ͼ�����Ȩֵ�У�\n";
	ArcNode *p;
	for(int i=0;i<G->vexnum;i++)
	{
		p=G->vertices[i].firstarc;
		while(p!=NULL)
		{
			cout<<"����V"<<i<<"->����V"<<p->adjvex<<": weight= "<<p->info<<endl;
			p=p->nextarc;
		}
	}
}//��ͼ��������������� 
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
}//��ͼ����BFS���� 
void BFS(AlGraph *G,int v)
{
	ArcNode *p;
	int queue[MAX_VEX_NUM+1];//���� 
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
				rear++;		//�µĽڵ���ջ 
				queue[rear]=p->adjvex;
			}
			p=p->nextarc;//p��ָ 
		}
	}
	cout<<endl;
}//�󶥵����ȣ����洢������indegree��
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
		cout<<"����V"<<i<<"����ǣ�"<<indegree[i]<<endl;
	}
}//�õ������������� 
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
	cout<<"���������������:  ";
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
int CriticalPath(AlGraph *G)//���G�ĸ���ؼ�� 
{
	Stack *t;
	int ve[MAX_VEX_NUM]={0};
	InitStack(t);
	if(!TopologicalOrder(G,t,ve))
		return 0;
	int vl[MAX_VEX_NUM],i,k,dut,ee,el;
	cout<<"������������緢��ʱ����:  ";
	for(i=0;i<G->vexnum;i++)
	{
		cout<<ve[i]<<" ";
	}
	cout<<endl;
	cout<<"�ù���������Ҫ��ʱ��Ϊ��"<<ve[G->vexnum-1]<<endl;
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
	cout<<"�����������ٷ���ʱ����:  ";
	for(i=0;i<G->vexnum;i++)
	{
		cout<<vl[i]<<" ";
	}
	cout<<endl;
	cout<<"�ؼ�·���ǣ�";
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
	cout<<"\t\t#===========���ܽ���============#\n";
	cout<<"\t\t#      ����0�� �� �� �� ��      #\n";
	cout<<"\t\t#      ����1�� �����ڽӾ���     #\n";
	cout<<"\t\t#      ����2�� �����ڽӱ�       #\n";
	cout<<"\t\t#      ����3�� ���ڽӱ�DFS      #\n";
	cout<<"\t\t#      ����4�� ���ڽӱ�BFS      #\n";
	cout<<"\t\t#      ����5�� �󶥵�����     #\n";
	cout<<"\t\t#      ����6�� ����������       #\n";
	cout<<"\t\t#      ����7�� ��ؼ�·��       #\n";
	cout<<"\t\t#      ����8�� �ͷŴ洢�ռ�     #\n";
	cout<<"\t\t#===============================#\n";
}
int main()
{
	int n;
	menu();
	MGraph *M;
	AlGraph *G=NULL;
	int indegree[MAX_VEX_NUM],i;
	cout<<"�����������:  ";
	while(cin>>n) 
	{
		switch(n)
		{
			case 0:	DestroyMatrix(M);
					DestroyAlGraph(G);
					exit(0);cout<<"�������\n";		//�������
			case 1:	
					CreateMatrix(M);				//�����ڽӾ���
					DispMGraph(M);
					break;
			case 2:									//�����ڽӱ�
					if(G==NULL)
						CreateAlGraph(G,M);
					DispAlGraph(G);
					break;
			case 3:									//��ͼ���ڽӱ�DFS
					if(G==NULL)
						cout<<"�ڽӱ�δ����!\n";
					else
					{
						for(i=0;i<G->vexnum;i++)	//init visited���� 
							visited[i]=false;
						cout<<"�������������������:\n";
						DFS(G,0);
						cout<<endl;
					}	
					break;
			case 4:									//��ͼ���ڽӱ�BFS
					if(G==NULL)
						cout<<"�ڽӱ�δ����!\n";
					else
					{
						for(i=0;i<G->vexnum;i++)	//init visited����
							visited[i]=false;
						cout<<"�������������������:\n";
						BFS(G,0);
					}
					break;
			case 5:									//��ͼ������������
					if(G!=NULL)
					{
						FindDegree(G,indegree);
						DispDegree(indegree,G->vexnum);
					}
					else
						cout<<"�ڽӱ�δ����!\n";
					break;
			case 6:									//�����������ж�AOE���ܷ�˳������
					if(G==NULL)
						cout<<"�ڽӱ�δ����!\n";
					else
					{
						if(TopologicalSort(G))
							cout<<"\tAOE���ܹ�˳������\n"; 
						else
							cout<<"\tAOE������˳������\n";
					}
					break;
			case 7:									//��AOE���Ĺؼ��������/�ٷ���ʱ��
					if(G==NULL)
						cout<<"�ڽӱ�δ����!\n";
					else
					{
						CriticalPath(G);
					}
					break;
			case 8:	DestroyMatrix(M);			//�ͷŴ洢�ռ� 
					DestroyAlGraph(G);
					cout<<"�ڽӱ���ڽӾ��������٣�\n";
					break;
			default:cout<<"����������������룡\n";
		} 
		system("pause");		// ������Ļ 
		system("cls"); 			//���� 
		menu();
		cout<<"�����������:  ";
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