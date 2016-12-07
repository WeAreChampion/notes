#include<iostream>
using namespace std;
int a[10];
/**
	统计数字问题
	计算十进制数字n中含有多少种数字，保存在数组a[10]中
	Tn = O(lgN)
*/
int Count(int n) {
	while(n) {
		a[n % 10]++;
		n /= 10;
	}
}
int main() {
	int n, i;
	while(cin >> n) {
		//init the count
		for(i = 0; i < 10; i++) {
			a[i] = 0;
		}
		
		// From 1 to n to count number,Tn = O(n)
		for(i = 1; i <=n; i++) {
			Count(i);	
		}
		
		//To display array
		for(i = 0; i < 10; i++) {
			cout << i << ": " << a[i] << endl;
		}
	}
	return 0;
} 
/*
In:
11
out:
1
4
1
1
1
1
1
1
1
1
*/