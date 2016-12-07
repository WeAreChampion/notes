#include<iostream>
using namespace std;
/*
	取绝对值
	n右移31位，可以获得n的符号。若n为正数，得到0；
	若n为负数，得到 -1
*/
int myAbs(int n){
	return (n ^ n >> 31) - (n >> 31);
}
void test() {
	cout << myAbs(10) << endl;
	cout << myAbs(11) << endl;
	cout << myAbs(-11) << endl;
	cout << myAbs(-12) << endl;
}
int main() {
	test();
	return 0;
}