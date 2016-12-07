#include<iostream>
using namespace std;
/**
	num[i] = value表示为i时的半数集数量value
	初始化为0
*/
int a[201] = {0};
/**
	产生不重复的半数集数量并返回。
	1. 如27，集合中有两个重复的数1227，可以是1 + 2 + 27，也可以
12 + 27，但是只能算一个。因为0 < n < 201，所以加上去的数肯
定<=100，显然+100不会引起重复，所以只要考虑2位数的情
况。
	2. 分治递归思想：设计一函数prog(n)表示n产生的半数集合
元素个数，0<n<201。prog(1) = 1，令prog = s(1)+s(2)+...
+s(i),1<=i<=n/2.
	3. 当0<i<=9时，s(i) = prog(i)。
当i>9且i的十位数比个位数的一半小(即i / 10 < (i % 10) / 2)
时，s(i) = prog(i) - prog(i div 10).
*/
int prog(int k)
{
	int i, s;
	if(k == 1) {
		return 1;
	} else {
		// 需要重新计算
		if(a[k] == 0) {
			// 初始化为1
			s = 1;
			// 枚举所有小于等于k的一半，1 - (k / 2)间所有的数
			for(i = 1; i <= k / 2; i++) {
				s += prog(i);
				// 当i>10且i的十位数比个位数的一半小
				if(i > 10 && (i / 10 <= (i % 10) / 2)) {
					// 减去重复计算
					s -= prog(i / 10);
				}
			}
			// 保存值
			a[k] = s;
		}
		// 直接返回
		return a[k];
	}
}
int main()
{
	int n;
	while(cin >> n) {
		cout << prog(n) << endl;
	}
	return 0;
}