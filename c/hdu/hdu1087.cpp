//求最大子序列和并且是从小到大排序的子序列
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n)
	{
		int sum,i,j,max=0,aa;
		vector<int> a;
		for(i=0;i<n;i++)
		{
			cin>>aa;
			a.push_back(aa);
		}
		for(i=0;i<n-1;i++)
		{
			sum=a[i];
			for(j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
				{
					sum+=a[j];
					i=j;
				}
				else
				{
					j++;
					break;
				}
			}
			if(max<sum)
				max=sum;
		}

		cout<<max<<endl;
		a.clear();
	}
	return 0;
}
*///11 1 11 2 3 4 5 6 7 8 9 10
/*		reverse(a.begin(),a.end());
		for(i=0;i<n-1;i++)
		{
			sum=a[i];
			for(j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
				{
					sum+=a[j];
					i=j;
				}
				else
				{
					flag=0;
					break;
				}
			}
			if(max<sum)
				max=sum;
		}
*/

#include<iostream>
using namespace std;
int main()
{
	int a[1010],t,sum,s[1010],max;
	int i,n,b,k;
	while(cin>>n&&n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		a[0] = 0;
		s[0] = 0;
		for(i=1;i<=n;i++)
		{
			s[i] = a[i];
			for(t=i-1;t>=0;t--)
			{//从后往前找比当前小的数 ,且和要比当前存储的要大
				if(a[t] < a[i]&& s[t] + a[i] > s[i])
				{
					s[i] = s[t] + a[i];
				}
			}
		}
		max=0;
		for(i=1;i<=n;i++)
			if(s[i]>max)
			{
				max = s[i];
			}
		cout<<max<<endl;
	}
	return 0;
}
