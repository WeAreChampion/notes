#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
/*
	重复元素排列问题，即讨论交换的元素是否在以前出现过
	，则说明已经排过，若不是，则给出排列.
*/
/**
	保存排列组合的种数
*/
long long ans;
/**
	判断字符数组前面的交换字符是否出现， 出现则排列代表重复；
	否则排列不重复。即判断[a-(b - 1)]之间的字符数组是否出现过
	相同的字符。
	char str[]  : 需要产生排列的字符数组
	int a  		: 排列的初始位置
	int b  		: 排列的结束位置

	出现返回0，即该排列已经产生，不需要重新产生相同的排列；否则返回1.
*/
int ok(char str[], int a, int b )
{
	// 必须大于
	if(b > a) {

		// 判断字符是否出现a~b-1内
		for(int i = a; i < b; i++) {
			if(str[i] == str[b]) {
				return 0;
			}
		}
	}
	return 1;
}
/**
	产生所有非重复元素的排列
	char str[]  : 需要产生排列的字符数组
	int k  		: 产生排列的初始位置
	int m  		: 产生排列的结束位置
*/
void perm(char str[], int k, int m)
{
	int i;

	// 递归结束
	if(k == m) {

		// 累加
		ans++;

		// 输出结果
		for(i = 0; i <= m; i++)
			printf("%c", str[i]);
		printf("\n");
		return ;
	} else {
		
		// 产生k~m之间的所有排列
		for(i = k; i <= m; i++)
			// 要交换的元素以前并未使用
			if(ok(str, k, i)) {
				
				// 交换
				swap(str[k], str[i]);
				
				// 递归产生k+1~m之间的所有排列
				perm(str, k + 1, m);
				
				// 交换
				swap(str[k], str[i]);
			}
	}
}
int main()
{
	char str[505];
	int n, i;
	scanf("%d", &n);
	getchar();
	ans = 0;
	for(i = 0; i < n; i++)
		scanf("%c", &str[i]);
	
	// 产生0 ~ n-1之间的所有非重复元素的排列
	perm(str, 0, n - 1) ;
	printf("%lld\n", ans);
	return 0;
}
/*
Input:
4
aacc

Output:
aacc
acac
acca
caac
caca
ccaa
6
*/