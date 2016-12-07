#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> v3;
int f(vector<string> v,string s)
{
	int k;
	for(k=0;k<10;k++)
	{
		if(v[k]==s)
		{
			return k;
		}
	}
}
void Disp(vector<string> v,int k)
{
	string s=v[k];
	for(int i=0;i<35;i++)
	{
		cout<<s[i];
		if((i+1)%5==0)
		{
			cout<<endl;
		}
	}
}
void disp(vector<string> v,int k1,int k2)
{
	string s1=v[k1],s2=v[k2],s;
	int count=0;
	for(int i=0;i<35;i=i+5)
	{
		for(count=i;count<i+5;count++)
		{
			cout<<s1[count];
		}
		for(count=i;count<i+5;count++)
		{
			cout<<s2[count];
		}
		cout<<endl;
	}
}
int main()
{
	string ss="";
	v3.clear();
	ss="******888**8*8**8*8**8*8**888******";
	v3.push_back(ss);
	ss="*******8***88****8****8***888******";
	v3.push_back(ss);
	ss="******888****8**888**8****888******";
	v3.push_back(ss);
	ss="******888****8**888****8**888******";
	v3.push_back(ss);
	ss="******8*8**8*8**888****8****8******";
	v3.push_back(ss);
	ss="******888**8****888****8**888******";
	v3.push_back(ss);
	ss="******888**8****888**8*8**888******";
	v3.push_back(ss);
	ss="******888****8****8****8****8******";
	v3.push_back(ss);
	ss="******888**8*8**888**8*8**888******";
	v3.push_back(ss);
	ss="******888**8*8**888****8**888******";
	v3.push_back(ss);
	int i,j,k;
	int ca;
	cin>>ca;
	while(ca--)
	{
		string s="",str1="",str2="";
		for(i=0;i<7;i++)
		{
			cin>>s;
			str1+=s;
		}
		int k1=f(v3,str1);
		for(i=0;i<7;i++)
		{
			cin>>s;
			str2+=s;
		}
		int k2=f(v3,str2);
		//cout<<k1<<" "<<k2<<endl;
		int sum=k1*k2;
		if(sum<10)
		{
			Disp(v3,sum);
		}
		else
		{
			int k3=sum%10,k4=sum/10;
			disp(v3,k4,k3);
		}
		if(ca!=0)
		{
			cout<<endl;
		}
	}
	return 0;
}