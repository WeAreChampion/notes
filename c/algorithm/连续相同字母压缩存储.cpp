#include<iostream>
using namespace std;
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int n,a,i;
		char b[1000];
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		/*
		for(i=0;i<n;i++)
		{
			cout<<b[i];
		}
		*/
		int count=1,num=1;
		char m=b[0];
		for(i=1;i<n;i++)
		{
			if(b[i]==m)
			{
				count++;
			}
			else
			{
				if(num!=1)
					cout<<" "<<count<<" "<<m;
				else
					cout<<count<<" "<<m;
				m=b[i];
				count=1;
				num++;
			}
		}
		cout<<" "<<count<<" "<<m<<endl;
	}
	return 0;
}
/*
2
6
aabbcc
5
aabbc
*/