#include<iostream>
using namespace std;
int f(int n)
{
	int a=1,i;
	if(n==1||n==0)
		return 1;
	for(i=2;i<=n;i++)
		a=a*i;
	return a;
}
int main()
{
	int n,s,i,f1,f2,f3,t;
	double sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		f1=1;f2=2;
		if(n==2)
		{
			cout<<"50.00%"<<endl;
			continue;
		}
		for(i=3;i<=n;i++)
		{
			f3=f1+f2;
			f1=f2;
			f2=f3;
		}
		sum=1.0/f(n);
		printf("%.2lf",(n-1)*f2*sum*10);
		cout<<"%"<<endl;
	}
	return 0;
}