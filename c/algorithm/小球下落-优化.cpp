#include<iostream>
using namespace std;
void test() {
	
	int D, I;
	// 输入深度D与编号I
	while(cin >> D >> I) {
		int k = 1;
		int length = D - 1;
		for(int i = 0; i < length; i++) {
			if(I % 2) {// 为奇数，左走(I + 1) / 2个小球
				k = k * 2;
				I = (I + 1) / 2;
			} else {// 为偶数，右走I / 2个小球
				k = k * 2 + 1;
				I = I / 2;
			}
		}
		
		cout << k << endl;
	}
}
int main() {
	test();
	return 0;
}

/**
Input:
4 2
3 4
10 1
2 2
8 128
16 12345

Output:
12
7
512
3
255
36358
*/