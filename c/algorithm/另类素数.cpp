#include<iostream>
#include<cmath>
using namespace std;
int a[10000]= {2};
/**
	判断是否为素数
*/
int f(int n)
{
	int length = (int)sqrt((double)n);
	for(int i = 2; i <= length; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	int i, k = 1, j;
	
	// 初始化10000内的所有素数
	for(i = 3; i < 10000; i++) {
		if(f(i)) {
			a[k++] = i;
		}
	}
	int n;
	while(cin >> n) {
		i = 0;
		j = 1;
		int flag = 0;
		
		// 判定n是否是两个素数和
		for(i = 0; ; i++) {
			for(j = i + 1; ; j++) {
				if(n == a[i] + a[j])
					flag = 1;
				if(a[j] > n)
					break;
			}
			if(a[i] > n / 2)
				break;
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}