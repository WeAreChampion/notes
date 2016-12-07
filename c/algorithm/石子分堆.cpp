#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n)
	{
		int i,sum=0,a;
		for(i=0;i<n;i++)
		{
			cin>>a;
			sum+=a;
		}
		int t=sum-n;
		if(t%2)
		{
			cout<<"Alice"<<endl;
		}
		else
		{
			cout<<"Bob"<<endl;
		}
	}
	return 0;
}