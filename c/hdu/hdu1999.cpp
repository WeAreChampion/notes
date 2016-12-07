#include<iostream>
using namespace std;
int f(int n)
{
	int i;
	if(n==0||n==1)
		return 0;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int sum=0,a,i=0,t;
		cin>>a;
		if(f(a-1)==1)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}