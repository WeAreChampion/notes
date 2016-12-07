#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k,m=0;
	char a,b;
	while(scanf("%c",&a)!=EOF)
	{
		if(a=='@') 
			break;	
		if(m)
			cout<<endl;
		scanf("%d",&n);
		m++;
		b=getchar();
		for(i=1;i<n;i++)
		{
			for(j=n-i;j>0;j--)
				cout<<" ";
			cout<<a;
			for(k=1;k<=2*(i-2)+1;k++)
				cout<<" ";
			if(i!=1)
				cout<<a;
			cout<<endl;
		}
		for(i=0;i<2*n-1;i++)
			cout<<a;
		cout<<endl;

	}
	return 0;
}