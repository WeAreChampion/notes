#include<iostream>
#include<string>
using namespace std;
string s="";
int f(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return 1;
	else 
		return 0;
}
int f1()
{
	if((s.find("a")>s.size())&&(s.find("e")>s.size())&&(s.find("i")>s.size())&&(s.find("o")>s.size())&&(s.find("u")>s.size()))
		return 0;
	return 1;
}
int f2()
{
	for(int i=0;i<s.length()-1&&s.length()>1;i++)
	{
		if((s[i]==s[i+1])&&s[i]!='e'&&s[i]!='o')
			return 0;
	}
	return 1;
}
int f3()
{
	for(int i=0;i<s.length()-2&&s.length()>2;i++)
	{
		if((f(s[i])&&f(s[i+1])&&f(s[i+2]))||(!f(s[i])&&!f(s[i+1])&&!f(s[i+2])))
			return 0;
	}
	return 1;
}
int main()
{
	while(cin>>s&&s!="end")
	{
		if(f1()&&f2()&&f3())
			cout<<"<"<<s<<"> is acceptable."<<endl;
		else
			cout<<"<"<<s<<"> is not acceptable."<<endl;
	}
	return 0;
}