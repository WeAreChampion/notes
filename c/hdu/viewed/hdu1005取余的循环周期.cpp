/*
A number sequence is defined as follows:
f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
Given A, B, and n, you are to calculate the value of f(n).
找规律，即重复出现，计算周期。
凡是没有优化的话，超时超内存等等是避免不了的了。
这题很显然是一个找规律的题目，也就是该题的求解
中是存在循环节的。
对于公式 f[n] = A * f[n-1] + B * f[n-2]; 后者
只有7 * 7 = 49 种可能，为什么这么说，因为对于
f[n-1] 或者 f[n-2] 的取值只有 0,1,2,3,4,5,6
这7个数，A，B又是固定的，所以就只有49种可能值
了。由该关系式得知每一项只与前两项发生关系，所
以当连续的两项在前面出现过循环节出现了，注意循
环节并不一定会是开始的 1，1 。 又因为一组测试
数据中f[n]只有49中可能的答案，最坏的情况是所有
的情况都遇到了，那么那也会在50次运算中产生循环节
。找到循环节后，就可以轻松解决了。
*/
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int rec[60];
int main()
{
	int a, b, n;
	rec[0] = rec[1] = rec[2] = 1;
	while(scanf( "%d %d %d", &a, &b, &n ), a | b | n) {
		int beg, end, flag = 0;
		for(int i = 3; i <= n && !flag; ++i) {
			//To calculate f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7
			rec[i] = ( a * rec[i - 1] + b * rec[i - 2] ) % 7;
			//向前寻找值，若出现重复则结束
			for(int j = 2; j <= i - 1; ++j) {
				if(rec[i] == rec[j] && rec[i - 1] == rec[j - 1]) {
					beg = j, end = i;
					flag = 1;
					break;
				}
			}
		}
		//The circle is end - beg
		if(flag) {
			printf("%d\n", rec[beg + (n - end) % (end - beg)]);
		} else {
			printf("%d\n", rec[n]);
		}
	}
	return 0;
}
/*
Sample Input
1 1 3
1 2 10
0 0 0

Sample Output
2
5

*/