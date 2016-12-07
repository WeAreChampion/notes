#include<iostream>
using namespace std;
//delete the ' ' from the string where start and ending
string trim(string str)
{
	string newStr = "";
	int start;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != ' ') {
			start = i;
			break;
		}
	}
	int end;
	for(int i = str.size() - 1; i >= 0; i--) {
		if(str[i] != ' ') {
			end = i;
			break;
		}
	}
	for(int i = start; i <= end; i++) {
		newStr += str[i];
	}
	return newStr;
} 
void TestTrim()
{
	string s = "  aa av b  ";
	string news = trim(s);
	cout<<news.size()<<endl<<news<<endl;
}
string string1 = "S¡úaU|bV";
//the char is lower like 'a','b'...'z'
bool isLower(char ch)
{
	if(ch >= 'a' && ch <= 'z') {
		return true;
	}
	return false;
}
//the char is Uper like 'A','B'...'Z'
bool isUper(char ch)
{
	if(ch >= 'A' && ch <= 'Z') {
		return true;
	}
	return false;
}
void TestChar()
{
	char ch;
	cout<<"Please type a word: ";
	while(cin>>ch) {
		if(isUper(ch)) { 
			cout<<ch<<" is upper!"<<endl;
		} 
		else if(isLower(ch)) { 
			cout<<ch<<" is lower!"<<endl;
		} 
		else { 
			cout<<ch<<" is not word!"<<endl;
		} 
		getchar();
		cout<<"Please type a word: ";
	} 
}
int main()
{
	TestChar();
	return 0;
}