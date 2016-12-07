#include<iostream>
using namespace std;
/*
	To get the i-th value of number(2).
	数字获得二进制位从低到高的第i位.
	结果为0，表示第i位为0;否则为1.
*/
int  BitAt(int  x, int  i)
{
	//1 << (i -1),即1右移i - 1位，即第i位为1，其余进制位为
	return (x & (1 << (i - 1)));
}
void test() {
	cout << "1's 1-th: " << BitAt(1, 1) << endl;
	cout << "1's 2-th: " << BitAt(1, 2) << endl;
	cout << "2's 1-th: " << BitAt(2, 1) << endl;
	cout << "2's 2-th: " << BitAt(2, 2) << endl;
	cout << "2's 3-th: " << BitAt(2, 3) << endl;
	cout << "3's 2-th: " << BitAt(3, 2) << endl;
}
int main()
{
	test();
	return 0;
}
