#include<iostream>
using namespace std;
/**
	整数的因式分解情况的种数
	如12：
		12 = 12
		12 = 6 * 2
		12 = 4 * 3
		12 = 3 * 4
		12 = 3 * 2 * 2
		12 = 2 * 6
		12 = 2 * 3 * 2
		12 = 2 * 2 * 3
*/
/**
	保存分解的种数
*/
long total = 0;
/**
	整数n因式分解的种数
*/
void solve(long n)
{
	// 整数1的分解种数，即只有一种
	if(n == 1)
		total++;
	else {
		// 对其多个因子也进行分解与计数
		for(long i = 2; i <= n; i++) {
			if(n % i == 0) {
				solve(n / i);
			}
		}
	}
}
int main()
{
	long n;
	while(cin >> n) {
		solve(n);
		cout << total << endl;
		total = 0;
	}
	return 0;
}
/**
Input:
12

Output:
8
*/