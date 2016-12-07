#include<iostream>
using namespace std;
// 16进制以0x开头0x11
// 8进制以0开头如011
/*
	获取n的倒数第m位的值（从1开始计数）
*/
int getMthByTail(int n, int m){
	return (n >> (m - 1)) & 1;
}
/*
	将n的倒数第m位设为1
*/
int setMthByTail21(int n, int m)
{
	return n | (1 << (m - 1));
}
/*
	将n的倒数第m位设为0
*/
int setMthByTail20(int n, int m)
{
	return n & ~(1 << (m - 1));
}
void test() {
	cout << getMthByTail(3, 1) << endl;
	cout << getMthByTail(3, 2) << endl;
	cout << getMthByTail(3, 3) << endl;
	
	cout << setMthByTail21(3, 1) << endl;
	cout << setMthByTail21(3, 2) << endl;
	cout << setMthByTail21(3, 3) << endl;
	
	cout << setMthByTail20(3, 1) << endl;
	cout << setMthByTail20(3, 2) << endl;
	cout << setMthByTail20(3, 3) << endl;
}
int main() {
	test();
	return 0;
}