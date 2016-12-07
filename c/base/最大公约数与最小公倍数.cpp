#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int temp;
	if(a < b) {/*交换两个数，使大数放在a上*/
		temp = a;
		a = b;
		b = temp;
	}
	while(b != 0) {/*利用辗除法，直到b为0为止*/
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
} 
void test()
{
	cout << "5与10的最大公约数：" << gcd(5, 10) << endl;
	cout << "5与10的最小公倍数：" << lcm(5, 10) << endl;
	cout << "2与3的最大公约数：" << gcd(2, 3) << endl;
	cout << "2与3的最小公倍数：" << lcm(2, 3) << endl;
	cout << "12与8的最大公约数：" << gcd(12, 8) << endl;
	cout << "12与8的最小公倍数：" << lcm(12, 8) << endl;
}
int main()
{
	test();
	return 0;
}