#include<iostream>
using namespace std;
#include"Graph.h"
#define INF 32767
//将邻接矩阵g转化为邻接表G 
bool visited[MAXV];
void InitVisited(int n)
{
	for(int i=0;i<n;i++)
		visited[i]=false;
}
int A1[MAXV][6]={
	{0,5,0,7,0,0}, 
	{0,0,4,0,0,0},
	{8,0,0,0,0,9},
	{0,0,5,0,0,6},
	{0,0,0,5,0,0},
	{3,0,0,0,1,0}
};
int A2[MAXV][6]={
	{0,1,0,1,0,0},
	{0,0,1,0,0,0},
	{1,0,0,0,0,1},
	{0,0,1,0,0,1},
	{0,0,0,1,0,0},
	{1,1,0,1,1,0}}; 
void MatToList(MGraph g,ALGraph *&G)
{	
	int i,j,n=g.n;
	ArcNode *p;//define a vertex
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for(i=0;i<n;i++)
		G->adjust[i].firstarc=NULL;//init
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
			if(g.edges[i][j]!=0)//相邻接 
			{
				p=(ArcNode *) malloc(sizeof(ArcNode));//开辟节点 
				p->adjex=j;//存储终点 
				p->info=g.edges[i][j];//存放权值 
				p->nextarc=G->adjust[i].firstarc;//将p链接到表后 
				G->adjust[i].firstarc=p;	
			}
	} 
	G->n=n;
	G->e=g.e;
}
//将邻接表G转换成邻接矩阵g 
void ListToMat(ALGraph *G,MGraph &g)
{
	cout<<"图G的邻接矩阵转换成邻接表：\n";
	int i,j,n=G->n;
	ArcNode *p;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			g.edges[i][j]=0;//init
	for(i=0;i<n;i++)
	{
		p=G->adjust[i].firstarc;
		while(p!=NULL)
		{
			g.edges[i][p->adjex]=p->info;
			p=p->nextarc;
		}
	} 
	g.n=n;
	g.e=G->e;
}
void DispMat(MGraph g)//输出邻接矩阵g 
{
	cout<<"图G的邻接矩阵：\n";
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
			if(g.edges[i][j]==INF)
				//printf("%3d",);
				cout<<"∞\t";
			else 
				//printf("%3d",g.edges[i][j]);
				cout<<g.edges[i][j]<<"\t";
		printf("\n");
	}
} 
void DispAdj(ALGraph *G)//输出邻接表G 
{
	cout<<"图G的邻接表："<<endl;
	int i;
	ArcNode *p;
	for(i=0;i<G->n;i++)
	{
		p=G->adjust[i].firstarc;
		if(p!=NULL)
		{
			//printf("%3d",i);
			cout<<i<<":\t";
		}
		while(p!=NULL)
		{
			//printf("%3d",p->adjex);
			cout<<p->adjex<<"\t"; 
			p=p->nextarc;
		}
		cout<<endl;
	}
	cout<<endl;
}
//输出G中从顶点u到顶点v的所有简单路径,递归深度i 
void PathAll1(ALGraph *G,int u,int v,int path[],int i)
{
	ArcNode *p;
	int j,n;
	visited[u]=true;//标记已访问 
	p=G->adjust[u].firstarc;//p指向顶点u的第一条弧的头结点 
	while(p!=NULL)
	{
		n=p->adjex;
		if(n==v)//到达终点 
		{
			path[i+1]=v;//添加终点路径 
			for(j=0;j<=i+1;j++)//输出路径 
			{
				cout<<path[j]<<"\t";
			}
			cout<<endl;
		}
		else if(!visited[n])//递归访问未标记的节点 
		{
			path[i+1]=n;//存储路径 
			PathAll1(G,n,v,path,i+1);
		}
		p=p->nextarc;//find the next vertex
	}
	visited[u]=false;//还原访问标记 
} 
void PathAll2(ALGraph *G,int u,int v,int l,int path[],int d)
{
	int m,i;
	ArcNode *p;
	visited[u]=true;//标记已经访问 
	d++;
	path[d]=u;//添加到路径 
	if(u==v&&d==l)//到达顶点且路径长度为l 
	{
		for(i=0;i<=d;i++)
		{
			//printf("%3d",path[i]);
			cout<<path[i]<<"\t";
		}
		cout<<endl;
	}
	p=G->adjust[u].firstarc;//p指向顶点u的第一条弧的头结点 
	while(p!=NULL)
	{
		m=p->adjex;//m为u的邻接顶点 
		if(!visited[m])//未访问节点m，递归访问 
		{
			PathAll2(G,m,v,l,path,d);
		}
		p=p->nextarc;//查找下一个邻接顶点 
	}
	visited[u]=false;//还原访问标记 
}
//求顶点u到顶点v的最短路径 
int ShortPath(ALGraph *G,int u,int v,int path[])
{
	struct
	{
		int vno;//当前顶点的编号 
		int level;//当前顶点的层次 
		int parent;//当前顶点的前一顶点 
	}qu[MAXV];
	int front=-1,rear=-1,k,lev,i,j;//init the queue
	ArcNode *p;
	visited[u]=true;//标记已访问 
	rear++;			//入队，修改队列 
	qu[rear].vno=u;
	qu[rear].level=0;
	qu[rear].parent=-1;//代表根 
	while(front<rear)//队列非空则执行 
	{
		front++;	//out queue 
		k=qu[front].vno;
		lev=qu[front].level;
		if(k==v)//到达终点 
		{
			i=0;
			j=front;	//此时全部出队 
			while(j!=-1)//最短路径存入path中 
			{
				path[lev-i]=qu[j].vno;//从后往前存储 
				j=qu[j].parent;
				i++;
			}
			return lev;//查找到顶点v，返回 
		}
		p=G->adjust[k].firstarc;//取k的边表头指针 
		while(p!=NULL)
		{
			if(!visited[p->adjex])//未访问 
			{
				visited[p->adjex]=true;//置访问标记 
				rear++;//修改信息，入队 
				qu[rear].vno=p->adjex;
				qu[rear].level=lev+1;
				qu[rear].parent=front;//父亲节点为队列的对手节点 
			}
			p=p->nextarc;//指针下指 
		}
	} 
	return 0;
}
//判断条件，路径中是否包含可以经过和不可经过的点
int V1[MAXV],V2[MAXV];
int Cond(int path[],int d,int n,int m)//d个必过/不过点 
{
	int flag1=0,f1,flag2=0,f2,i,j;
	for(i=0;i<n;i++)
	{
		f1=1;
		for(j=0;j<=d;j++)
		{
			if(path[j]==V1[i])//在路径中找到 
			{
				f1=0;
				break;
			}
		}
		flag1+=f1;//累加结果 
	}
	for(i=0;i<m;i++)
	{
		f2=0;
		for(j=0;j<=d;j++)
		{
			if(path[j]==V2[i])//在路径中找到 
			{
				f2=1;
				break;
			}
		}
		flag2+=f2;//累加结果 
	}
	if(flag1==0&&flag2==0)//符合必过和不过点集 
		return 1;
	return 0;
} 
void TravPath(ALGraph *G,int path[],int vi,int vj,int d,int n,int m)
{
	int v,i;
	ArcNode *p;
	visited[vi]=true;
	d++;
	path[d]=vi;
	if(vi==vj&&Cond(path,d,n,m))//判断 
	{
		for(i=0;i<=d;i++)//output the path 
			cout<<path[i]<<"\t";
		cout<<endl;
	}
	p=G->adjust[vi].firstarc;
	while(p!=NULL)
	{
		v=p->adjex;
		if(!visited[v])//未访问，递归访问 
		{
			TravPath(G,path,v,vj,d,n,m);
		}
		p=p->nextarc;
	}
	visited[vi]=false;//还原访问 
	d--;
}//利用深度优先搜索求深度优先搜索树 
void DFS(ALGraph *G,int v)
{
	ArcNode *p;
	visited[v]=true;
	p=G->adjust[v].firstarc;
	while(p!=NULL)
	{
		if(!visited[p->adjex])
		{
			printf("<%d,%d>",v,p->adjex);
			DFS(G,p->adjex);
		}
		p=p->nextarc;
	}
}
//利用广度优先搜索求广度优先搜索树
void BFS(ALGraph *G,int v)
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;
	int w,i;
	visited[v]=true;
	rear=(rear+1)%MAXV;//循环队列 
	queue[rear]=v;//push v
	while(front<rear)//队列不空 
	{
		front=(front+1)%MAXV;//出队 
		w=queue[front];
		p=G->adjust[w].firstarc;
		while(p!=NULL)
		{
			if(!visited[p->adjex])
			{
				printf("<%d,%d>",w,p->adjex);
				visited[p->adjex]=true;
				rear=(rear+1)%MAXV;//入队 
				queue[rear]=p->adjex; 
			}
			p=p->nextarc;
		}
	}
}
int main()
{
	int path[MAXV];
	int i,j,u=5,v=2,d=3;
	MGraph g1,g11,g2;
	ALGraph *G1,*G2;
	
	
	//构造邻接矩阵 
	g1.n=6;
	g1.e=10;
	for(int i=0;i<g1.n;i++)
		for(j=0;j<g1.n;j++)
			g1.edges[i][j]=A1[i][j];
	DispMat(g1);
	G1=(ALGraph *) malloc (sizeof(ALGraph));
	MatToList(g1,G1);
	DispAdj(G1);
	ListToMat(G1,g11);
	DispMat(g11);
	
	
	//有向图的简单路径 
	g2.n=6,g2.e=1;
	for(int i=0;i<g2.n;i++)
		for(j=0;j<g2.n;j++)
			g2.edges[i][j]=A2[i][j];
	G2=(ALGraph *) malloc (sizeof(ALGraph));
	MatToList(g2,G2);
	DispAdj(G2);
	InitVisited(g2.n);
	path[0]=u;
	visited[u]=true;
	printf("从%d到%d的所有路径：\n",u,v);
	PathAll1(G2,u,v,path,0);
	cout<<endl;
	printf("从%d到%d的所有长度为%d路径：\n",u,v,d);
	PathAll2(G2,u,v,d,path,-1);
	cout<<endl;
	InitVisited(g2.n);
	printf("从%d到%d的最短路径：\n",u,v);
	j=ShortPath(G2,u,v,path);
	for(int i=0;i<=j;i++)
		//printf("%3d",path[i]);
		cout<<path[i]<<"\t";
	cout<<endl;
	
	//无向图中满足约束条件的路径
	MGraph g3;
	ALGraph *G3;
	int A3[MAXV][15];
	g3.n=15;
	g3.e=20;
	for(i=0;i<g3.n;i++)
		for(j=0;j<g3.n;j++)
			A3[i][j]=0;
	A3[0][1]=1;A3[0][2]=1;A3[0][3]=1;A3[0][4]=1;
	A3[1][8]=1;A3[3][6]=1;A3[4][7]=1;A3[5][8]=1;
	A3[5][9]=1;A3[6][7]=1;A3[6][9]=1;A3[7][10]=1;
	A3[7][11]=1;A3[8][12]=1;A3[9][10]=1;A3[9][12]=1;
	A3[10][13]=1;A3[11][13]=1;A3[12][14]=1;A3[13][14]=1;
	for(i=0;i<g3.n;i++)
		for(j=0;j<g3.n;j++)
			A3[j][i]=A3[i][j];
	for(i=0;i<g3.n;i++)
		for(j=0;j<g3.n;j++)
			g3.edges[i][j]=A3[i][j];
	G3=(ALGraph *) malloc (sizeof(ALGraph));
	MatToList(g3,G3);
	InitVisited(g3.n);
	int start,end;
	cout<<"起点：";
	cin>>start;
	cout<<"终点：";
	cin>>end;
	int count1,count2;
	cout<<"必经点个数：";
	cin>>count1;
	cout<<"必经点集合：";
	for(i=0;i<count1;i++)
		cin>>V1[i];
	cout<<"必过点个数：";
	cin>>count2;
	cout<<"必过点集合：";
	for(i=0;i<count2;i++)
		cin>>V2[i];
	cout<<"所求路径：\n";
	TravPath(G3,path,start,end,-1,count1,count2);
	cout<<endl;
	
	
	
	//求深度广度优先搜索树
	MGraph g4;
	ALGraph *G4; 
	int A4[MAXV][11];
	g4.n=11;
	g4.e=13;
	for(i=0;i<g4.n;i++)
		for(j=0;j<g4.n;j++)
			A4[i][j]=0;
	A4[0][3]=1;A4[0][2]=1;A4[0][1]=1;
	A4[1][5]=1;A4[1][4]=1;
	A4[2][6]=1;A4[2][5]=1;A4[2][3]=1;
	A4[3][7]=1;
	A4[6][9]=1;A4[6][8]=1;A4[6][7]=1;
	A4[7][10]=1;
	for(i=0;i<g4.n;i++)
		for(j=0;j<g4.n;j++)
			A4[j][i]=A4[i][j];
	for(i=0;i<g4.n;i++)
		for(j=0;j<g4.n;j++)
			g4.edges[i][j]=A4[i][j];
	G4=(ALGraph *) malloc (sizeof(ALGraph));
	MatToList(g4,G4);
	InitVisited(g4.n);
	DispAdj(G4);
	cout<<"深度优先搜索树：";
	DFS(G4,3);
	cout<<endl;
	InitVisited(g4.n);
	cout<<"广度优先搜索树：";
	BFS(G4,3);
	cout<<endl;
	return 0;
} 
/*
0
14
2
3 9
2
7 12 
*/