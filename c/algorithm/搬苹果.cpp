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
	int y,k,n;
	while(cin>>y>>k>>n)
	{
		vector<int> v;
		v.clear();
		int i,sum,flag=1,count=0;
		for(i=0;i<=100;i++)
		{
			sum=i*k-y;
			if(sum<=0)
				continue;
			if(sum+y>n)
				break;
			v.push_back(sum);
		}
		if(v.size()==0)
		{
			cout<<-1<<endl;
			continue;
		}
		sort(v.begin(),v.end(),comp);
		for(int i=0;i<v.size();i++)
		{
			if(i!=v.size()-1)
				cout<<v[i]<<" ";
			else
				cout<<v[i]<<endl;
		}
	}
	return 0;
} 