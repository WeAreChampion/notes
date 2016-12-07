#include<iostream>
/*交换行，求交换最少的次数使矩阵相同，相斥则看为相同 */
using namespace std;
#define MaxSize 20
typedef struct{
	int a[MaxSize];
	int length;
}Triple;
int visited1[MaxSize];
int visited2[MaxSize];
bool compareTrue(Triple t1,Triple t2)//判断是否相同 
{
	for(int i=0;i<t1.length;i++)
	{
		if(t1.a[i]!=t2.a[i])
		{
			return false;
		}
	}
	return true;
}
bool compareFalse(Triple t1,Triple t2)//判断是否互补 
{
	for(int i=0;i<t1.length;i++)
	{
		if(t1.a[i]+t2.a[i]!=1)
		{
			return false;
		}
	}
	return true;
}/* 
void Swap(Triple &t1,Triple &t2)
{
	for(int i=0;i<t1.length;i++)
	{
		int t=t1.a[i];
		t1.a[i]=t2.a[i];
		t2.a[i]=t;
	}
}*/ 
int getCount(Triple t1[],Triple t2[],int n)//t1 is aim
{
	int i,j,count=0,sum=0; 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(visited1[j]&&visited2[i])//find the same
			{
				if(i==j)//the same row
				{
					if(compareTrue(t1[i],t2[j])||compareFalse(t1[i],t2[j]))
					{
						visited1[j]=0;
						visited2[i]=0;
					}
					else
					{
						continue;
					}
				}
				else//different row
				{
					if(compareTrue(t1[i],t2[j])||compareFalse(t1[i],t2[j]))
					{
						count++;
						visited1[j]=0;
						visited2[i]=0;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		sum+=visited1[i];
	}/*
	if(sum!=0)
	{
		return -1;
	}*/
	cout<<"sum="<<sum<<endl;
	return count;
}
int  main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int m,n,i,j;
		Triple marry[20];
		cin>>m>>n;
		for(i=0;i<m;i++)//input 原array 
		{
			marry[i].length=n;
			for(j=0;j<n;j++)
			{
				cin>>marry[i].a[j];
			}
		}
		Triple marry2[20];
		for(i=0;i<m;i++)//input 目array
		{
			marry2[i].length=n;
			for(j=0;j<n;j++)
			{
				cin>>marry2[i].a[j];
			}
		}
		for(i=0;i<m;i++)
		{
			visited1[i]=1;
			visited2[i]=1;
		}
		int count=getCount(marry,marry2,m);
		cout<<count<<endl;
		if(ca)
		{
			cout<<endl;
		}
	}
	return 0;
}
/*
2
4 3
1 0 1
0 0 0
1 1 0
1 0 1

1 0 1
1 1 1
0 0 1
1 0 1
4 3
1 0 1
0 0 0
1 1 0
1 1 0

1 1 0
1 1 1
0 0 1
1 0 1
*/