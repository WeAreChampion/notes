#include<iostream>
using namespace std;
/*
	Ҫ������10000ȡ�ࡣ 
	���� n * n ���������ֺܴ�����Ҫ��10000ȡ�ࡣ 
*/
void test()
{
	int ca;
	cin>>ca;
	while(ca--) {
		int n;
		cin >> n;
		int value =  n % 10000;
		cout << (value * value ) % 10000 <<endl;
	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
2
1
2


Sample Output
1
4

*/