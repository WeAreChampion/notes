#include<iostream>
using namespace std;
int main()
{
	int n;
	char a[205];
	while(scanf("%d",&n)!=EOF&&n)
	{
		cin>>a;
		char str[300][30];
		int i,j,l=strlen(a)/n,k;
		for(i=0;i<l;i++)
		{
			if(i%2==0)
			{
				k=i*n;
				for(j=0;j<n;j++)
				{
					str[i][j]=a[k];
					k++;
				}
			}
			else
			{
				k=(i+1)*n-1;
				for(j=0;j<n;j++)
				{
					str[i][j]=a[k];
					k--;
				}
			}
		}
		for(j=0;j<n;j++)
			for(i=0;i<l;i++)
				cout<<str[i][j];
		cout<<endl;
	}
	return 0;
}
