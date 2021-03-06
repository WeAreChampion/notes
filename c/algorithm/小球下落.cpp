#include<iostream>
using namespace std;
#include<string.h>

// 数的最大深度
#define MAX_D 20

// 最大节点数2^MAX_D - 1
int s[1 << MAX_D];
/**
	1. 二叉树最大深度为D，根节点深度为1，所有叶子节点深度相同；
	节点从上到下，从左到右依次编号1, 2, ..., 2^D-1；节点1处
	放一个小球，小球会下落；每个内节点上都有一个开关，初始全
	部关闭，每次有小球落到开关上时，状态会改变。到达内节点时，
	若开关关闭，则往左走，否则往右走；直到走到叶子节点。
	
	2. 一些小球从节点1出一次开始下落，最后小球将会落在哪里？输入
	叶子深度D和小球个数I，输出第I个小球最后所在的叶子编号。
	
	3. 往左走为2*k, 右走为2*k+1
*/
void test() {
	int D, I;
	while(cin >> D >> I) {
		memset(s, 0,sizeof(s));
		
		// n是最大节点编号
		int k, n = (1 << D) - 1;
		
		// 循环I次
		for(int i = 0; i < I; i++) {
			// 初始编号为1
			k = 1;
			for( ; ; ) {
				// 去异或
				s[k] = !s[k];
				
				// s[k] 为 1 则往左走，否则往右走
				k = s[k] ? k * 2 : k * 2 + 1;
				
				// 直到走到叶子节点。
				if(k > n) {
					break;
				}
			}
		}
		cout << k / 2 << endl;
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