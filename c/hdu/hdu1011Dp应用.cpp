/*
是有n个洞组成一棵树，你有m个士兵，你从1号房间开始攻打，
每个洞有a个"bugs"和b的价值。你的一个士兵可以打20个"bugs"，
为了拿到这个洞的价值b你必须留下k个士兵消灭这个洞的所有"bugs"
（k*20>="bugs"的数量，且留下的士兵不可以再去攻打其他的洞，
且必须攻打了前面的洞才可以攻打后面的洞）。问你花费这m个士
兵可以得到的最大价值是多少。 
dp方程：
dp[p][j]=max(dp[p][j],dp[p][j-k]+dp[ son[p] ][ k ])
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
const int Ni = 110;
int n, m;
int cos[Ni], weg[Ni];
int dp[Ni][Ni];
bool vis[Ni];
vector<int> dv[Ni];
inline int max(int a, int b){
	return a > b ? a : b;
}//get max value
void dfs(int p)
{
    int i, j, k;
    int temp = (cos[p] + 19) / 20;
    for(i = temp; i <= m; i++) 
		dp[p][i] = weg[p];
    vis[p] = 1;
    for(i = 0; i < dv[p].size(); i++)
    {
        int t = dv[p][i];
        if(vis[t]) {
			continue;
		} 
        dfs(t);		//recursion
        for(j = m; j >= temp; j--)
        {
            for(k = 1; k <= j - temp; k++)//留下temp攻打p
                dp[p][j] = max(dp[p][j], dp[p][j - k] + dp[t][k]);
        }
    }
}
int main()
{
    int i;
    while(scanf("%d%d", &n, &m), n != -1|| m != -1)
    {
        for(i = 0; i <= n; i++) { //init the vector array
			dv[i].clear();
		} 
        memset(dp, 0, sizeof(dp));//quick set the array dp is 0
        memset(vis, 0, sizeof(vis));//quick set the array vis is 0
        for(i = 1; i <= n; i++)
            scanf("%d%d", cos + i, weg + i);//input the data by adress
        for(i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            dv[u].push_back(v);
            dv[v].push_back(u);
        }
        if(m == 0) 
		{
			printf("0\n");
			continue;
		}
        dfs(1);
        printf("%d\n", dp[1][m]);
    }
    return 0;
}
/*
Input:
5 10
50 10
40 10
40 20
65 30
70 30
1 2
1 3
2 4
2 5
1 1
20 7
-1 -1
output:
50
7 
 */