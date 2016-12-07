#include <iostream>
using namespace std;
#define N 36
__int64 chessboard[N][N];
/*
�����(0��0)�ߵ��յ�(n,n)�����·������C(2n,n)��
�ּ��費�ܴ���ס�Խ���(y = x)�������߷�������
*/
void init(){
	int i, j;
	memset(chessboard, 0, sizeof(chessboard));
	for (i = 0; i < N; i++) {
		// ��ʼ����i�е�0�е�ֵΪ1
		/*
			ÿ�ε���(i, 0)�������߾����1�������߾����1��
			���к�������ѡ�� 
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
		//�ȼ���Խ���y = x���·����������öԳƼ�����2 
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