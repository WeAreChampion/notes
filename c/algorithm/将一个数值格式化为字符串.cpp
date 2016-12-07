#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;
int main()
{
	stringstream ss;
	ss<<"There are "<<9<<" apples in my cart.";
	cout<<ss.str()<<endl;//stringstream::str() return a string
	//with the contents
	ss.str("");//empty the string
	//16进制 
	ss<<showbase<<hex<<16;//show the base in hexadecimal
	cout<<"ss = "<<ss.str()<<endl;//output the string
	ss.str("");//empty the string
	//10进制 
	ss<<3.14;
	cout<<"ss = "<<ss.str()<<endl;
	return 0;
} 