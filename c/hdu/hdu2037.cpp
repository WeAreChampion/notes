//	for(i=0;i<n;i++)
//		cout<<a[i]<<" "<<b[i]<<endl;
#include<iostream>	
using namespace std;
int main()
{
	int n,a[120],b[120],i,j,t;
	while(cin>>n&&n)
	{
		for(i=0;i<n;i++)
			cin>>a[i]>>b[i];
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(b[i]>b[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
					t=b[i];
					b[i]=b[j];
					b[j]=t;
				}
			}
		}

		int count=1,flag;
		for(i=0;i<n-1;i++)
		{
			flag=1;
			for(j=i+1;j<n&&flag!=0;j++)
				if(b[i]<=a[j])
				{
					count++;
					i=j-1;
					flag=0;
				}
		}
		cout<<count<<endl;
	}
	return 0;
}
/*
贪心算法，先考虑目前最优，而后考虑后面，
按结束时间排序，而后依次遍历
*/
