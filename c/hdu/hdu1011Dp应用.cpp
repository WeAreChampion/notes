/*
����n�������һ����������m��ʿ�������1�ŷ��俪ʼ����
ÿ������a��"bugs"��b�ļ�ֵ�����һ��ʿ�����Դ�20��"bugs"��
Ϊ���õ�������ļ�ֵb���������k��ʿ�����������������"bugs"
��k*20>="bugs"�������������µ�ʿ����������ȥ���������Ķ���
�ұ��빥����ǰ��Ķ��ſ��Թ������Ķ��������㻨����m��ʿ
�����Եõ�������ֵ�Ƕ��١� 
dp���̣�
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
            for(k = 1; k <= j - temp; k++)//����temp����p
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