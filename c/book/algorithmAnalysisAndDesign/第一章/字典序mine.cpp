#include<iostream>
#include<string>
using namespace std;
/**
	To get the char value
*/
int getCharValue(char ch) {
	return ch - 'a' + 1;
}
/**
	To get the dictionary code by string s
	获得字典序中的编码，从1开始，以26为周期类似于
	字符串转换为整数
*/
int getDictionaryCode(string s) {
	int length = s.size() - 1;
	int sum = 0;
	int k = 1;
	for(int i = length; i >= 0; i--) {
		sum += getCharValue(s[i]) * k;
		k = k * 26;
	}
	return sum;
}
void testGetDictionaryCode() {
	int ca;
	cin >> ca;
	while(ca--) {
		string s;
		cin >> s;
		
		cout << getDictionaryCode(s) << endl;
	}
}
int main() {
	testGetDictionaryCode();
	return 0;
}
/**
Input:
2
a
b

Output:
1
2
*/