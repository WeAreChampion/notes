#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int temp;
	if(a < b) {/*������������ʹ��������a��*/
		temp = a;
		a = b;
		b = temp;
	}
	while(b != 0) {/*����շ������ֱ��bΪ0Ϊֹ*/
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
	cout << "5��10�����Լ����" << gcd(5, 10) << endl;
	cout << "5��10����С��������" << lcm(5, 10) << endl;
	cout << "2��3�����Լ����" << gcd(2, 3) << endl;
	cout << "2��3����С��������" << lcm(2, 3) << endl;
	cout << "12��8�����Լ����" << gcd(12, 8) << endl;
	cout << "12��8����С��������" << lcm(12, 8) << endl;
}
int main()
{
	test();
	return 0;
}