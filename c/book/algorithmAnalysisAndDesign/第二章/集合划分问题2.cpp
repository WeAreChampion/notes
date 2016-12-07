#include <iostream>
using namespace std ;
/**
	1. 给定正整数n 和m，计算出n 个元素的集合{1,2,., n }可以划分为
	多少个不同的由m 个非空子集组成的集合。
	递归公式,
*/
/**
	构造计算排列组合的函数
	n : 分母
	m : 分子
*/
int zuhe(int m, int n, int r) //
{
	//用t记录n到(n - m + 1)的乘积, 用 s 记录m到1的乘积
	int p = m, q = n, t = 1, s = 1 ;

	for(int i = 0; i < p; i++) {
		t *= n ;
		n--;
		s *= m;
		m--;

	}
	if(q == p * 2 && r == 1)
		return (t / s) / 2 ;
	/**
		当出现在四个元素的集合中选取两个元素作为一个集合时，可能出现的情况是这两个
		元素在被计算了两次，故在这里先将其组合数的结果除2
	*/
	return t / s ;
}
/**
	运用递归计算集合的个数
	集合中元素个数为m 的 数量有n情况
	m : 集合中元素个数
	n : 集合数量
*/
int jihe(int m, int n)
{
	// 累计数量
	int count = 0;
	
	// 元素个数为
	if(m == n || m == 0)
		return 1;
	
	// 含一个集合的数量为1即本身
	if(n == 1)
		return 1;
	for(int i = (m - n + 1); i >= (m - i + (n - 2)) / (n - 1); i--) {
		count += zuhe(i, m, n - 1) * jihe(m - i, n - 1) ;
	}
	return count ;
}
int main()
{
	int m, n ;
	cout << "Input m and n: ";
	cin >> m >> n ;
	cout << jihe(m, n) << endl ;
	return 0 ;

}
/**
Input:
4 3

Output:
6

*/