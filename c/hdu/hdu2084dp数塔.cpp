#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[105][105],dp[105][105];
/*
dp 数塔，从下往上依次计算，取最大值往上计算，最后输出dp[n] 

*/ 
int main() {
    int t, n, i,j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        //input the data
        for(i = 1;i <= n; i++) {
            for(j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
        }
        for(i = n;i >= 1;i--) {
            for(j = 1; j <= i; j++) {
            	/*
					To get the max between dp[i + 1] and dp[i + 1][j + 1]
					and get the sum
            	
            	*/
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
            }
        }
        printf("%d\n", dp[1][1]);
    }
    return 0;
}
/*
Sample Input

1
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5

 

Sample Output

30
*/ 