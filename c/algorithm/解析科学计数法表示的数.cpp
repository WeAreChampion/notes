#include<iostream>
#include<string>
#include<sstream>
using namespace std;
double sciToDub(const string& str)
{
	stringstream ss(str);
	double d=0;
	ss>>d;
	if(ss.fail())//解析失败 
	{
		string s="Unable to format ";
		s+=str;
		s+=" as a number!";
		throw(s);//抛出异常 
	}
	return (d);//返回解析值 
}
int main()
{
	try
	{
		cout<<sciToDub("1.234e5")<<endl;
		cout<<sciToDub("6.02e-2")<<endl;
		cout<<sciToDub("asdf")<<endl;
	}catch(string& e)//输出异常 
	{
		cerr<<"Whoops: "<<e<<endl;
	}
	return 0;
}