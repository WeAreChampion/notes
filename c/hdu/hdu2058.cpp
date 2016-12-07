#include<iostream>
#include<cmath>
using namespace std;
void disp(int start,int end)
{
	cout<<"["<<start<<","<<end<<"]"<<endl;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
		{
			break;
		}
		int k=(int)sqrt((double)(2*m)),i;
		for(i=k;i>=1;i--)
		{
			if(i%2==0)
			{
				if(m%(m/i+m/i+1)==0)
				{
					disp(m/i-i/2+1,m/i+i/2);
				}
			}
			else
			{
				if(m%i==0)
				{
					disp(m/i-i/2,m/i+i/2);
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 