/*hdu1024
״̬dp[i][j]��ǰj���������i��ĺ͵����ֵ�����ߣ� 
��j���������ڵڰ����ڵ�i�����棬�����Լ��������顣
���� dp[i][j]=Max(dp[i][j-1]+a[j] , max( dp[i-1][k] ) + a[j] ) 0<k<j
�ռ临�Ӷȣ�mδ֪��n<=1000000�������������顣 
ʱ�临�Ӷ� n^3. n<=1000000.  ��Ȼ�ᳬʱ�������Ż���
max( dp[i-1][k] ) ������һ�� 0....j-1 �����ֵ��
���ǿ�����ÿ�μ���dp[i][j]��ʱ���¼��ǰj�������ֵ 
�����鱣������  �´μ����ʱ������ã�����ʱ�临�Ӷ�Ϊ n^2.
*/ 
#include <stdio.h>
#include <string.h>
int num[1000050], pre[1000050], now[1000050];
int main ()
{
    long int m , n, max_pre;
    while (scanf("%d%d", &m, &n) != EOF) {
		for (int i = 1 ;i <= n; i++)
			scanf("%d", &num[i]); 
		//������������ĳ�ֵ 
		memset(pre ,0 ,sizeof (pre)) ;
		memset(now ,0 ,sizeof (now)) ;
		
		//���M�Ӷκ�
		for (int i = 1 ;i <= m ;i++) {
			max_pre = -9999999;
			for (int j = i ;j <= n ;j++) {
				//now[j] = max(now[j - 1] + num[j] ,pre[j - 1] + num[j]);
				now[j] = (now[j - 1] > pre[j - 1] ? now[j - 1] : pre[j - 1]) + num[j];
				pre[j - 1] = max_pre;
				if (now[j] > max_pre)
					max_pre = now[j];   
			}
		}
		printf("%ld\n",max_pre);
    }
    return 0;
}
/*
Sample Input
//m n
1 3 1 2 3
2 6 -1 4 -2 3 -2 3


Sample Output
6
8
*/ 