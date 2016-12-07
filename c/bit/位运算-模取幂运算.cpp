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
/*
参数：
a、 b、 n： a^b mod n 的对应参数
返回值： a^b mod n 的值
注意：
需要BitLength和BitAt
*/
int Modular_Expoent(int a, int b, int n)
{
	int y = 1;
	//To get the bit's length
	int i = BitLength(b);
	
	//For each i
	for(; i > 0; i--) {
		y = (y * y) % n;
		if(BitAt(b, i) > 0)
			y = (y * a) % n;
	}
	return y;
}
void test() {
	cout << "2^3 % 3 = " << Modular_Expoent(2, 3, 3) << endl;
	cout << "2^4 % 3 = " << Modular_Expoent(2, 4, 3) << endl;
	cout << "2^3 % 4 = " << Modular_Expoent(2, 3, 4) << endl;
	cout << "3^3 % 4 = " << Modular_Expoent(3, 3, 4) << endl;
}
int main() {
	test();
	return 0;
}