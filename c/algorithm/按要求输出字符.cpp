#include<iostream>
using namespace std;
int main()
{
	int i,j,m,n;
	char a[10000];
	while(cin>>m>>n)
	{
		for(i=2;i<2*n;i++)
		{
			if(j==1||j==2*m-1)
				a[i][j]='|';
			else
				a[i][j]=' ';
		}
		a[1][1]=a[1][2*m-1]=a[2*n][1]=a[2*n][2*m-1]='+';
		for(j=2;j<2*m-1;j++)
			if(i==1||i==2*n)
				a[i][j]='-';
		for(i=1;i<=2*n;i++)
		{
			for(j=1;j<=2*m-1;j++)
				cout<<a[i][j];
			cout<<endl;
		}
	}
	return 0;
}