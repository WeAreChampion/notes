#include <iostream>
using namespace std;
__int64 dp[60];
int main(int argc, char *argv[])
{
    int n, i, a, b;
    dp[1] = 1;
    for(i = 1; i <= 50; i++) {
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i];
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &a, &b);
        b -= (a - 1);
        printf("%I64d\n", dp[b]);
    }
    return 0;
}
 

