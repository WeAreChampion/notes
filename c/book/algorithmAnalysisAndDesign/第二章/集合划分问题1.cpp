#include <iostream>
using namespace std;
#include <stdio.h>
/**
	1. 设n个元素的集合可以划分为F(n, m)个不同的由m个非空子集组成的集合。

	2.F(n, m) = 1, when n = 0, n = m, n = 1, or m = 1;
	F(n, m) = 0, when n < m;
	否则 F(n, m) = F(n - 1, m - 1) + m * F(n - 1, m)
*/
int getCollectionsCounts(int n, int m)
{
	/**
		m = 1 ：由一个非空子集组成集合的情况，只有一种情况，即其本身；
		n = 1 ：一个元素的集合划分只有一种情况，也是其本身；
		n = m ：n个元素m个非空子集组成的集合也只有一种情况，即每个元素组成单集合的集合
	*/
	if(m == 1 || n == m || n == 1) {
		return 1;
	}

	/**
		转换为n-1个元素含m-1个非空子集组成的集合数，
		加上m * 与n-1个元素含m个非空子集组成的集合数的乘积。
	*/
	return getCollectionsCounts(n - 1, m - 1) + m * getCollectionsCounts(n - 1, m);
}
void test()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		int sum = 0;

		// 累加m从1到n的不同情况
		for(int m = 1; m <= n; m++) {
			sum += getCollectionsCounts(n, m);
		}
		cout << sum << endl;
	}
}
int  main()
{
	test();
	return 0;
}

/*
Input:
4
5

Output:
15
52

*/