#include "stdio.h"
#include "stdlib.h"  // srand  
#include "time.h"    // time  
#include "string.h"  // memset  

// 最大的数据是100万， 1000000
#define MAX_NUM  1000*1000

// 出现频率的个数
#define OVER_VAR  2

// 记录1-9这几个数字出现的次数，是否出现超过2次，
// 如果超过2次可以不用判断，初始化为0
unsigned char g_abyNumAry[10];

// 记录总共出现超过3次的数字的个数，当超过7个时，即为8时。
// 则可以直接打印出没有出现超过2次的那个数字，就一定是公出现2次的数字了。
unsigned char g_nCount = 0;
int main()
{
	int nIdx;
	int nData;
	time_t nCurTime;
	srand(time(&nCurTime));
	memset(g_abyNumAry, 0, sizeof(g_abyNumAry));
	for (nIdx = 0; nIdx < MAX_NUM; nIdx++) {
		nData = rand() % 9 + 1; // 随机数从1到9，测试专用，jernymy from 1-9
		printf("%d ", nData); // 打印该随机数字
		// 此数字出现次数大于2次，则退出次循环
		if (g_abyNumAry[nData] > OVER_VAR) {
			continue;
		}
		// 此数字出现1次，在大于2次时，就对总个数加1
		if (++g_abyNumAry[nData] > OVER_VAR) {
			g_nCount++;
		}
		// 当有8个数字出现的个数均超过2次，
		// 那么剩下的那个数字一定就是要求的了
		if (g_nCount == 8) {
			printf("\nfound only 2 num: ");
			for (nIdx = 1; nIdx < 10; nIdx++) {
				if (OVER_VAR >= g_abyNumAry[nIdx]) { // 20110820 modify
					// jernymy 此数就是我们要找的那个了
					printf("%d\n", nIdx);
					break;
				}
			}
			break;
		}
	}
	// 当没有8个数字出现的个数均超过2次，
	// 那么求出仅出现2次的那个数字即可
	if (g_nCount < 8) {
		printf("\nfound only 2 num: ");
		for (nIdx = 1; nIdx < 10; nIdx++) {
			if (OVER_VAR == g_abyNumAry[nIdx]) {
				// jernymy 此数就是我们要找的那个了
				printf("%d\n", nIdx);
				break;
			}
		}
	}
	return 0;
}