#include<iostream>
#include<cmath>
/*
汉诺塔。用1,2,...,n表示n个盘子，称为1号盘，2号盘,....号数大盘子就大。
是盘子的数目N(1<=N<=60)和盘号k(1<=k<=N)。

*/
using namespace std;
void test() {
	int ca, n, k;
	cin >> ca;
	while(ca--) {
		cin >> n >> k;
        printf("%I64d\n",(__int64)pow(2.0, n - k));
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input

2
60 1
3 1


Sample Output

576460752303423488
4
*/