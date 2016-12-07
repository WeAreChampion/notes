#include<iostream>
using namespace std;
int f(int n)
{
	int k=0;
	while(n)
	{
		k++;
		n=n/10; 
	}
	return k;
}
int Count(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=0&&i<=9)
		{
			sum++;
			if(sum==n)
				return sum;
		}
		else
		{
			sum+=f(i);
			if(sum==n)
				return i;
			if(sum>n)
				return 0;
		}
	}
	return 0;
}
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int n;
		cin>>n;
		if(Count(n)==0)
		{
			cout<<-1<<endl;
		}
		else
			cout<<Count(n)<<endl;
	}
	return 0;
}