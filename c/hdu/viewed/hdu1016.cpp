/*
hdu 1016 Prime Ring Problem
有点字典树的感觉，父节点与子节点的和为素数
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool prim[40];
int num[25];
bool used[25]; //标记是否使用 
//筛法
void is_prim()
{
    memset(prim, 0, sizeof(prim));
    prim[0] = prim[1] = 1;
    int sq = sqrt((double) 40);
    for(int i = 2; i < sq; i++) { 
        for(int j = i * i; j < 40; j += i) { 
            prim[j] = 1;
        }
	} 
}
void dfs(int root, int n, int t) {
    //数组从1开始，共n个数，当t>n时，说明n个数已排好序
    if(t > n && !prim[num[n] + num[1]]) {
        for(int j = 1; j < n; j++) { 
            printf("%d ", num[j]);
        } 
        printf("%d\n", num[n]);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!prim[root + i] && !used[i]) {
            num[t] = i;
            used[i] = 1;
            dfs(i, n, t + 1);
            used[i] = 0;
        }
    }
}
int main()
{
    is_prim();
    int n;
    int cas = 1;
    while(scanf("%d", &n) != EOF) {
        memset(used, 0, sizeof(used));
        printf("Case %d:\n", cas++);
        num[1] = 1;//第一个数一定是1
        used[1] = 1;
        dfs(1, n, 2);
        used[1] = 0;
        printf("\n");

	}
    return 0;
}