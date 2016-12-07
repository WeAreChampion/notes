#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(n%i==0)
				sum++;
		}
		if(sum%2)
		{
			cout<<1;
		}
		else
			cout<<0;
		cout<<endl;
	}
	return 0;
} 