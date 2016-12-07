#include<stdio.h>
/**
	给定一个自然数n，由n开始，在n的左边加上一个自然数，但该自然数
	不能超过最近添加的数的一半；以此，直到不能再添加自然数为止。
	如：set(6) = {6, 16, 26, 126, 36, 136}
*/
/**
	num[i] = value表示为i时的半数集数量value
	初始化为0
*/
int num[1000] = {0};
/**
	统计半数集的元素个数
*/
int Count(int n)
{
	int i = 0;
	int count = 1;
	
	// 枚举1 - (n / 2) 所有的数字,该数不超过n的一半
	for(i = 1; i <= n / 2; i++) {
		// 不为0，直接累加，避免重复计算
		if(num[i] != 0) {
			count += num[i];
		}
		else {// num[i]为0，需要重新计算
			
			// 统计i的半数集个数
			int value = Count(i);
			
			// 存储在num数组中
			num[i] = value;
			
			// 统计半数集数量到count
			count += value;
		}
	}
	return count;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", Count(n));
	}
	return 0;
}
/**
Input:
6

Output:
6

*/