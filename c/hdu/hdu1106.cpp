#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool Comp(string s1,string s2)
{
	if(s1.length ()!=s2.length ())
		return s1.length ()<s2.length ();
	else
		return s1<s2;
}
string delZero(string s)
{
	string str;
	for(int i=0;i<s.size ()-1;i++)
		if(s[i]!='0')
			break;
	for(int j=i;j<s.size ();j++)
		str+=s[j];
	return str;
}
int main()
{
	string s,str;
	vector<string> v;
	int i;
	while(cin>>s)
	{
		str="";
		for(i=0;i<s.size();i++)
		{
			if(s[i]!='5')
				str+=s[i];
			else
			{
				if(str!="")
					v.push_back(str);
				str="";
			}
		}
		if(str!="")
			v.push_back (str);
		for(i=0;i<v.size ();i++)
		{
			v[i]=delZero(v[i]);
		}
		sort(v.begin (),v.end (),Comp);
		for(i=0;i<v.size ();i++)
		{
			if(i!=v.size ()-1)
				cout<<v[i]<<" ";
			else
				cout<<v[i]<<endl;
		}
		v.clear ();
	}
	return 0;
}		/*
		for(i=0;i<v.size ();i++)
		{
			cout<<v[i]<<endl;
		}
		*/
		//cout<<v.size ()<<endl;
		//cout<<s<<endl;
		/*
		for(i=0;i<v.size ();i++)
		{
			if(i!=v.size ()-1)
				cout<<v[i]<<" ";
			else
				cout<<v[i]<<endl;
		}
		*/