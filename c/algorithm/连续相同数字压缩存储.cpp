#include<iostream>
using namespace std;
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int n,a,i,b[1000];
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		int count=1,m=b[0],num=1;
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
1 1 4 2 4 2
5
1 2 3 2 1
output:
2 1 1 4 1 2 1 4 1 2
1 1 1 2 1 3 1 2 1 1
*/