#include<iostream>
using namespace std;
/**
	n的整数划分数，将最大加数不大于m的划分数记作q(n, m)
*/
int q(int n, int m)
{
	/*
		1. 不满足划分数的条件，返回0
	*/
	if(n < 1 || m < 1)
		return 0;
	
	/*
		2. n = 1时 : 1的划分数是1本身，即只有一种
		   m = 1时 : n的划分数最大加数不大于1，即全1的情况，只有一种
	*/
	if(n == 1 || m == 1)
		return 1;
	
	/*
		3. 最大加数不大于m > n 时；允许的最大加数为其本身n
	*/
	if(n < m)
		return q(n, n);
	
	/*
		4. 最大加数不大于m = n 时；允许的最大加数为其本身n，其种数为
		本身(一种) + 最大加数为n - 1(or m - 1)的递归调用
		即q(n, m - 1) + 1;
		
	*/
	if(n == m)
		return q(n, m - 1) + 1;
	
	/*
		5. 最大加数不大于m的划分即包含最大加数 = m与最大加数<= m - 1
		划分的和
		q(n, m - 1) : 整数n划分，最大加数<= m - 1的种数
		
		q(n - m, m) : 剩余数n - m划分；最大加数 <= m的种数
		已经用掉了m
	*/
	return q(n, m - 1) + q(n - m, m);
}
int main()
{
	int n;
	while(cin >> n) {
		cout << q(n, n) << endl;
	}
	return 0;
}
/**
Input:
6

Output:
11

*/