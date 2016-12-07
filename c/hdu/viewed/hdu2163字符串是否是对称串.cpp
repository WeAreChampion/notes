#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s) {
	int length = s.size();
	int counts = length / 2;
	for(int i = 0; i < counts; i++) {
		if(s[i] != s[length - i - 1]) {
			return false;
		}
	}
	return true;
}
void test() {
	int ca = 0;
	string s = "";
	while(cin >> s) {
		if("STOP" == s) {
			break;
		}
		ca++;
		cout << "#" << ca << ": ";
		if(isPalindrome(s)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
ABCCBA
A
HELLO
ABAB
AMA
ABAB
PPA
STOP
 

Sample Output
#1: YES
#2: YES
#3: NO
#4: NO
#5: YES
#6: NO
#7: NO
*/