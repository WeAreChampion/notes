#include<iostream>
using namespace std;
#include"Graph.h"
#define INF 32767
//���ڽӾ���gת��Ϊ�ڽӱ�G 
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
			if(g.edges[i][j]!=0)//���ڽ� 
			{
				p=(ArcNode *) malloc(sizeof(ArcNode));//���ٽڵ� 
				p->adjex=j;//�洢�յ� 
				p->info=g.edges[i][j];//���Ȩֵ 
				p->nextarc=G->adjust[i].firstarc;//��p���ӵ���� 
				G->adjust[i].firstarc=p;	
			}
	} 
	G->n=n;
	G->e=g.e;
}
//���ڽӱ�Gת�����ڽӾ���g 
void ListToMat(ALGraph *G,MGraph &g)
{
	cout<<"ͼG���ڽӾ���ת�����ڽӱ�\n";
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
void DispMat(MGraph g)//����ڽӾ���g 
{
	cout<<"ͼG���ڽӾ���\n";
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
			if(g.edges[i][j]==INF)
				//printf("%3d",);
				cout<<"��\t";
			else 
				//printf("%3d",g.edges[i][j]);
				cout<<g.edges[i][j]<<"\t";
		printf("\n");
	}
} 
void DispAdj(ALGraph *G)//����ڽӱ�G 
{
	cout<<"ͼG���ڽӱ�"<<endl;
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
//���G�дӶ���u������v�����м�·��,�ݹ����i 
void PathAll1(ALGraph *G,int u,int v,int path[],int i)
{
	ArcNode *p;
	int j,n;
	visited[u]=true;//����ѷ��� 
	p=G->adjust[u].firstarc;//pָ�򶥵�u�ĵ�һ������ͷ��� 
	while(p!=NULL)
	{
		n=p->adjex;
		if(n==v)//�����յ� 
		{
			path[i+1]=v;//����յ�·�� 
			for(j=0;j<=i+1;j++)//���·�� 
			{
				cout<<path[j]<<"\t";
			}
			cout<<endl;
		}
		else if(!visited[n])//�ݹ����δ��ǵĽڵ� 
		{
			path[i+1]=n;//�洢·�� 
			PathAll1(G,n,v,path,i+1);
		}
		p=p->nextarc;//find the next vertex
	}
	visited[u]=false;//��ԭ���ʱ�� 
} 
void PathAll2(ALGraph *G,int u,int v,int l,int path[],int d)
{
	int m,i;
	ArcNode *p;
	visited[u]=true;//����Ѿ����� 
	d++;
	path[d]=u;//��ӵ�·�� 
	if(u==v&&d==l)//���ﶥ����·������Ϊl 
	{
		for(i=0;i<=d;i++)
		{
			//printf("%3d",path[i]);
			cout<<path[i]<<"\t";
		}
		cout<<endl;
	}
	p=G->adjust[u].firstarc;//pָ�򶥵�u�ĵ�һ������ͷ��� 
	while(p!=NULL)
	{
		m=p->adjex;//mΪu���ڽӶ��� 
		if(!visited[m])//δ���ʽڵ�m���ݹ���� 
		{
			PathAll2(G,m,v,l,path,d);
		}
		p=p->nextarc;//������һ���ڽӶ��� 
	}
	visited[u]=false;//��ԭ���ʱ�� 
}
//�󶥵�u������v�����·�� 
int ShortPath(ALGraph *G,int u,int v,int path[])
{
	struct
	{
		int vno;//��ǰ����ı�� 
		int level;//��ǰ����Ĳ�� 
		int parent;//��ǰ�����ǰһ���� 
	}qu[MAXV];
	int front=-1,rear=-1,k,lev,i,j;//init the queue
	ArcNode *p;
	visited[u]=true;//����ѷ��� 
	rear++;			//��ӣ��޸Ķ��� 
	qu[rear].vno=u;
	qu[rear].level=0;
	qu[rear].parent=-1;//����� 
	while(front<rear)//���зǿ���ִ�� 
	{
		front++;	//out queue 
		k=qu[front].vno;
		lev=qu[front].level;
		if(k==v)//�����յ� 
		{
			i=0;
			j=front;	//��ʱȫ������ 
			while(j!=-1)//���·������path�� 
			{
				path[lev-i]=qu[j].vno;//�Ӻ���ǰ�洢 
				j=qu[j].parent;
				i++;
			}
			return lev;//���ҵ�����v������ 
		}
		p=G->adjust[k].firstarc;//ȡk�ı߱�ͷָ�� 
		while(p!=NULL)
		{
			if(!visited[p->adjex])//δ���� 
			{
				visited[p->adjex]=true;//�÷��ʱ�� 
				rear++;//�޸���Ϣ����� 
				qu[rear].vno=p->adjex;
				qu[rear].level=lev+1;
				qu[rear].parent=front;//���׽ڵ�Ϊ���еĶ��ֽڵ� 
			}
			p=p->nextarc;//ָ����ָ 
		}
	} 
	return 0;
}
//�ж�������·�����Ƿ�������Ծ����Ͳ��ɾ����ĵ�
int V1[MAXV],V2[MAXV];
int Cond(int path[],int d,int n,int m)//d���ع�/������ 
{
	int flag1=0,f1,flag2=0,f2,i,j;
	for(i=0;i<n;i++)
	{
		f1=1;
		for(j=0;j<=d;j++)
		{
			if(path[j]==V1[i])//��·�����ҵ� 
			{
				f1=0;
				break;
			}
		}
		flag1+=f1;//�ۼӽ�� 
	}
	for(i=0;i<m;i++)
	{
		f2=0;
		for(j=0;j<=d;j++)
		{
			if(path[j]==V2[i])//��·�����ҵ� 
			{
				f2=1;
				break;
			}
		}
		flag2+=f2;//�ۼӽ�� 
	}
	if(flag1==0&&flag2==0)//���ϱع��Ͳ����㼯 
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
	if(vi==vj&&Cond(path,d,n,m))//�ж� 
	{
		for(i=0;i<=d;i++)//output the path 
			cout<<path[i]<<"\t";
		cout<<endl;
	}
	p=G->adjust[vi].firstarc;
	while(p!=NULL)
	{
		v=p->adjex;
		if(!visited[v])//δ���ʣ��ݹ���� 
		{
			TravPath(G,path,v,vj,d,n,m);
		}
		p=p->nextarc;
	}
	visited[vi]=false;//��ԭ���� 
	d--;
}//������������������������������ 
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
//���ù������������������������
void BFS(ALGraph *G,int v)
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;
	int w,i;
	visited[v]=true;
	rear=(rear+1)%MAXV;//ѭ������ 
	queue[rear]=v;//push v
	while(front<rear)//���в��� 
	{
		front=(front+1)%MAXV;//���� 
		w=queue[front];
		p=G->adjust[w].firstarc;
		while(p!=NULL)
		{
			if(!visited[p->adjex])
			{
				printf("<%d,%d>",w,p->adjex);
				visited[p->adjex]=true;
				rear=(rear+1)%MAXV;//��� 
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
	
	
	//�����ڽӾ��� 
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
	
	
	//����ͼ�ļ�·�� 
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
	printf("��%d��%d������·����\n",u,v);
	PathAll1(G2,u,v,path,0);
	cout<<endl;
	printf("��%d��%d�����г���Ϊ%d·����\n",u,v,d);
	PathAll2(G2,u,v,d,path,-1);
	cout<<endl;
	InitVisited(g2.n);
	printf("��%d��%d�����·����\n",u,v);
	j=ShortPath(G2,u,v,path);
	for(int i=0;i<=j;i++)
		//printf("%3d",path[i]);
		cout<<path[i]<<"\t";
	cout<<endl;
	
	//����ͼ������Լ��������·��
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
	cout<<"��㣺";
	cin>>start;
	cout<<"�յ㣺";
	cin>>end;
	int count1,count2;
	cout<<"�ؾ��������";
	cin>>count1;
	cout<<"�ؾ��㼯�ϣ�";
	for(i=0;i<count1;i++)
		cin>>V1[i];
	cout<<"�ع��������";
	cin>>count2;
	cout<<"�ع��㼯�ϣ�";
	for(i=0;i<count2;i++)
		cin>>V2[i];
	cout<<"����·����\n";
	TravPath(G3,path,start,end,-1,count1,count2);
	cout<<endl;
	
	
	
	//����ȹ������������
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
	cout<<"���������������";
	DFS(G4,3);
	cout<<endl;
	InitVisited(g4.n);
	cout<<"���������������";
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