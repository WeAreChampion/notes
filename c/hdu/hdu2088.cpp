#include<iostream>
using namespace std;
int main()
{
	int a[102],n,i,sum,s,flag=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		sum=0;s=0;
		if(flag)
			cout<<endl;
		flag=1;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		s=s/n;
		for(i=0;i<n;i++)
		{
			if(a[i]>s)
				sum+=a[i]-s;
		}
		cout<<sum<<endl;
	}
	return 0;
}
