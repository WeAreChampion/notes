#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int q;
		double y,e,f,g,sum;
		cin>>y>>q>>e>>f>>g;
		sum=y*(1+(q*e*1.0/100/365));
		//cout<<sum*(1+g*1.0/100)<<endl;
		printf("%.1lf\n",sum*(1+g*1.0/100));
		printf("%.1lf\n",y*(1+f*1.0/100*(q+365)/365));
		//cout<<y*(1+f*1.0/100*(q+365)/365)<<endl;
	}
	return 0;
}