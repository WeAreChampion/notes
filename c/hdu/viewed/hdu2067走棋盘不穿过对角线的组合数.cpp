#include <iostream>
using namespace std;
#define N 36
__int64 chessboard[N][N];
/*
从起点(0，0)走到终点(n,n)的最短路径数是C(2n,n)；
现假设不能穿过住对角线(y = x)，求其走法的数量
*/
void init(){
	int i, j;
	memset(chessboard, 0, sizeof(chessboard));
	for (i = 0; i < N; i++) {
		// 初始化第i行第0列的值为1
		/*
			每次到达(i, 0)，往上走距离加1，往又走距离加1；
			即有含有两种选择 
		*/ 
		chessboard[i][0] = 1;
	}
	for (i = 1; i < N; i++) { 
		for (j = 1; j <= i; j++) { 
			chessboard[i][j] = chessboard[i - 1][j]+chessboard[i][j - 1];
		}
	} 
}

int main(){
	int n,ce = 0;
	init();
	while (scanf("%d", &n) != EOF  && n != -1){
		ce++;
		//先计算对角线y = x的下方，而后利用对称即乘以2 
		printf("%d %d %I64d\n",ce, n, 2 * chessboard[n][n]);
	}
	return 0;
}
/*
Sample Input

1
3
12
-1

 
Sample Output

1 1 2
2 3 10
3 12 416024
*/