#include<iostream>
using namespace std;
int main()
{
	int a[1000],n,m,i;
	while(cin>>n>>m)
	{
		a[0]=n%10;
		for(i=1;;i++)
		{
			a[i]=(a[i-1]*a[0])%10;
			if(a[i]==a[0]) break;
		}
		if(m%i==0)
			cout<<a[i-1]<<endl;
		else if(m%i==1)
			cout<<a[0]<<endl;
		else
			cout<<a[m%i-1]<<endl;
	}
	return 0;
}