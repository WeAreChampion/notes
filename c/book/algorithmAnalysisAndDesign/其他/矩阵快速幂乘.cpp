#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int N;
struct matrix {
	int a[3][3];
} origin, res;
/**
	To calculate the matrix Z = X * Y and return
*/
matrix multiply(matrix x, matrix y)
{
	matrix temp;

	// quick set matrix temp 0
	memset(temp.a, 0, sizeof(temp.a));

	// multiply temp = x * y
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				temp.a[i][j] += x.a[i][k]*y.a[k][j];
			}
		}
	}
	return temp;
}
void init()
{
	// random set matrix origin
	printf("随机数组如下:\n");
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			origin.a[i][j] = rand() % 10;
			printf("%8d", origin.a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// quick set matrix res 0
	memset(res.a, 0, sizeof(res.a));

	//将res.a初始化为单位矩阵
	res.a[0][0] = res.a[1][1] = res.a[2][2] = 1;
}
/**
	矩阵快速幂乘
	A^n = AAAA...A

*/
void calc(int n)//快速幂乘
{
	int m = n;
	while(n) {
		// 奇数
		if(n & 1) {
			//	res = res I* origin
			res = multiply(res, origin);
		}
		// 右移1位，相当于 n = n / 2;
		n >>= 1;

		// origin = origin * origin
		origin = multiply(origin, origin);
	}

	// To output the result matrix res
	printf("%d次幂结果如下：\n", m);
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			printf("%8d", res.a[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	while(cin >> N) {
		init();
		calc(N);
	}
	return 0;
}