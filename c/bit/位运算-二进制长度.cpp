#include<iostream>
using namespace std;
/*
	To get the length of x(2).
	获得二进制位长度
*/
int BitLength(int  x)
{
	int  d = 0;
	while (x > 0) {
		x >>= 1;
		d++;
	}
	return d;
}
void test()
{
	cout << "1's length = " << BitLength(1) << endl;
	cout << "2's length = " << BitLength(2) << endl;
	cout << "4's length = " << BitLength(4) << endl;
	cout << "9's length = " << BitLength(9) << endl;
}
int main()
{
	test();
	return 0;
}