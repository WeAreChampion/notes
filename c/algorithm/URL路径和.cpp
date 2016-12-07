#include<iostream>
#include<string>
using namespace std;
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int n,mod_old,mod_even,i;
		cin>>n>>mod_old>>mod_even;
		for(i=0;i<n;i++)
		{
			int j,sum_old=0,sum_even=0;
			string s;
			cin>>s;
			for(j=0;j<s.length();j++)
			{
				if(s[j]>=48&&s[j]<=122)
				{
					if(j%2==1)
					{
						sum_old=sum_old+s[j];
					}
					else
					{
						sum_even=sum_even+s[j];
					}
				}
			}
			cout<<"("<<sum_old%mod_old+sum_even%mod_even<<","<<sum_even+sum_old<<")"<<endl;
		}
	}
	return 0;
}