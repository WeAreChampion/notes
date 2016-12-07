#include<iostream>
using namespace std;
/**
	使用异或运算交换A与B
	不使用第三变量交换A与B
*/
void swap(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
/**
	测试是否交换成功
*/
void testSwap() {
	int a = 2;
	int b = 10;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	
	a = 11, b =14;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	
	a = 14, b =11;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
}
int main() {
	testSwap();
	return 0;
}