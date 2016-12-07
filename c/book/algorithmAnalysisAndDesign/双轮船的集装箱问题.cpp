#include<iostream>
using namespace std;
template<class Type>
class Loading
{
public:
	Type MaxLoading(Type w[],Type c,int n,int bestx[]);
	void Backtrack(int i);
	int n,		//集装箱数
		*x,		//当前解 
		*bestx;	//当前最优解	 
	Type *w,	//集装箱重量数组 
		c,		//第一艘轮船的载重量 
		cw,		//当前载重量	 
		bestw,	//当前最优载重量 
		r;		//剩余集装箱重量 
};
template<class Type>
void Loading<Type>::Backtrack(int i)//搜索第i层结点 
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
		x[i]=1;		//表明已选 
		cw+=w[i];//改变当前载重量 
		Backtrack(i+1);
		cw-=w[i]; //还原载重量 
	}
	if(cw+r>bestw)
	{
		x[i]=0;	//表明未选 
		Backtrack(i+1);//搜索有子树
	}
	r+=w[i];//还原 
}
template<class Type>
Type Loading<Type>::MaxLoading(Type *w,Type c,int n,int *bestx)
{
	Loading<Type> X;
	X.x=new int [n+1];//对相关数组，变量赋值 
	X.w=w;
	X.c=c;
	X.n=n;
	X.bestx=bestx;
	X.bestw=0;
	X.cw=0;
	//init
	X.r=0;
	for(int i=1;i<=n;i++)//剩余重量 
		X.r+=w[i];
	X.Backtrack(1);
	return X.bestw;
}
int main()
{
	int n,c1,c2,i;
	int ca=1;
	while(cin>>n)
	{
		int *w=new int[n+1];
		int *bestx=new int[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>w[i];
			bestx[i]=0;
		}
		cin>>c1>>c2;
		if(c2>c1)//Swap(c1,c2)
		{
			int temp=c1;
			c1=c2;
			c2=temp;
		}
		Loading<int> l;
	 	int max1=l.MaxLoading(w,c1,n,bestx);
	 	cout<<"Case: "<<ca<<endl;
		int count=0,sum1=0,sum2=0;
		int *bestw=new int [n+1];
		int *besty=new int [n+1];
		for(i=1;i<=n;i++)
		{
			if(bestx[i]==0)
				count++;
			bestw[count]=w[i];//save the 未装的货物重量 
		}
		l.MaxLoading(bestw,c2,count,besty);//对c2进行装剩余集装箱 
		int count1=0;
		for(i=1;i<=count;i++)//累计未装入c1中集装箱装入c2中的个数 
			if(besty[i])
				count1++;
		if(count1!=count)//不相等，表明未全部装完，输出No 
		{
			cout<<"No";
		}
		else
		{
			cout<<max1<<" ";
			for(i=1;i<=n;i++) 
				cout<<bestx[i];
		}
		cout<<endl;
		ca++;
		delete w;
		delete bestx;
		delete besty;
		delete bestw;
	}
	return 0;
}
/*
Input:
3
10 40 40
50 50
3
20 40 40
50 50
Output:
Case 1:
50 110
Case 2: 
No
*/