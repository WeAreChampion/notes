#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_ROW 100
#define MAX_COL 100
/*
	To get max Sum.
*/
//To save the current start pos and end pos
int bStart;
int bEnd;
//To save the start pos and end pos
int start;
int end;
/*
	得到最大子段和
*/
int maxSum(int a[], int n)//一维最大子串和
{
	int sum = -10000000, b = 0;
	int i;
	for(i = 0; i < n; i++) {
		//若当前值大于0，则累加
		if(b > 0) {
			b += a[i];
			//记忆相应的最后位置i
			bEnd = i;
		} else {
			//若当前值小于等于0，则将当前值a[i]保存到当前最优值中.
			b = a[i];
			bStart = i;
			bEnd = i;
		}
		if(b > sum) {//若当前最优值大于保存的最优值，则保存当前值为最优值
			sum = b;
			//To save the start pos and end pos
			start = bStart;
			end = bEnd;
		}
	}
	return sum;
}
void testMaxSum()
{
	int n = 7;
	int array[MAX_ROW] = {
		1, 2, -7, 5, 4, -2, 3
	};
	
	cout << "Max Sum 1 : " << maxSum(array, n) << endl;
	cout << "start = " << start << ", end = " << end << endl;
}
/**
	二维矩阵最大字段和，即求矩阵的一个子矩阵，使之和最大
	矩阵即m行n列
*/
int maxSum2(int array[3][3], int m, int n)
{
	int sum = 0;
	int *b = new int[n];

	// 枚举m行0 ~ m-1
	for(int i = 0; i < m; i++) {
		/**
			To init the array b
			b[k] 保存第k列最大子段和
		*/
		for(int k = 0; k < n; k++) {
			b[k] = 0;
		}

		// 枚举第 i ~ m-1行
		for(int j = i; j < m; j++) {

			// 求解其j行下的第k列的最大字段和
			for(int k = 0; k < n; k++) {
				b[k] += array[j][k];
			}

			// 计算当前最优值
			int max = maxSum(b, n);

			// 当前最优值为最优解
			if(sum < max) {
				sum = max;
			}
		}
	}
	delete b;
	return sum;
}
void testMaxSum2()
{
	int array[3][3] = {
		{1, 2, 3},
		{4, -3, 1},
		{6, 7, -8}
	};
	int m = 3, n = 3;
	cout << maxSum2(array, m, n) << endl;
}
int main()
{
	testMaxSum();
	
	cout << endl << "Max Sum 2 : ";
	testMaxSum2();
	return 0;
}
/**
	
*/