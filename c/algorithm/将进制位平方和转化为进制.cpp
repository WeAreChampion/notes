#include<iostream>
using namespace std;
int convert(int n,int m,int a[])//convert n to m½øÖÆ ,save in a[]
{
	int i=0;
	while(n!=0)
	{
		a[i++]=n%m;
		n=n/m;
	}
	return i;//return length
}
int getsum(int a[],int length)//get sum
{
	int sum=0;
	for(int i=0;i<length;i++)
	{
		sum+=a[i]*a[i];
	}
	return sum;
}
int main()
{
	int n,m,a[1000],length,i;
	while(cin>>n>>m)
	{
		int sum=0;
		for(i=1;i<=n;i++)
		{
			if(n%i==0)
			{
				length=convert(i,m,a);
				sum+=getsum(a,length);	
			}
		}
		length=convert(sum,m,a);
		for(i=length-1;i>=0;i--)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}