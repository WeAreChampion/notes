#include<iostream>
using namespace std;
/**
	返回1：不是漂亮草坪
	返回0：是漂亮草坪
*/
int FirstLine(int p[10][10], int m)
{
	//the first line
	for(int k = 1; k < m; k++) {
		//连续两个0
		if(p[0][k] == 0 && p[0][k - 1] == 0) {	
			return 1;
		}
	}
	return 0;
}
/**
	返回1：不是漂亮草坪
	返回0：是漂亮草坪
*/
int OthersLine(int p[10][10], int m, int n)
{
	int i, j;
	for(i = 1; i < n; i++) {
		for(j = 0; j < m; j++) {
			
			// 同列相邻行连续两个0
			if(p[i][j] == 0 && p[i - 1][j] == 0) {
				return 1;
			}
			if(j != 0) {
				// 同行相邻列连续0
				if(p[i][j] == 0 && p[i][j - 1] == 0) {
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int p[10][10];
	int n, m, i, j, k;
	while(cin >> n >> m) {
		int flag = 1;
		if(n == 0 && m == 0) {
			break;
		} 
		
		// 输入并判断是否全1
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				cin >> p[i][j];
				if(p[i][j] == 0) {
					flag = 0;
				}
			}
		}
		
		// 全1，则不是
		if(flag) {
			cout << "No\n";
			continue;
		}
		
		// 第一行
		if(FirstLine(p, m)) {
			cout << "No\n";
			continue;
		}
		
		// 其他行
		if(OthersLine(p, m, n)) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}
	return 0;
}
/*
Input:
2 2
1 0
0 1
2 2
1 1
0 0
2 3
1 1 1
1 1 1

Output:
Yes
No
No
*/