#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
void reverseStr(string &s) {
	int length = s.size();
	int counts = length / 2;
	for(int i = 0; i < counts; i++) {
		char ch = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = ch;
	}
}
void test() {
	int ca;
	cin >> ca;
	string s;
	getchar();
	while(ca--) {
		char ch;
		s = "";
		while((ch = getchar()) != '\n') {
			if(ch == ' ') {// is space
				if(s != "") {
					reverseStr(s);
					cout << s << ch;
				} else {
					cout << ch;
				}
				s = "";
			} else {//not space
				s += ch;
			}
		}
		if(s != "") {
			reverseStr(s);
		}
		cout << s << endl;
	}
}
int main() {
	test();
	return 0;
}