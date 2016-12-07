#include<iostream>
#include<cmath>
using namespace std;
void f(int n,int &i,int &k)
{
	int m=(int)sqrt((double)n);
	if(m*m<n)
	{
		i=m+1;
		k=n-m*m;
	}
	else
	{
		i=m;
		k=2*i-1;
	}
}
int find(int ia,int ka,int ib,int kb)
{
	int sum=0;
	while(ia!=ib || ka!=kb)
	{
		if(ia==ib)
		{
			sum+=abs(ka-kb);
			break;
		}
		else
		{
			if(ka%2!=0)
			{
				ia++;
				ka++;
			}
			else
			{
				if(ka>=kb)
					ka--;
				else
					ka++;
			}
			sum++;
		}
	}
	return sum;
}
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int sum=0;
		if(m>n)
		{
			int t=m;
			m=n;
			n=t;
		}
		int ia,ib,ka,kb;
		f(m,ia,ka);
		f(n,ib,kb);
		cout<<find(ia,ka,ib,kb)<<endl;
	}
	return 0;
}