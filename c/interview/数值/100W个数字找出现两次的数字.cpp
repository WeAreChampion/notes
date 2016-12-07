#include "stdio.h"
#include "stdlib.h"  // srand  
#include "time.h"    // time  
#include "string.h"  // memset  

// ����������100�� 1000000
#define MAX_NUM  1000*1000

// ����Ƶ�ʵĸ���
#define OVER_VAR  2

// ��¼1-9�⼸�����ֳ��ֵĴ������Ƿ���ֳ���2�Σ�
// �������2�ο��Բ����жϣ���ʼ��Ϊ0
unsigned char g_abyNumAry[10];

// ��¼�ܹ����ֳ���3�ε����ֵĸ�����������7��ʱ����Ϊ8ʱ��
// �����ֱ�Ӵ�ӡ��û�г��ֳ���2�ε��Ǹ����֣���һ���ǹ�����2�ε������ˡ�
unsigned char g_nCount = 0;
int main()
{
	int nIdx;
	int nData;
	time_t nCurTime;
	srand(time(&nCurTime));
	memset(g_abyNumAry, 0, sizeof(g_abyNumAry));
	for (nIdx = 0; nIdx < MAX_NUM; nIdx++) {
		nData = rand() % 9 + 1; // �������1��9������ר�ã�jernymy from 1-9
		printf("%d ", nData); // ��ӡ���������
		// �����ֳ��ִ�������2�Σ����˳���ѭ��
		if (g_abyNumAry[nData] > OVER_VAR) {
			continue;
		}
		// �����ֳ���1�Σ��ڴ���2��ʱ���Ͷ��ܸ�����1
		if (++g_abyNumAry[nData] > OVER_VAR) {
			g_nCount++;
		}
		// ����8�����ֳ��ֵĸ���������2�Σ�
		// ��ôʣ�µ��Ǹ�����һ������Ҫ�����
		if (g_nCount == 8) {
			printf("\nfound only 2 num: ");
			for (nIdx = 1; nIdx < 10; nIdx++) {
				if (OVER_VAR >= g_abyNumAry[nIdx]) { // 20110820 modify
					// jernymy ������������Ҫ�ҵ��Ǹ���
					printf("%d\n", nIdx);
					break;
				}
			}
			break;
		}
	}
	// ��û��8�����ֳ��ֵĸ���������2�Σ�
	// ��ô���������2�ε��Ǹ����ּ���
	if (g_nCount < 8) {
		printf("\nfound only 2 num: ");
		for (nIdx = 1; nIdx < 10; nIdx++) {
			if (OVER_VAR == g_abyNumAry[nIdx]) {
				// jernymy ������������Ҫ�ҵ��Ǹ���
				printf("%d\n", nIdx);
				break;
			}
		}
	}
	return 0;
}