#include<iostream>
using namespace std;
#include<string>
bool isReverseStr(string str)
{
	int length = str.size();
	if(length == 0 || length == 1) {
		return true;
	}
	int len = length / 2;
	for(int i = 0; i < len; i++) {
		if(str[i] != str[length - i - 1]) {
			return false;
		}
	}
	return true;
}
void testIsReverseStr()
{
	cout << isReverseStr("aaa") << endl;
	cout << isReverseStr("aba") << endl;
	cout << isReverseStr("baa") << endl;
	cout << isReverseStr("abb") << endl;
}
int main()
{
	testIsReverseStr(); 
	return 0;
}