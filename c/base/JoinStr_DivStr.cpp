#include<iostream>
#include<string>
using namespace std;
#define STRING_MAX_SIZE 20
string joinString(string array[], int length, char joinChar)
{
	string str="";
	for(int i = 0; i < length - 1; i++) {
		str += array[i];
		str += joinChar;
	}
	str += array[length-1];
	return str;
}
string stringArray[STRING_MAX_SIZE];
int String_Array_Size = 0;
void divideString(string str, char divideChar)
{
	string newStr = "";
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != divideChar) {
			newStr += str[i];
		} else if(newStr != "") {
			stringArray[String_Array_Size++] = newStr;
			newStr = "";
		}
	}
	if(newStr != "") {
		stringArray[String_Array_Size++] = newStr;
	}
}
void DispStringArray()
{
	for(int i=0; i<String_Array_Size; i++) {
		cout<<stringArray[i]<<endl;
	}
}
void TestJoin()
{
	string str[3];
	str[0]="I";
	str[1]="love";
	str[2]="you";
	cout<<joinString(str,3,' ')<<endl;
	cout<<joinString(str,3,'-')<<endl;
}
void TestDivide()
{
	string str="I love you!";
	divideString(str,' ');
	DispStringArray();
}
void Test()
{
	TestJoin();
	TestDivide();
}
int main()
{
	Test();
	return 0;
}