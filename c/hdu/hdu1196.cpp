#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[121],n,i,k;
	while(cin>>n&&n)
	{
		k=0;
		while(n!=0)
		{
			a[k]=n%2;
			n=n/2;
			if(a[k]==1)
			{
				cout<<pow(2,k)<<endl;
				break;
			}
			k++;
		}
	}
	return 0;
}