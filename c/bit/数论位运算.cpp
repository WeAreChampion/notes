#include<iostream>
using namespace std;
/*
	1.x �Ķ����Ƴ���
	�﷨��result=BitLength(int x);
	������
	x���ⳤ��x
	����ֵ��x �Ķ����Ƴ���
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
	2.����x �Ķ����Ʊ�ʾ�дӵ͵��ߵĵ�i λ
	�﷨��result=BitAt(int x, int i);
	������
	x��ʮ����x
	i��Ҫ������Ƶĵ�i λ
	����ֵ������x �Ķ����Ʊ�ʾ�дӵ͵��ߵĵ�i λ
	ע�⣺
	���λΪ��һλ
*/
int BitAt(int x, int i)
{
	return ( x & (1 << (i - 1)) );
}
/*
	3.ģȡ������
	�﷨��result=Modular_Expoent(int a,int b,int n);
	������
	a��b��n��a^b mod n �Ķ�Ӧ����
	����ֵ��a^b mod n ��ֵ
	ע�⣺
	��ҪBitLength ��BitAt
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
		cout << "�����Ʊ�ʾ�дӵ͵��ߵĵ�3 λ: " << BitAt(n, 3) << endl;
		cin >> a >> b;
		cout << "ģȡ������: " << Modular_Expoent(a, b, n) << endl;
	}
	return 0;
}