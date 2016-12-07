#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool comp(string a,string b)
{
	string s1="",s2="";
	s1=a+b,s2=b+a;
	int i,t=s1.length();
	for(i=0;i<t;i++)
	{
		if(s1[i]-'0'==s2[i]-'0')
			continue; 
		if(s1[i]-'0'>s2[i]-'0')
			return false;
		else
			return true;
	}
	return true;
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		int i;
		string s;
		vector<string> v;
		v.clear();
		for(i=0;i<n;i++)
		{
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(),v.end(),comp);//
		for(i=0;i<n;i++)
		{
			cout<<v[i]; 
		}
		cout<<endl;
	}
	return 0;
}
/*

bool Comp(string a,string b)
{
	if(a.length()<b.length())
	{
		string s=a;
		a=b;
		b=s;
	}
	int i,j;
	for(i=0,j=0;i<a.length()&&j<b.length();i++,j++)
	{
		if(a[i]-'0'>b[j]-'0')
		{
			return false;
		}
		else
			return true;
	}
	if(j==b.length())
	{
		j=0;
		while(i<a.length())
		{
			if(a[i]-'0'<b[j]-'0')
			{
				return false;
			}
			else 
				return true;
			i++;
			j++;
		}
	}
	return false;
}
*/

