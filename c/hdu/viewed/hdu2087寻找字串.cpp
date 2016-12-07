#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int countsStr(string a, string b) {
	int bLength = b.size();
	int aLength = a.size();
	int counts = 0;
	string s = "";
	int j = 0;
	int i = 0;
	while(i < aLength) {
		if(a[i] == b[j]) {// is equal
			// b is the end
			if(j == bLength - 1) {
				j = 0;
				//i -> the next
				i++;
				counts++;
				//s += b[j];
				//cout << "s = " << s << endl;
				s = "";
			} else {// both get the next
				j++;
				i++;
				s += b[j];
			}
		} else {// not the equal then back
			j = 0;
			s = "";
			i = i - s.size() + 1;
		}
	}
	if(s.size() == b.size()) {
		counts++;
	}
	return counts;
}
int main() {
	string a = "";
	string b = "";
	while(true) {
		cin >> a;
		//find "#"
		if(a.find("#") != -1 && a[0] == '#') {
			break;
		}
		cin >> b;
		/*
		if(b.find("#") != -1) {	
			break;
		}
		*/
		cout << countsStr(a, b) << endl;
	}
	return 0;
}
/*
Sample Input
abcde a3
aaaaaa  aa
#

 

Sample Output

0
3


*/