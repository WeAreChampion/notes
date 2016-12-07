#include<iostream>
using namespace std;
int main()
{
	int ca;
	cin>>ca;
	getchar();
	while(ca--) {
		char ch, str;
		str = getchar();
		int count = 1;
		string s = "";
		while((ch = getchar()) != '\n') {
			if(str == ch) {
				count++;
			} else {
				if(count != 1){ 
					s += count + '0';
				} 
				s += str;
				str = ch;
				count = 1;
			}
		}
		if(count != 1) { 
			s += count + '0';
		} 
		s += str;
		cout<<s<<endl;
	}
	return 0;
}
/*
2
ABC
ABBCCC
out:
ABC
A2B3C 
*/