/*
ò���Ǻܾ��������dp���⣬Ӧ��˵������dp�����ţ���
�о�����dp�ȱ�������һ���������飬����ֱ��һ������ѭ����ȥ��
������dp��Ϊ�з�֧���������Եģ����Ծ���Ҫ��һ����������������ת�����������
1011 ��Ŀ���⣺һ��������n����㣬ÿ�������v��bug����w��brain��
�Ҵ�1�Ž�㿪ʼ�ߣ�����m��սʿ��
1��սʿ��������20��bugs������Ұ�ĳ����������bug���������Ҿ��ܵõ��Ǹ�����brain��
����빥����ǰ��㣬��ô�����ȹ��������ĸ���㣨1�ŵ���⣩��
���е��㹥ռ�˵�ǰ��㣬����Է������֣����򼸸���ͬ���ӽ�㣬
ȥ��ռ���ࡣҲ����˵�����ǵ�һ��·����
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