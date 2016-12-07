#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>
using namespace std;
/*
	To get logN / log2,该方法会导致错误答案，因为是估算
*/
int getLog2N_2(int n) {
	double value = log((double) n) / log(2.0);
	return ceil(value);
}
/**
	获得十进制数对2取对数的值，移位方法
*/
int getLog2N(int n) {
	int m = 0;
	while(n) {
		m++;
		
		//右移一位
		n = n >> 1;
	}
	return m;
}
/*
	convert string to (m) int
*/
int convert2Int(string s, int m) {
	int length = s.size();
	int sum = 0;
	int k = 1;
	for(int i = length - 1; i >= 0; i--) {
		sum += (s[i] - '0') * k;
		k = k * m;
	}
	return sum;
}
/*
	convert ten string to int
*/
int convertTen2Int(string s) {
	return convert2Int(s, 10);
}
/*
	convert binary string to (2) int
*/
int convertBinary2Int(string s) {
	return convert2Int(s, 2);
}
/*
	To reverse the string
*/
void reverse2String(string &s) {
	int length = s.size();
	int times = length  / 2;
	for(int i = 0; i < times; i++) {
		char ch = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = ch;
	}
}
/*
	convert (10) value to string
*/
string convert2String(int n) {
	string s = "";
	int value = n;
	while(value) {
		int result = value % 10;
		char ch = result + '0';
		s += ch;
		value = value / 10;
	}
	if(s == "") {
		return "0";
	}
	reverse2String(s);
	return s;
}
/*
	convert the string to ip adress
*/
string convert2IP(string s) {
	string newStr = "";
	string s1 = s.substr(0, 8);
	//cout << "s1 = " << s1 << endl;
	newStr += convert2String(convert2Int(s1, 2));
	newStr += ".";
	s1 = s.substr(8, 8);
	//cout << "s1 = " << s1 << endl;
	newStr += convert2String(convert2Int(s1, 2));
	newStr += ".";
	s1 = s.substr(16, 8);
	//cout << "s1 = " << s1 << endl;
	newStr += convert2String(convert2Int(s1, 2));
	newStr += ".";
	s1 = s.substr(24, 8);
	//cout << "s1 = " << s1 << endl;
	newStr += convert2String(convert2Int(s1, 2));
	return newStr;
}
void test() {
	int n;
	while(scanf("%d", &n) != EOF) {
		// 连续1的个数
		int continue1Counts = getLog2N(n + 2);
		//cout << "continue1Counts = " << continue1Counts <<endl;
		string s = "";
		int i;
		for(i = 0; i < 32 - continue1Counts; i++) {
			s += '1';
		}
		
		//低位补0
		for(i = 0; i < continue1Counts; i++) {
			s += '0';
		}
		
		//cout << "s = " << s << endl;
		cout << convert2IP(s) << endl;
	}
}
int main() {
	test();
	return 0;
}
/*

Sample Input
10
 

Sample Output
255.255.255.240
*/