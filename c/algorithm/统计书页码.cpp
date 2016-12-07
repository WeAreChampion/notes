#include<iostream>
using namespace std;
void count(int n,int a[])
{
	if(n<10)
	{
		a[n]++;
	}
	else
	{
		while(n)
		{
			a[n%10]++;
			n=n/10;
		}
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		int a[10]={0};
		for(int i=1;i<=n;i++)
		{
			count(i,a);
		} 
		for(int i=0;i<10;i++)
		{
			cout<<a[i]<<endl;
		}
	} 
	return 0;
}