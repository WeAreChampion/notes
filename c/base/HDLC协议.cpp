#include<iostream>
using namespace std;
#include<string>
/*
	HDLC Protocol: If there are continual 1 then add one 0. 
	连续5个1，添加一个0
*/
string HDLC(const string str) {
	int length = str.size();
	int count = 0;
	string s = "";
	for(int i = 0; i < length; i++) {
		if(str[i] == '1') {
			count++;
		} else {
			count = 0;
		}
		s += str[i];
		//If there are continual five 1 then add one 0
		if(count == 5) {
			s += '0';
			count = 0;
		}
	}
	return s;
}
/*
	连续5个1，删除一个0
*/
string RHDLC(const string str) 
{
	int length = str.size();
	int count = 0;
	string s = "";
	for(int i = 0; i < length; i++) {
		if(str[i] == '1') {
			count++;
		} else {
			count = 0;
		}
		s += str[i];
		//If there are continual five 1 to delete one 0
		if(count == 5) {
			i++;
			count = 0;
		}
	}
	return s;
}
void testHDLC() {
	string str = "0101011111101";
	cout << HDLC(str) << endl;
}
void testRHDLC() {
	string str = "01010111110101";
	cout << RHDLC(str) << endl;
}
int main()
{
//	testHDLC();
	testRHDLC();
	return 0;
}