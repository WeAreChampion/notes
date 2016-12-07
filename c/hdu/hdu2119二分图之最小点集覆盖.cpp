#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
/*
给一个矩阵，矩阵点值为0或1，每次可以将矩阵的一行或一列 全变成0 ，
问最少需要多少次，可以使矩阵的点全为0.
思路：讲矩阵点值为1的点的横纵坐标问边建二分图，求二分图的最小点集覆盖。
最小覆盖要求用最少的点（Ｘ集合或Ｙ集合的都行）让每条边都至少和其中一个点
关联。可以证明：最少的点（即覆盖数）＝最大匹配数 M
简单的证明如下：
（1）M个是足够的。只需要让它们覆盖最大匹配的M条边，则其它边一定被覆盖
（如果有边e不被覆盖，把e加入后得到一个更大的匹配）
（2）M个是必需的，仅考虑形成最大匹配的这M条边，由于它们两两之间没有公
共点，因此至少需要M个点才可以把它们覆盖
*/
#define MAXN 110
#define MAXM 110*110

struct Edge
{
    int v, next;
}edge[MAXM];

int n, m;
int cnt;
int tot;

int first[MAXN], link[MAXN];
bool vis[MAXN];

void init() {
    cnt = 0;
    tot = 0;
    memset(first, -1, sizeof(first));
    memset(link, -1, sizeof(link));
}

void read_graph(int u, int v)
{
    edge[cnt].v = v;
    edge[cnt].next = first[u];
	first[u] = cnt++;
}
int ED(int u)
{
    for(int e = first[u]; e != -1; e = edge[e].next) {
        int v = edge[e].v;
        if(!vis[v])
        {
            vis[v] = true;
            if(link[v] == -1 || ED(link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        if(ED(i))
			ans++;
    }
    printf("%d\n", ans);
}
int main()
{
    while(scanf("%d", &n) && n) {
        init();
        scanf("%d", &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                int map;
                scanf("%d", &map);
                if(map)
                {
                    read_graph(i, j);
                }
            }
        }
        solve();
    }
    return 0;
}
/*
Sample Input
3 3 
0 0 0
1 0 1
0 1 0
0
 

Sample Output
2
*/