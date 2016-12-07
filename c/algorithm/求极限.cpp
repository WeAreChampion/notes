#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if(a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	if(b==0)
	{
		return a;	
	}
	else
	{
		return gcd(b,a%b);
	}
}
int main()
{
	int m,n;
	while(cin>>n>>m)
	{
		int a[120],b[120],i;
		for(i=0;i<n+1;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<m+1;i++)
		{
			cin>>b[i];
		}
		if(n>m)
		{
			if(a[0]*b[0]<0)
			{
				cout<<"-Infinity"<<endl;
				continue;
			}
			else
			{
				cout<<"Infinity"<<endl;
				continue;
			}
		}
		else if(n==m)
		{
			int t=gcd(abs(a[0]),abs(b[0]));
			if(a[0]*b[0]>0)
			{
				cout<<abs(a[0]/t)<<"/"<<abs(b[0]/t)<<endl;
				continue;
			}
			else
			{
				cout<<"-"<<abs(a[0]/t)<<"/"<<abs(b[0]/t)<<endl;
				continue;
			}
		}
		else
		{
			cout<<"0/1"<<endl;
			continue;
		}
	}
	return 0;
}