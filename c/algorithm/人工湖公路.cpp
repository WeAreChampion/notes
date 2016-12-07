/*
方法： 
　树状数组是一个查询和修改复杂度都为log(n)的数据结构，假设数组a[1..n]，
 那么查询a[1]+...+a[n]的时间是log(n)级别 ，而且是一个在线的数据结构，支
 持随时修改某个元素的值，复杂度也为log(n)级别。


有一个湖，他的周围都是城市，但是由于水路不发达，所以城市间的交通
 都靠陆地。每一个城市都是只和它相邻的城市建有公路，假设有n个城市，
 编号依次是1~n，那么编号i的城市只和i%n+1、(i-2+n)%n+1两个城市有路
 相连。公路是双向的，有多公路会坏掉，有的会被修好。现在有人询问，
 某两个城市是否可以相互到达。
 输入：
 第一行有两个数n，m，分别代表城市数目和询问次数，接着是m行，每一
 行有一个标志数f和两个城市编号x，y。
 f=0，表明x，y之间的公路好的，则x，y之间的公路会坏掉；如果x，y
 之间的公路是坏的，则x，y之间的公路会被修好。
 f=1，那么就代表询问x，y之间的是否相互可到达。 
input:
5 10
1 2 5
0 4 5
1 4 5
0 2 3
1 3 4
1 1 3
0 1 2
0 2 3
1 2 4
1 2 5
output:
YES
YES
YES
NO
YES
NO
*/
#include<iostream>
#include<cstring>
using namespace std;
int c[100001],ma[100001];
int lowbit(int t)//位运算 
{
	return t&(-t);
}
void insert(int k,int d,int max)//快速修改 
{
	while(k<=max)
	{
		c[k]+=d;
		k=k+lowbit(k);
	}
}
int getsum(int k)//快速求和 
{
	int t=0;
	while(k>0)
	{
		t+=c[k];
		k-=lowbit(k);
	}
	return t;
}
int main()
{
	int i,j,k,t,n;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(c,0,sizeof(c));//初始化数组c 
		for(i=1;i<=n;i++)//起始任意间公路完好 
		{
			insert(i,1,n);
			ma[i]=1;//ma数组记录当前这个城市是否和下一个城市相连 
		}
		while(k--)
		{
			int a,b,f;
			cin>>f>>a>>b;
			if(f==0)//遇到毁坏公路，将其修好 
			{
				if(a>b)
				{
					t=a;
					a=b;
					b=t;
				}
				if(b==n&&a==1)
				{
					if(ma[b]==1)
					{
						insert(b,-1,n);
						ma[b]=0;
					}
					else
					{
						insert(b,1,n);
						ma[b]=1;
					}
				}
				else
				{
					if(ma[a]==1)
					{
						insert(a,-1,n);
						ma[a]==0;
					}
					else
					{
						insert(a,1,n);
						ma[a]=1;
					}
				}
			}
			if(f==1)//询问是否可以到达 
			{
				if(a>b)
				{
					t=a;
					a=b;
					b=t;
				}
				int t1,t2,t3,t4;
				t1=getsum(a-1);
				t2=getsum(b-1);
				int flag=0;
				if(t2-t1==b-a)//判断顺时针是否可以到达 
				{
					flag=1;
					printf("YES\n");
				}
				if(!flag)//判断逆时针是否可以到达 
				{
					t3=getsum(n)-t2;
					if(t3+t1==n-b+a)
					{
						printf("YES\n");
						flag=1;
					}
				}
				if(!flag)
					printf("NO\n");
			}
		}	
	}
	return 0;
}