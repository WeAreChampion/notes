#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int a[1000],b,i,j;
		vector<int> v;
		v.clear();
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b;
			int c=b;
			for(j=0;j<n;j++)
			{
				c=c+a[j];
				v.push_back(c);
				c=b;
			}
		}
		sort(v.begin(),v.end(),comp);
		for(i=k-1;i>=1;i--)
		{
			cout<<v[i]<<" ";
		}
		cout<<v[i]<<endl;
	}
	return 0;
} 