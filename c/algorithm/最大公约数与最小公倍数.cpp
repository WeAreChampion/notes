/*
�﷨��resulet=hcf(int a,int b)��result=lcd(int a, int b)
������
a��int a�������Լ������С������
b��int b�������Լ������С������
����ֵ���������Լ����hcf������С��������lcd��
ע�⣺
lcd ��Ҫ��ͬhcf ʹ��
*/
#include<iostream>
using namespace std;
/*
	�����Լ��
*/
int hcf(int a, int b)
{
	int r = 0;
	while(b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
/**
	����С������
*/
int lcd(int u, int v, int h)
{
	return u * v / h;
}
int main()
{
	int m, n;
	while(cin >> m >> n) {
		if(m < n) {
			int temp = m;
			m = n;
			n = temp;
		}
		int h = hcf(m, n);
		cout << "���Լ���ǣ�" << h << "\n" << "��С�������ǣ�" << lcd(m,n,h) << endl;
	}
	return 0;
}
/**
Input:
2 3
4 8

Output:
1 6
4 8
*/