#include<iostream>
using namespace std;
int main()
{
	int a,b,i,n;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		int sum1=0,sum2=0;
		for(i=1;i<a;i++)
			if(a%i==0)
				sum1+=i;
		for(i=1;i<b;i++)
			if(b%i==0)
				sum2+=i;
		if(sum1==b&&sum2==a)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}