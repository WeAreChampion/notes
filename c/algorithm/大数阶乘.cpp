#include<iostream>
#include<cmath>
using namespace std;
void factorial(int n)//int
{
	long a[10000];
	int i,j,c,m=0;//,w
	a[0]=1;
	for(i=1;i<=n;i++)
	{
		c=0;						//进位标志
		for(j=0;j<=m;j++)
		{
			a[j]=a[j]*i+c;			//处理进位
			c=a[j]/10000;			
			a[j]=a[j]%10000;
		}
		if(c>0)
		{
			m++;
			a[m]=c;//进位c
		}
	}
//	w=m*4+log10(a[m])+1;
	printf("%ld",a[m]);//output最高位
	for(i=m-1;i>=0;i--)
		printf("%4.4ld",a[i]);
//	return w;
}
int main()
{
	int n;
	while(cin>>n)
	{
		factorial(n);
		cout<<endl;
	}
	return 0;
}
