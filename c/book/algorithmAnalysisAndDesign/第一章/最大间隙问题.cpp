#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cmath>
bool comp(const double a,const double b)
{
	return a<b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int i;
		double k;
		vector<double> v;
		v.clear();
		for(i=0;i<n;i++)
		{
			cin>>k;
			v.push_back(k);
		}
		sort(v.begin(),v.end(),comp);
		double minDis=3567.0,maxDis=0.0;
		for(i=1;i<n;i++)
		{
			double c=fabs(v[i-1]-v[i]);
			if(c<minDis)
			{
				minDis=c;
			}
			if(c>maxDis)
			{
				maxDis=c;
			}
		}
		cout<<"maxDis="<<maxDis<<endl;
		cout<<"minDis="<<minDis<<endl;
	}
	return 0;
} 
/*
5
2.3 3.1 7.5 1.5 6.3
*/