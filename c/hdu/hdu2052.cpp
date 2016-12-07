#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j,k;
	while(cin>>m>>n)
	{
		for(i=0;i<=n+1;i++)
		{
			if(i==0||i==n+1)
			{
				cout<<"+";
				for(j=0;j<m;j++)
					cout<<"-";
				cout<<"+"<<endl;
			}
			else
			{
				for(k=0;k<=m+1;k++)
				{
					if(k==0||k==m+1)
						cout<<"|";
					else
						cout<<" ";
					
				}
				cout<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}