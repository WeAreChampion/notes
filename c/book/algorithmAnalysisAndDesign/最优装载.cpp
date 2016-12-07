#include<iostream>
using namespace std;
#define Max 100
int n,		//集装箱数
	x[Max],		//当前解 
	bestx[Max];	//当前最优解	 
int w[Max],	//集装箱重量数组 
	c,		//第一艘轮船的载重量 
	cw,		//当前载重量	 
	bestw,	//当前最优载重量 
	r;		//剩余集装箱重量 
void Backtrack(int i)//搜索第i层结点 
{
	if(i>n)//到达叶子结点 
	{
		if(cw>bestw)//存储当前最优值 
		{
			bestw=cw;
			for(int j=1;j<=n;j++)
				bestx[j]=x[j];
		}
		return ;
	}
	//搜索子树 
	r-=w[i];
	if(cw+w[i]<=c)//搜索左子树 
	{
		x[i]=1;
		cw+=w[i];//改变当前载重量 
		Backtrack(i+1);
		cw-=w[i]; //还原载重量 
	}
	if(cw+r>bestw)
	{
		x[i]=0;
		Backtrack(i+1);//搜索有子树
	}
	r+=w[i];
}
int MaxLoading(int _w[],int _c,int _n,int _bestx[])
{
	c=_c;
	n=_n;
	for(int i=1;i<=n;i++)
	{
		w[i]=_w[i];
		bestx[i]=_bestx[i];
	}
	bestw=0;
	cw=0;
	//init
	r=0;
	for(int i=1;i<=n;i++)
		r+=w[i];
	Backtrack(1);
	return bestw;
}
int main()
{
	int n,c;
	int ca=1;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
			bestx[i]=0;
		}
		cin>>c;
	 	int max=MaxLoading(w,c,n,bestx);
	 	cout<<"Case: "<<ca<<endl;
		cout<<max<<"　";
		for(int i=1;i<=n;i++)
			cout<<bestx[i];
		cout<<endl;
		ca++;
	}
	return 0;
}
/*
Input:
3
10 40 40
50
Output:
Case 1:
50 110
*/