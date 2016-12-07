#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(int a,int b)
{
	return a<b;
}
int f(int n,int m)//C(n,m)
{
	if(n<m)
		return 0;
	if(n==0||m==0||n==1)
		return 1;
	if(m==1)
		return n;
	double sum=1;
	for(int i=m;i>=1;i--)
	{
		sum*=(n-i+1)*1.0/i;
	}
	return ((int)sum);
}
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		vector<int> v;
		v.clear();
		if(n==0&&k==0)	break;
		int i,a;
		for(i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end(),comp);
		int sum=f(n,k)*k,count=1;
		a=v[0];
		for(i=1;i<n;i++)
		{
			if(a==v[i])
			{
				count++;
			}
			else
			{
				if(count>1)
				{
					sum-=f(count,k);
				}
				count=1;
				a=v[i];
			}
		}
		//cout<<f(n,k)<<endl;
	}
	return 0;
} 