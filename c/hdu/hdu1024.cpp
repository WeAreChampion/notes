/*hdu1024
状态dp[i][j]有前j个数，组成i组的和的最大值。决策： 
第j个数，是在第包含在第i组里面，还是自己独立成组。
方程 dp[i][j]=Max(dp[i][j-1]+a[j] , max( dp[i-1][k] ) + a[j] ) 0<k<j
空间复杂度，m未知，n<=1000000，继续滚动数组。 
时间复杂度 n^3. n<=1000000.  显然会超时，继续优化。
max( dp[i-1][k] ) 就是上一组 0....j-1 的最大值。
我们可以在每次计算dp[i][j]的时候记录下前j个的最大值 
用数组保存下来  下次计算的时候可以用，这样时间复杂度为 n^2.
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
		//快速设置数组的初值 
		memset(pre ,0 ,sizeof (pre)) ;
		memset(now ,0 ,sizeof (now)) ;
		
		//最大M子段和
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