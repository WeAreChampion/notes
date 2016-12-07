/*
语法：resulet=hcf(int a,int b)、result=lcd(int a, int b)
参数：
a：int a，求最大公约数或最小公倍数
b：int b，求最大公约数或最小公倍数
返回值：返回最大公约数（hcf）或最小公倍数（lcd）
注意：
lcd 需要连同hcf 使用
*/
#include<iostream>
using namespace std;
/*
	求最大公约数
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
	求最小公倍数
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
		cout << "最大公约数是：" << h << "\n" << "最小公倍数是：" << lcd(m,n,h) << endl;
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