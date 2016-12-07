#include<iostream>
using namespace std;
int f(int x,int y)
{
	if(x-y>=0)
	{
		return x-y;
	}
	return y-x;
}
int getdis(char a[55][55],int x,int y,int d,int n)
{
	int i,j,count=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]=='*'&&f(x,i)+f(y,j)<=d)
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int n,m,d;
		cin>>n>>m>>d;
		char a[55][55];
		int i,j,x,y;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			cout<<getdis(a,x,y,d,n)<<endl;
		}
		if(ca!=0)
		{
			cout<<endl;
		}
	}
	return 0;
} 