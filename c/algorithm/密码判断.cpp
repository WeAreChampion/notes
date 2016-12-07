#include<iostream>
using namespace std;
/**
	判断长度
*/
bool judgeLength(char *ch)
{
	if(strlen(ch) >= 8 && strlen(ch) <= 16) {
		return true;
	}
	return false;
}
/**
	判断是否含大写字母
*/
bool judgeBig(char ch)
{
	if(ch >= 'A' && ch <= 'Z') {
		return true;
	}
	return false;
}
/**
	判断是否含小写字母
*/
bool judgeSmall(char ch)
{
	if(ch >= 'a' && ch <= 'z') {
		return true;
	}
	return false;
}
/**
	判断是否含数字
*/
bool judgeNumber(char ch)
{
	if(ch >= '0' && ch <= '9') {
		return true;
	}
	return false;
}
int main()
{
	int ca;
	cin >> ca;
	while(ca--) {
		int a[4] = {0};
		char ch[20];
		cin >> ch;
		//	cout<<ch<<endl;
		if(judgeLength(ch)) {
			for(int i = 0; i < strlen(ch); i++) {
				if(judgeSmall(ch[i])) {
					a[0] = 1;
				} else if(judgeBig(ch[i])) {
					a[1] = 1;
				} else if(judgeNumber(ch[i])) {
					a[2] = 1;
				} else {
					a[3] = 1;
				}
			}
			int sum = 0;
			for(int j = 0; j < 4; j++) {
				sum += a[j];
			}
			if(sum >= 3) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}