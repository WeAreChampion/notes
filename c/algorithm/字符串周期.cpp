#include<iostream>
#include<string>
using namespace std;
/**
	获取字符串的最小周期
*/
int geMinT(string str)
{
	int length = str.size();
	int i, j;

	// i 为周期
	for(i = 1; i <= length; i++) {

		// 可以以i为周期的条件是可以整除length
		if(length % i == 0) {
			bool ok = true;

			// j ->周期i时的位置，因为string从0开始存储
			for(j = i; j < length; j++) {
				// 若以i为周期，则对i取余相等
				if(str[j] != str[j % i]) {
					ok = false;
					break;
				}
			}
			// 返回最小周期
			if(ok) {
				return i;
			}
		}
	}
}
/**
	判断字符串的周期是否为T
*/
bool isCircleT(string str, int T)
{
	int length = str.size();
	int j;
	
	// 可以以T为周期的条件是可以整除length
	if(length % T == 0) {
		bool ok = true;

		// j ->周期T时的位置，因为string从0开始存储
		for(j = T; j < length; j++) {
			// 若以T为周期，则对T取余相等
			if(str[j] != str[j % T]) {
				ok = false;
				break;
			}
		}
		return ok;
	}
	return false;
}
void testIsCircleT() {
	cout << isCircleT("HOHOHO", 2) << endl;
	cout << isCircleT("HOHOHO", 3) << endl;
	cout << isCircleT("HHHHHH", 2) << endl;
	cout << isCircleT("HHHHHH", 3) << endl;
	cout << isCircleT("HHHHHH", 4) << endl;
	cout << isCircleT("HHHHHH", 6) << endl;
}
void test()
{
	string str = "";
	while(cin >> str) {
		cout << "min T = " << geMinT(str) << endl;
	}
}
int main()
{
	testIsCircleT();
	test();
	return 0;
}
/**
Input:
HoHoHo

Output:
2

*/