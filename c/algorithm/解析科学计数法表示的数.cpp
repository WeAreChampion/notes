#include<iostream>
#include<string>
#include<sstream>
using namespace std;
double sciToDub(const string& str)
{
	stringstream ss(str);
	double d=0;
	ss>>d;
	if(ss.fail())//����ʧ�� 
	{
		string s="Unable to format ";
		s+=str;
		s+=" as a number!";
		throw(s);//�׳��쳣 
	}
	return (d);//���ؽ���ֵ 
}
int main()
{
	try
	{
		cout<<sciToDub("1.234e5")<<endl;
		cout<<sciToDub("6.02e-2")<<endl;
		cout<<sciToDub("asdf")<<endl;
	}catch(string& e)//����쳣 
	{
		cerr<<"Whoops: "<<e<<endl;
	}
	return 0;
}