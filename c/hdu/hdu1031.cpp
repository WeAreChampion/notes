#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Info
{
	int pos;
	float s;
};
bool myComp(Info a , Info b)
{
	if(a.s != b.s)
		return a.s > b.s;
	else
		return a.pos < b.pos;
}
bool Comp(Info a , Info b)
{
	return a.pos > b.pos;
}
Info info[10000];
int main()
{
	float a;
	int n,m,k;
	vector<Info> v;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		v.clear();
		int i,j;
		for(j=0;j<m;j++)
		{
			info[j].s=0;
			info[j].pos =j+1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%f",&a);
				info[j].s+= a;
			}
		}
		for(j=0;j<m;j++)
			v.push_back (info[j]);
		sort(v.begin(),v.end(),myComp);
		sort(v.begin (),v.begin ()+k,Comp);
		for(j=0;j<k-1;j++)
		{
			printf("%d ",v[j].pos);
		}
		printf("%d\n",v[j].pos);
	}
	return 0;
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Info
{
	int pos;
	float s;
};
bool myComp(Info a , Info b)
{
	if(a.s != b.s)
		return a.s > b.s;
	else
		return a.pos < b.pos;
}
bool Comp(Info a , Info b)
{
	return a.pos > b.pos;
}
int main()
{
	string s;
	float a[1000][100];
	int n,m,k;
	Info info;
	vector<Info> v;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		v.clear();
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%f",&a[i][j]);
			}
		}
		for(j=0;j<m;j++)
		{
			float sum=0;
			for(i=0;i<n;i++)
			{
				sum=sum+a[i][j];
			}
			info.pos=j;
			info.s=sum;
			v.push_back(info);
		}
		sort(v.begin(),v.end(),myComp);
		sort(v.begin (),v.begin ()+k,Comp);
		for(j=0;j<k-1;j++)
		{
			printf("%d ",v[j].pos+1);
		}
		printf("%d\n",v[j].pos+1);
	}
	return 0;
}
*/