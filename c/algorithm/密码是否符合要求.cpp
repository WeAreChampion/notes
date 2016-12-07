#include<iostream>
using namespace std;
#include<string>
int check(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		return 1;
	return 0;
}
int check1(string s)//´æÔÚa,e,i,o,u 
{
	for(int i=0;i<s.size();i++)
	{
		if(check(s[i]))
			return 1;
	}
	return 0;
}
int check2(string s)
{
	if(s.size()<3)
		return 1;
	for(int i=0;i<s.size()-2;i++)
	{
		if((check(s[i])&&check(s[i+1])&&check(s[i+2]))||
		((!check(s[i]))&&(!check(s[i+1]))&&(!check(s[i+2]))))
			return 0;
	}
	return 1;
}
int check3(string s)
{
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]==s[i+1]&&s[i]!='e'&&s[i]!='o')
		{
			return 0;
		}
	}
	return 1;
}
int main() 
{
	string s;
	while(cin>>s)
	{
		if(s=="end")
			break;
		cout<<check1(s)<<" "<<check2(s)<<" "<<check3(s)<<endl;
		if(check1(s)&&check2(s)&&check3(s))
		{
			cout<<"<"<<s<<"> is acceptable.\n";
		}
		else
			cout<<"<"<<s<<"> is not acceptable.\n";
	}
	return 0;
}
/*
a
tv
ptaui
bontres
zoggax
wiinq
eep
houctuh
end
*/