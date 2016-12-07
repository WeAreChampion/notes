/*
貌似是很经典的树形dp问题，应该说是树形dp的入门！！
感觉树形dp比背包多了一个辅助数组，背包直接一个数组循环下去，
而树形dp因为有分支，不是线性的，所以就需要用一个辅助数组来进行转化最优情况！
1011 题目大意：一棵树，有n个结点，每个结点有v个bug，有w的brain。
我从1号结点开始走，带着m个战士。
1个战士可以消灭20个bugs，如果我把某个结点的所有bug都消灭了我就能得到那个结点的brain。
如果想攻击当前结点，那么必须先攻击了它的父结点（1号点除外）。
其中当你攻占了当前结点，你可以分派人手，走向几个不同的子结点，
去攻占更多。也就是说，不是单一的路径。
*/
# include<stdio.h>
# include<string.h>
# define N 105
struct node{
	int from,to,next;
}edge[2*N];
int head[N],tol,visit[N],ans[N],bug[N],n,m,dp[N][N],f[N][N];
void add(int a,int b)
{
	edge[tol].from=a;
	edge[tol].to=b;
	edge[tol].next=head[a];
	head[a]=tol++;
}
int max(int a,int b)//get max
{
	return a>b?a:b;
}
void dfs(int u)
{
    int i,j,r,tt,k;
    visit[u]=1;//mark is visited
    for(i=head[u];i!=-1;i=edge[i].next)
    {
	    r=edge[i].to;
	    if(!visit[r])//not visited
	    {
		    dfs(r);
		    for(k=m;k>=1;k--)
		    {
			    for(j=1;j<=k;j++)
			    {
			    	f[u][k]=max(f[u][k],f[u][k-j]+dp[r][j]);//get max
		    	}
	    	}
	      /*for(j=0;j<=m;j++)
	      	{
	      		if(j*20>=ans[u]) 
	      			dp[u][j]=max(dp[u][j],dp[r][(j*20-ans[u])/20]+bug[u]);
	      	}*/
      	}
     }
     tt=(ans[u]+19)/20;
     for(j=tt;j<=m;j++)
         dp[u][j]=f[u][j-tt]+bug[u];
}
int main()
{
     int i,a,b;
     while(scanf("%d%d",&n,&m)!=EOF)
     {
         if(n==-1 && m==-1) break;
         for(i=1;i<=n;i++)
             scanf("%d%d",&ans[i],&bug[i]);
         tol=0;//init
         memset(head,-1,sizeof(head));
         for(i=1;i<n;i++)
         {
             scanf("%d%d",&a,&b);
             add(a,b);
             add(b,a);
         }
         memset(visit,0,sizeof(visit));//init
         memset(dp,0,sizeof(dp));
         memset(f,0,sizeof(f));
         if(m==0)
         {
             printf("0\n");
             continue;
         }
         dfs(1);
         printf("%d\n",dp[1][m]);
     }
     return 0;
}
/*
Input:
5 10
50 10
40 10
40 20
65 30
70 30
1 2
1 3
2 4
2 5
1 1
20 7
-1 -1
output:
50
7 
 */