#include<iostream>
using namespace std;
int yu[1010]={0};
int in=0;
void f(int a,int b,int m)
{
	int j;
	in=a/b;
	a=a-b*in;
	for(j=1;j<=m+1;j++)
	{
		a=a*10;
		yu[j]=a/b;
		a=a-yu[j]*b;
	}
	if(yu[m+1]>=5)
	{
		yu[m]++;
		int i=m;
		while(yu[i]>=10)
		{
			if(i!=0)
			{
				yu[i]=yu[i]-10;
				yu[i-1]++;
			}
			i--;
			if(i==0)
				break;
		}
	}
}
int main()
{
	int a,b,m;
	while(scanf("%d%d%d",&a,&b,&m)!=EOF)
	{
		int i;
		f(a,b,m);
		in=in+yu[0];
		if(m!=0)
			cout<<in<<".";
		else
			cout<<in;
		for(i=1;i<=m;i++)
		{
			cout<<yu[i];
		}
		cout<<endl;
		yu[0]=0;
	}
	return 0;
} 