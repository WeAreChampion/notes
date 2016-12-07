#include<iostream>
#include<cmath>
using namespace std;
/**
	s(n)是正整数n的真因子之和，即小于n且整除n的因子和.例如
	s(12)=1+2+3+4+6=16.如果任何数m，s(m)都不等于n,则称n为不可摸数.
	
	数学题，输入n，判断n是不是不可摸数。
	1. 设t = n - 1。
	2. 如果t是素数的话，那么要使得S(m) = n，只要m = t * t即可，此时m的真因子
	有：1, t。则S(m) = t + 1 = n，也就是说n可摸.
	3.如果t不是素数，但是t可以表示成两个素数的和的话，设i是素数，并且t = i + (t-i)，
	其中 t-i 也是素数。那么要使得S(m) = n，只要m = i * (t - i) 即可，此时，m 的真因子
	有：1, i , t - i 。则S(m) = 1 + i + t - i = t + 1 = n，也就是说 n 可摸 （这里注意：
	t - i != i，因为 i 和 n - i 在作为真因子相加的时候出现了两次，如果两者相等的话，相
	当于第一种情况）

	4. 除了这两种情况，n 都是不可摸数
*/
int prime[1010], b[1010], c[1010];
int main()
{
	int n;
	cin >> n;

	// 0,1可摸
	c[0] = c[1] = 1;
	int k = 0;
	for (int i = 2; i <= 1000; ++i)
		if (c[i] == 0) {
			for (int j = i + i; j <= 1000; j += i)
				c[j] = 1;
			b[i + 1] = 1;
			prime[k] = i;
			k++;
		}
	for (int i = 0; i < k; ++i)
		for (int j = i + 1; j < k; ++j)
			if (prime[i] + prime[j] + 1 < 1000)
				b[prime[i] + prime[j] + 1] = 1;
	while (n--) {
		int m;
		cin >> m;
		if (b[m] == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
/**
Sample Input
3
2
5
8


Sample Output
yes
yes
no
*/