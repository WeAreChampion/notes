#include<iostream>
using namespace std;
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int n;
		cin>>n;
		double sum1=0,sum2=0;
		int flag=1;
		char a[50];
		double score,degree;
		for(int i=0;i<n;i++)
		{
			cin>>a>>degree>>score;
			if(score<60)
			{
				flag=0;
			}
			else
			{
				sum1+=degree;
				sum2+=degree*score;
			}
		}
		if(flag)
		{
			printf("%.2lf\n",sum2/sum1);
		}
		else
		{
			cout<<"Sorry!"<<endl;
		}
		if(ca!=0)
		{
			cout<<endl;
		}
	}
	return 0;
}