/*
输入两个整数m和n，计算需要改变m的二进制表示中的多少位才能得到n
即求m与n中有多少位不同
*/
#include<iostream>
using namespace std;
/*
	计算m与n有多少位不同，先进行异或运算(相同为0，不同为1)，
	而后进行1个数的统计。
*/
int changM2N(int m, int n) {
	int counts = 0;
	// To get the m ^ n's value.取m、n的异或，保存在c中
	int c = m ^ n;
	
	//计算1的个数
	while(c){
        c &= (c - 1);
        counts++;
    }
	return counts;
}
void testChangeM2N() {
	cout << "13 with 10, the bits different are : " << changM2N(13, 10) << endl;
}
/*
	To swap a and b by bit ^
*/
void swap(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void testSwap() {
	int a = 2;
	int b = 10;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
}
/*
	
*/
int sameMAndN(int m, int n) {
	int counts = 0;
	// 取反(m ^ n)
	int c = ~(m ^ n);
	
	//计算1的个数
	while(c){
        c &= (c - 1);
        counts++;
    }
	return counts;
}
void testSameMAndN() {
	cout << "13 with 10, the bits same are : " << sameMAndN(13, 10) << endl;
}
void test() {
	testChangeM2N();
	testSameMAndN();
	testSwap();
}
int main()
{
	test();
    return 0;
}