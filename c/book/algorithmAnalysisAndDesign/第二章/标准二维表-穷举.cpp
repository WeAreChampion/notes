#include <iostream>
#define MAX 100
using namespace std;
/**
	设n 是一个正整数。2xn的标准2维表是由正整数1，2，…，2n 组成的2xn
	数组，该数组的每行从左到右递增，每列从上到下递增。2xn的标准2维表
	全体记为Tab(n)。
*/
int a[2][MAX];
int count = 0;
/**
	穷举法求解二维表
	枚举整数n，即共有1-2n个数
	k表示当前第k个数
*/
void tab(int n, int k)
{
	// 最后一个格子
	if(k == 2 * n) {
		count++;
		return;
	}

	// 依次枚举
	for(int i = k % n + 1; i <= n * 2; i++) {

		// 得到行号
		int x = k / n;

		// 得到列号
		int y = k % n;

		// 当前行列的值为i
		a[x][y] = i;

		// 标志位，初始化为true
		bool ok = true;
		for(int j = 0 ; j < k ; j++) {

			//
			if(a[x][y] == a[j / n][j % n]
			    || (a[x - 1][y] > a[x][y] && x == 1)
			    || (a[x][y - 1] > a[x][y] && y > 0)) {
				ok = false;
				break;
			}
		}

		// 满足条件，继续下一步搜索
		if(ok) {
			tab(n , k + 1);
		}
	}
}
/**
	catalan数
	令h(0)=1,h(1)=1，catalan数满足递推式[1]：
	h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)
	例如：h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
	h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5
	另类递推式[2]：
	h(n)=h(n-1)*(4*n-2)/(n+1);
	递推关系的解为：
	h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
	递推关系的另类解为：
	h(n)=c(2n,n)-c(2n,n+1)(n=0,1,2,...)
*/
int catalan(int n)
{
	if(n <= 1) {
		return 1;
	}
	int *h = new int[n + 1];
	h[0] = h[1] = 1;
	for(int i = 2; i <= n; i++) {
		h[i] = 0;
		for(int j = 0; j < i; j++) {
			h[i] += h[j] * h[i - j - 1];
		}
	}
	int result = h[n];
	delete []h;
	return result;
}
int main()
{
	int n;
	while(cin >> n) {
		tab(n, 0);
		cout << count << endl;
		cout << catalan(n) << endl;
		count = 0;
	}
	return 0;
}
/**
Input:
3

Output:
5

*/