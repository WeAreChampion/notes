#include<iostream>
using namespace std;
/**
	1. n个元素{1,2,……, n}有n!个不同的排列。将这n!个排列按字典序排列，
	并编号为0，1，…，n!-1。每个排列的编号为其字典序值。例如，当n=3时，
	6 个不同排列的字典序值如下：

	2. 给定n以及n个元素{1,2,……, n }的一个排列，计算出这个排列的字典序值，
	以及按字典序排列的下一个排列。

	3. 输入数据的第1行是元素个数n（n≤20）。接下来的1行是n个元素 {1,2,……,
	n }的一个排列。

	4. 输出数据的第1行是字典序值，第2行是按字典序排列的下一个排列。
	
	5. 字典序值 0   1   2   3   4   5
		排列   123 132 213 231 312 321
*/

/**
	1. 计算字典值看
	看后面的数有多少个比自己小
	例： 对于数据：
	2 6 4 5 8 1 7 3
	tot = 0；
	比2小的数有1个，则 tot += 1*7！；
	比6小的数有4个，则 tot += 4*6！；
	比4小的数有2个，则 tot += 2*5！；
	比5小的数有2个，则 tot += 2*4！；
	比8小的数有3个，则 tot += 3*3！；
	比1小的数有0个，则 tot += 0*2！；
	比7小的数有1个，则 tot += 1*1！；
	比3小的数没有；

	2. 下一个排列。
	从数组尾部开始找相邻两个元素，满足order[i] < order[i + 1]，
	再从数组尾部开始找第一个大于order[i]的数order[k]（k>i），
	交换order[i]和order[k]，order[i+1]~order[n-1]进行逆向重排。
*/
#include<stdio.h>
#include<stdlib.h>

/**
	交换a, b的值
*/
void SWAP(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int n, i, k, j, t, order[100];
	int lis, f[100], mid, h;

	// 0! = 1;
	f[0] = 1;

	/**
		计算阶乘
		数组f[i] 保存i!(i的阶乘)
	*/
	for(i = 1; i <= 22; i++)
		f[i] = f[i - 1] * i;
	
	//
	while(scanf("%d", &n) != EOF) {

		// 输入字典序序列，存储在order中
		for(i = 0; i < n; i++)
			scanf("%d", &order[i]);

		// n为1，输出编号为0，下一个序列为1
		if(n == 1) {
			printf("0\n1\n");
		} else if(n >= 2) {
			
			// 计算字典序值
			lis = 0;
			for(i = 0, k = n - 1; i < n - 1; i++, k--) {
				t = 0;
				for(j = 0; j < i; j++)
					if(order[j] < order[i]) {
						t++;
					}
				lis += (order[i] - 1 - t) * f[k];
			}
			printf("%d\n", lis);

			
			// 找下一个序列
			for(i = n - 2; i >= 0; i--) {
				if(order[i] < order[i + 1]) {
					j = i;
					for(k = n - 1; k > j; k--) {
						if(order[k] > order[j]) {
							mid = j + (n - j) / 2;
							SWAP(&order[j], &order[k]);
							for(j++, h = 1; j <= mid; j++, h++)
								SWAP(&order[j], &order[n - h]);
						}
					}
					break;
				}
			}
			
			// 输出下一个序列
			for(i = 0; i < n - 1; i++)
				printf("%d ", order[i]);
			printf("%d\n", order[i]);
		}
	}
	return 0;
}
/**
Input:
8
2 6 4 5 8 1 7 3

Output:
8227
2 6 4 5 8 3 1 7


*/