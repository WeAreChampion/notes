#include<iostream>
using namespace std;
/*
	判断一个数的奇偶性.返回1，为奇数;返回0，为偶数
*/
bool isOdd(int num)
{
	return num & 0x1 == 1;
}
void test() {
	cout << isOdd(1) << endl;
	cout << isOdd(0) << endl;
	cout << isOdd(2) << endl;
	cout << isOdd(3) << endl;
}
int main() {
	test();
	return 0;
}