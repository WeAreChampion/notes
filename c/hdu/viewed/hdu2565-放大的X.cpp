#include<iostream>
using namespace std;
void printX(int n, char ch) {
	char array[81][81];
	
	//init array by char ch
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j || (i + j == n - 1)) {
				array[i][j] = ch;
			} else {
				array[i][j] = ' ';
			}
		}
	}
	
	//print char array
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			// 控制输出空格,利用几何区域来限制
			if( i < j && i + j > n - 1) {
				break;
			}
			cout << array[i][j];
		}
		cout << endl;
	}
}
void test() {
	int ca;
	cin >> ca;
	while(ca--) {
		int n;
		cin >> n;
		printX(n, 'X');
		cout << endl;
	}
	
}
int main() {
	test();
	return 0;
}
/*
Sample Input
2
3
5 
 

Sample Output
X X
 X
X X

X   X
 X X
  X
 X X
X   X
*/