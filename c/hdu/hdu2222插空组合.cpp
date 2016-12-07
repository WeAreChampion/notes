#include<stdio.h>
/*
	假设n个人的ac数量按从小到大排列，可以从中任选m个人(n=>m>=2)，
	再把这m个人分2组(每个人都要分组)，要是满足最小ac数大于最大ac数，只需要在m
	个人中插板即可。例如： 
	m个人假如分别为 ： 1，2，3，4，......m-1，m (m个人的ac数从小到大排列) 
	只需在任意位置插板就可分为符合要求的2组：1，2，3......t， || t+1...m-1，m (1<=t<m) 
	则 1，2，3......t 为一组;t+1，t+2，......m-1，m 为一组 
	很明显这样分组符合要求，在这m人中共有m-1种分法(t取不同值)
*/
/*
	To get C(m, n)
*/
__int64 cal(__int64 m, __int64 n)
{
	__int64 s = 1, i;
    for(i = 1; i <= m; i++)
        s = s * (n - i + 1) / i;
    return s;
}
int main( )
{
    __int64 n, sum, i;
    while(~scanf("%I64d", &n)) {
        sum = 0;
        for(i = 2; i <= n; i++)
            sum += (i - 1) * cal(i, n);
        printf("%I64d\n", sum);
    }
    return 0;
}
/*
Sample Input
2
4

Sample Output
1
17

*/