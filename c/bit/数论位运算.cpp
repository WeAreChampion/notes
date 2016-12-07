#include<iostream>
using namespace std;
/*
	1.x 的二进制长度
	语法：result=BitLength(int x);
	参数：
	x：测长的x
	返回值：x 的二进制长度
*/
int BitLength(int x)
{
	int d = 0;
	while (x > 0) {
		x >>= 1;
		d++;
	}
	return d;
}
/*
	2.返回x 的二进制表示中从低到高的第i 位
	语法：result=BitAt(int x, int i);
	参数：
	x：十进制x
	i：要求二进制的第i 位
	返回值：返回x 的二进制表示中从低到高的第i 位
	注意：
	最低位为第一位
*/
int BitAt(int x, int i)
{
	return ( x & (1 << (i - 1)) );
}
/*
	3.模取幂运算
	语法：result=Modular_Expoent(int a,int b,int n);
	参数：
	a、b、n：a^b mod n 的对应参数
	返回值：a^b mod n 的值
	注意：
	需要BitLength 和BitAt
*/
int Modular_Expoent(int a, int b, int n)
{
	int i, y = 1;
	for (i = BitLength(b); i > 0; i--) {
		y = (y * y) % n;
		if (BitAt(b, i) > 0)
			y = (y * a) % n;
	}
	return y;
}
int main()
{
	int n,a,b;
	while(cin >> n) {
		cout << "bit Length is: " << BitLength(n) << endl;
		cout << "二进制表示中从低到高的第3 位: " << BitAt(n, 3) << endl;
		cin >> a >> b;
		cout << "模取幂运算: " << Modular_Expoent(a, b, n) << endl;
	}
	return 0;
}