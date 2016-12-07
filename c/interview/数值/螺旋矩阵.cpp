#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_SIZE 10
/**
	获得循环矩阵
*/
void getCircleMatrix(int array[MAX_SIZE][MAX_SIZE], int n) {
	int i, j, k = 0, m;
	
	// 1. 求m：保存旋的次数
	if(n % 2 == 0) {
		m = n / 2;
	} else {
		m = n / 2 + 1;
	}
	
	// 2.依次求值
	for(i = 0; i < m; i++) {
		int length = n - i;
		
		// 产生该圈上 横行数字
		for(j = i; j < length; j++) {
			k++;
			array[i][j] = k;
		}
		
		// 产生该圈右 竖列数字
		for(j = i + 1; j < length; j++) {
			k++;
			array[j][length - 1] = k;
		}
		
		// 产生该圈下 横行数字
		length = length - 2;//length = n - i - 2
		for(j = length; j >= i; j--) {
			k++;
			array[length + 1][j] = k;
		}
		
		// 产生该圈左 竖列数字
		for(j = length; j >= i + 1; j--) {
			k++;
			array[j][i] = k;
		}
	}
}
void dispArray(int array[MAX_SIZE][MAX_SIZE], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%4d ", array[i][j]);
		}
		cout << endl;
	}
}
void testGetCircleMatrix() {
	int n;
	while(cin >> n) {
		int array[MAX_SIZE][MAX_SIZE];
		
		getCircleMatrix(array, n);
		dispArray(array, n);
	}
}
int main() {
	testGetCircleMatrix();
	return 0;
}