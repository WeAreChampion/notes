#include<iostream>//已知n,求解x^2+y^2+z^2=n中的x，y，z 
using namespace std;
void f(int n,int &x,int &y,int &z)
{
	for(int i=0;i<=100;i++)
	{
		for(int j=i;j<=100;j++)
		{
			for(int k=0;k<=10;k++)
				if((n-i*i-j*j)==(k*k))
				{
					x=i;
					y=j;
					z=k;
					return ;
				}
		}
	}
	return ;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int x,y,z;
		f(n,x,y,z);
		cout<<x<<" "<<y<<" "<<z<<endl;
	}
	return 0;
}