#include<iostream>
#include<cmath>
using namespace std;
int n;//皇后个数 
int *x;//当前解
int sum=0;//累计可行方案
bool Place(int k)//判断第k行的x[k]位置是否合法 
{
	for(int j=1;j<k;j++)
	{
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	} 
	return true;
} 
void Backtrack()
{
	x[1]=0;
	int k=1;
	while(k>0)
	{
		x[k]+=1;//
		while((x[k]<=n)&&!Place(k))
			x[k]+=1;//
		if(x[k]<=n)
		{
			if(k==n)
			{
				sum++;
				cout<<"第"<<sum<<"种可行方案:"<<endl;
				for(int i=1;i<=n;i++)//output the result
					cout<<x[i]<<" ";
				cout<<endl;
			}	
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
			k--;
	}
} 
int main()
{
	cout<<"Please input n= ";
	while(cin>>n)
	{
		x=new int [n+1];
		Backtrack();
		cout<<"the sum is :"<<sum<<endl;
		sum=0;
		delete x;
		cout<<"Please input n= ";
	}
	return 0;
} 