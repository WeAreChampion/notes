#include<iostream>
using namespace std;
void Swap(int &x,int &y);
#define Max 100
class Flowshop
{
public:
	int Flow(int M[Max][3],int n);
	void Backtrack(int i);
	void Disp();
	int M[Max][3],	//各作业所需的处理时间 
		x[Max],		//当前作业调度 
		bestx[Max],	//当前最优作业调度 
		f2[Max],	//机器2完成处理时间 
		f1,		//机器1完成处理时间 
		f,		//完成时间和 
		bestf,	//当前最优值 
		n;		//作业数 
};
int Flowshop::Flow(int M[Max][3],int n)
{
	int ub=INT_MAX,i,j;
	Flowshop X;
	for(i=1;i<=n;i++)//init
	{
		for(j=1;j<=2;j++)
			X.M[i][j]=M[i][j];
	}
	X.n=n;
	X.bestf=ub;
	X.f1=0;
	X.f=0;
	for(int i=1;i<=n;i++)//init
	{
		X.f2[i]=0;
		X.x[i]=i;//作业号 
	}
	X.Backtrack(1);
	return X.bestf;
}
void Flowshop::Disp()
{
	for(int i=1;i<=n;i++)
		cout<<bestx[i]<<" ";
	cout<<endl;
}
void Flowshop::Backtrack(int i)
{
	int j;
	if(i>n)
	{
		for(j=1;j<=n;j++)
		{
			bestx[j]=x[j];
		}
		cout<<"The bestx[]:";
		Disp();
		bestf=f;
	}
	else
	{
		for(j=i;j<=n;j++)
		{
			f1+=M[x[j]][1];
			f2[i]=(f2[i-1]>f1?f2[i-1]:f1)+M[x[j]][2];
			f+=f2[i];
			if(f<bestf)
			{
				Swap(x[i],x[j]);
				Backtrack(i+1);	
				Swap(x[i],x[j]);
			}
			f1-=M[x[j]][1];
			f-=f2[i];
		}		
	}
}
void Swap(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
int main()
{
	int n,a[Max][3],i,j;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=2;j++)
				cin>>a[i][j];
		Flowshop f; 
		int aa=f.Flow(a,n);
		cout<<aa<<endl;
	}
	return 0;
} 
/*
3
2 1
3 1
2 3
*/ 