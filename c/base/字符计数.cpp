#include<iostream>
#include<string>
using namespace std;
int main()
{
	char ch;
	string s = "";
	int sum = 0, i = 0;
	while((ch = getchar()) != '#') {
		i++;
		if(ch != '\n') {
			if(ch >= 'A' && ch <= 'Z'){ 
				sum += i * (ch - 64);
			} 
			if(ch >= 'a' && ch<='z') { 
				sum += i * (ch - 96);
			} 
		} else {
			cout<<sum<<endl;
			i = 0;
			sum = 0;
		}
	}
	return 0;
}
/*
ACM
MID CENTRAL
A C M
#
*/