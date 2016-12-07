#include<iostream>
using namespace std;
/**
	游戏规则
	1. 每次将任一行金币翻过来(0->1;1->0)
	2. 每次任选两列，交换
	求从初始状态变换到目标状态需要的最少变换次数
*/

// 变换次数最大值
const int inf = 99999;
const int N = 101;
/**
	a save the start array
	b save the aim array
	temp save the current array
*/
int a[N][N], b[N][N], temp[N][N];

int n, m;
/**
	变换次数
*/
int need;

/**
	交换a与b
*/
int swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

/**
	交换任意temp array两列
*/
void swapColumn(int x, int y) {
	if(x == y) {
		return;
	}
	
	// 
	for(int i = 1; i <= n; i++) {
		swap(temp[i][x], temp[i][y]);
	}
	
	// 变换次数+1
	need++;
}
/**
	翻转temp某一行；0->1;1->0；即取异或
*/
void changeRow(int x) {
	for(int i = 1; i <= m; i++) {
		temp[x][i] ^= 1;//与1取异或
	}
}
/**
	判断目标数组b的第x列与临时数组temp的第y列是否相同
	相同返回true；否则返回false
*/
bool Same(int x, int y) {
	for(int i = 1; i <= n; i++) {
		if(b[i][x] != temp[i][y]) {
			return false;
		}
	}
	return true;
}
int main() {
	int tests;
	cin >> tests;
	while(tests--) {
		cin >> n >> m;
		int i, j;
		
		// 输入初始变换矩阵
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		
		// 输入目标变换矩阵
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				cin >> b[i][j];//input the aim array
			}
		}
		
		// 开始变换矩阵，并求变换次数
		int k;
		
		// 当前变换矩阵最优值
		int ans = inf;
		
		// 枚举m列变换
		for(k = 1; k <= m; k++) {
			
			// 记录当前初始值
			for(i = 1; i <= n; i++) {
				for(j = 1; j <= m; j++)
					temp[i][j] = a[i][j];
			}
			
			// 初始变换次数
			need = 0;
			
			// 交换temp的第一列与第k列；k from 1 to m
			swapColumn(1, k);
			
			// 比较第一列，不相等，进行行变换
			for(i = 1; i <= n; i++) {
				if(temp[i][1] != b[i][1]) {
					changeRow(i);
					need++;
				}
			}
			
			// 标记m列是否相同
			bool find;
			
			// 依次检查m列是否与目标数组b相同
			for(i = 1; i <= m; i++) {
				find = false;
				
				//与目标数组进行判断
				if(Same(i, i)) { 
					find = true;
					continue;
				}
				
				// 寻找temp中与b相同的列
				for(j = 1; j <= m; j++) {
					
					// 目标数组的第i列与临时数组的第j列是否相同
					if(Same(i, j)) {
						// 若果目标数组的第j列与临时数组的第j列已经相同了，则不变换
						if(Same(j, j))
							continue;
						
						// 进行变换，标记找到了相应的列
						swapColumn(i, j);//交换列
						find = true;
						break;
					}
				}
				
				if(find == false) { //找不到该列对应的列
					break;
				}
			}
			
			// 都能找到对应的变换列
			if(find && need < ans) {
				// 更改当前最优值
				ans = need;
			}
		}
		
		// 能否变换成功
		if(ans < inf) {
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
/*
Input:
2
4 3
1 0 1
0 0 0
1 1 0
1 0 1
1 0 1
1 1 1
0 1 1
1 0 1
4 3
1 0 1
0 0 0
1 0 0
1 1 1
1 1 0
1 1 1
0 1 1
1 0 1

Output:
2
-1
*/