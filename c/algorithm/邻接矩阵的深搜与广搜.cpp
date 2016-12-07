#include<iostream>
using namespace std;
#define  MaxVexnum 20
typedef struct
{
	int a[20][20];
	int vexnum;
}Graph;
bool visited[MaxVexnum];
void DFS(Graph G,int v)
{
	visited[v]=true;
	cout<<"V"<<v<<" ";
	for(int j=0;j<G.vexnum;j++)
	{
		if(G.a[v][j]!=0&&!visited[j])
		{
			DFS(G,j);
		}
	}
}
void DFSTraverse(Graph G)
{
	for(int v=0;v<G.vexnum;v++)
	{
		visited[v]=false;
	}
	for(int v=0;v<G.vexnum;v++)
	{
		if(!visited[v])
		{
			DFS(G,v);
		}
	}
}
void BFSTraverse(Graph G)
{
	for(int v=0;v<G.vexnum;v++)
	{
		visited[v]=false;
	}
	int Queue[MaxVexnum];
	int front=0,rear=0;
	for(int v=0;v<G.vexnum;v++)
	{
		if(!visited[v])
		{
			visited[v]=true;
			cout<<"V"<<v<<" ";
			rear++;
			Queue[rear]=v;
			while(rear!=front)
			{
				front++;
				int i=Queue[front];
				for(int j=0;j<G.vexnum;j++)
				{
					if(G.a[i][j]!=0&&!visited[j])
					{
						cout<<"V"<<j<<" ";
						visited[j]=true;
						rear++;
						Queue[rear]=j;
					}
				}
			}
		}
	}
}
int main()
{
	Graph G;
	int n;
	cin>>n;
	G.vexnum=n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>G.a[i][j];
		}
	}
	cout<<"其深度优先搜索序列是:";
	DFSTraverse(G);
	cout<<endl;
	cout<<"广度优先搜索序列是:";
	BFSTraverse(G);
	cout<<endl;
	return 0;
} 
/*
4
0 1 0 1
1 0 1 0
0 1 0 0
1 0 0 0
*/