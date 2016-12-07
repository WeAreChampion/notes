#include<iostream>
using namespace std;
/*
	快速清0
*/
void resetWithZero(int &a) {
	a = a & 0x0;
}
void testResetWithZero() {
	int a = 10;
	cout << "a = " << a << endl;
	
	resetWithZero(a);
	cout << "a = " << a << endl;
}
/*
	获取数据的指定位，低8位
*/
int getLow8(int m) {
	return m & 0xFF;
}
void testGetLow8() {
	int m = 1034;
	cout << "1034 low 8 bits are : " << getLow8(m) << endl;
}
/*
	获取数据的指定位，高8位
*/
int getHigh8(int m) {
	return m & 0xFF00;
}
void testGetHigh8() {
	int m = 101034;
	cout << "101034 high 8 bits are : " << getLow8(m) << endl;
}
void test() {
	testResetWithZero();
	testGetLow8();
	testGetHigh8();
}
int main() {
	test();
	return 0;
}