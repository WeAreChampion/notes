#include<iostream>
using namespace std;
string Trim(string str)//去除前导空格和末尾空格 
{
	string s="";
	int start,end,i;
	for(i=0;i<str.size();i++)
	{
		if(str[i]!=' ')
			break;
	}
	start=i;
	for(i=str.size()-1;i>=0;i--)
	{
		if(str[i]!=' ')
			break;
	}
	end=i;
	for(i=start;i<=end;i++)
	{
		s+=str[i];
	}
	return s;
}
int main()
{
	string s="  aa d  da  ";
	cout<<Trim(s);
	return 0;
}