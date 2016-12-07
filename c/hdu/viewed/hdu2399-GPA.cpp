#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
/*
	已经分段A(4),B(3),C(2),D(1),F(0),其他为无效字符,求平均GPA
*/
int getValue(char ch) {
	switch(ch) {
		case 'A':
		case 'a': return 4;
		
		case 'B':
		case 'b': return 3;
		
		case 'C':
		case 'c': return 2;
		
		case 'D':
		case 'd': return 1;
		
		case 'F':
		case 'f': return 0;
	}
	
	return -1;
}
bool isGPA(char ch) {
	
	if(ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'F') {
		return true;
	}
	return false;
}
void test() {
	string s = "";
	// gets a line save in string s
	while(getline(cin, s)) {
		int length = s.size();
		double sum = 0.0;
		int n = 0;
		bool flag = true;
		for(int i = 0; i < length; i++) {
			if(s[i] != ' ') {
				if(isGPA(s[i])) {
					n++;
					sum += getValue(s[i]);
				} else {
					flag = false;
					break;
				}
			}
		}
		if(flag) {
			printf("%.2lf\n", sum / n);
		} else {
			cout << "Unknown letter grade in input" << endl;
		}
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
A B C D F
B F F C C A
D C E F

Sample Output
2.00
1.83
Unknown letter grade in input
*/