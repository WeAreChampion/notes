#include<iostream>
#include<string>
using namespace std;
#include<cstdlib>
//change the string to in or float
long hex2int(const string &hexStr)
{
	char *offset;
	if(hexStr.length()>2)
	{
		if(hexStr[0]=='0'&&hexStr[1]=='x')
		{
			return strtol(hexStr.c_str(),&offset,0);
		}
	}
	return strtol(hexStr.c_str(),&offset,16);
}
int main()
{
	string str1="0x12AB";	//16进制数 
	cout<<hex2int(str1)<<endl;
	string str2="12AB";		//16进制数 
	cout<<hex2int(str2)<<endl;
	string str3="QAFG";		//非法的16进制数 
	cout<<hex2int(str3)<<endl;
	return 0;
} 
/*
output:
4779
4779
0
*/