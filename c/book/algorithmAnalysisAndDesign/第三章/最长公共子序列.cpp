#include<iostream>
#include<string>
using namespace std;
/**
	设序列X = {x1,x2...xm}，Y = {y1,y2...yn}的最长公共子序列为Z = {z1,z2..zk}
		1. 当xm = yn，则zk = xm = yn，且Zk-1是Xm-1和Yn-1的最长公共子序列
		2. 当xm != yn 且zk != xm，则Z是Xm-1和Y的最长公共子序列
		3. 当xm != yn 且zk != yn，则Z是X和Yn-1的最长公共子序列

	c[i][j] 记录序列Xi与Yj的最长公共子序列的长度
	Xi = {x1,x2...xi}
	Yj = {y1,y2...yj}
	
	动态转移方程:
	          0                               i = 0, j = 0
	c[i][j] = c[i - 1][j - 1] + 1             i, j > 0;xi = yj
	          max{c[i][j - 1], c[i - 1][j]}   i,j > 0,xi != yj
			  
	b[i][j]记录c[i][j] 的值是由哪一个子问题得到的，这在构造最长公共子序列时要用到
	
	          1 由上面的标注1得到
	b[i][j] = 2 由上面的标注2得到
	          3 由上面的标注3得到
	
	c[m][n] 即记录序列Xm与Yn的最长公共子序列的长度，即X和Y的最长公共子序列的长度
	X和Y的最长公共子序列的长度记录于c[m][n]中
	
	
	m   : X序列的长度
	n   : Y序列的长度
	*x  : X序列
	*y  : Y序列
	**c : 如上所述
	**b : 如上所述
	Tn = O(m * n)
*/
void LCSLength(int m, int n, char *x, char *y, int c[10][10], int b[10][10])
{
	int i, j;
	// j = 0, c[i][j] = 0;
	for(i = 1; i <= m; i++) {
		c[i][0] = 0;
	}
	
	// i = 0, c[i][j] = 0
	for(i = 1; i <= n; i++) {
		c[0][i] = 0;
	}
	
	// 遍历子序列X与Y
	for(i = 1; i <= m; i++) {
		for(j = 1; j <= n; j++) {
			
			// 第一种方案
			if(x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			} else if(c[i - 1][j] >= c[i][j - 1]) {// 第二中方案
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			} else {// 第三中方案
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
}
/**
	根据b[i][j]输出解，输出给定的最长公共子序列
	b[i][j] = 1时，表示Xi与Yj的最长公共子序列是由Xi-1与Yj-1的最长公共子序列在尾部加上
xi所得到的子序列。
	b[i][j] = 2时，表示Xi与Yj的最长公共子序列与Xi-1与Yj的最长公共子序列相同
xi所得到的子序列。
	b[i][j] = 3时，表示Xi与Yj的最长公共子序列与Xi与Yj-1的最长公共子序列相同
xi所得到的子序列。
	Tn = O(m + n)
*/
void LCS(int i, int j, char *x, int b[10][10])
{
	if(i == 0 || j == 0) {
		return ;
	}
	
	// Xi-1与Yj-1的最长公共子序列在尾部加上xi所得到的子序列。
	if(b[i][j] == 1) {
		LCS(i - 1, j - 1, x, b);
		cout << x[i];
	} else if(b[i][j] == 2) { // Xi-1与Yj的最长公共子序列相同
		LCS(i - 1, j, x, b);
	} else { // Xi与Yj-1的最长公共子序列相同
		LCS(i, j - 1, x, b);
	}
}
int main()
{
	string sa, sb;
	while(cin >> sa >> sb) {
		char x[10], y[10];
		int i, m, n;
		
		// 初始化x序列
		for(i = 0; i < sa.size(); i++) {
			x[i + 1] = sa[i];
		}
		
		// 初始化y序列
		for(i = 0; i < sb.size(); i++) {
			y[i + 1] = sb[i];
		}
		int c[10][10];
		int b[10][10];
		m = sa.size();
		n = sb.size();
		LCSLength(m, n, x, y, c, b);
		cout << "the length is: " << c[m][n] << endl;
		cout << "最长公共子序列是：" << endl;
		LCS(m, n, x, b);
		cout << endl;
	}
	return 0;
}
/*
Input:
ABCBDAB
BDCABA

Output:
4
BCAB
*/