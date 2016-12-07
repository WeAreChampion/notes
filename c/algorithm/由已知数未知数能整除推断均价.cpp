#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct Info
{
	int first;
	int last;
	int average;
};
bool comp(const Info a,const Info b)//sort big to small
{
	if(a.average!=b.average)
	{
		return a.average>b.average;
	}
}
int main()
{
	int i,j,n,x,y,z,m,ca;
	Info info;
	vector<Info> v;
	cin>>ca;
	while(ca--)
	{
		cin>>n;
		cin>>x>>y>>z;
		v.clear();
		m=x*1000+100*y+10*z;
		for(i=1;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				if((i*10000+m+j)%n==0)
				{
					info.first=i;
					info.last=j;
					info.average=(i*10000+m+j)/n;
					v.push_back(info);
				}
			}
		}
		sort(v.begin(),v.end(),comp);
		if(v.size()==0)
		{
			cout<<"0"<<endl;
		}
		else
		{
			cout<<v[0].first<<" "<<v[0].last<<" "<<v[0].average<<endl;
		}
	}
	return 0;
}
/*
ca
N
X Y Z
$_XYZ_,Çó_µÄÖµ 
3
72 
6 7 9
5
2 3 7
78
0 0 5
output:
3 2 511
9 5 18475
0
*/