#include<iostream>
using namespace std;
int f(int n)
{
	int count=0;
	while(n!=1)
	{
		if(n%2==0)
		{
			n=n/2;
		}
		else
		{
			n=3*n+1;
		}
		count++;
	}
	return count+1;
}
int main()
{
	int i,j;
	while(cin>>i>>j)
	{
		int n=i,nn=j;
		if(i>j)
		{
			int temp=j;
			j=i;
			i=temp;
		}
		int max=0;
		for(int ii=i;ii<=j;ii++)
		{
			int m=f(ii);
			if(m>max)
				max=m;
		}
		cout<<n<<" "<<nn<<" "<<max<<endl;
	}
	return 0;
}