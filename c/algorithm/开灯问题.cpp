#include<iostream>
using namespace std;
#include<cstring>
#define MAX_SIZE 100
/**
	问题： n盏灯，编号1-n，第一个人把所有等打开；第二个人按所有编号为2的倍数
	的灯(开-关)；第三个人按所有编号为3的倍数的灯；以此类推。一共有k个人，
	求最后开着的灯的编号。

*/
void print(int array[], int length) {
	for(int i = 1; i <= length; i++) {
		if(array[i] != 0) {
			cout << i << " ";
		}
	}
	cout << endl;
}
void turnOrOff(int array[], int n, int k) {
	// k peoples
	for(int i = 1; i <= k; i++) {
		// n lights
		for(int j = 1; j <= n; j++) {
			if(j % i == 0) {
				
				// 取反,0->1; 1->0
				array[j] = !array[j];
			}
		}
	}
	
}
void testOnOrOff() {
	int n, k;
	int array[MAX_SIZE];
	while(cin >> n >> k) {
		memset(array, 0, sizeof(array));
		turnOrOff(array, n, k);
		print(array, n);
	}
}
int main() {
	testOnOrOff();
	return 0;
}
/**
Input:
7 3

Output:
1 5 6 7
*/