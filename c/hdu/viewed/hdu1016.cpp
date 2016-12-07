/*
hdu 1016 Prime Ring Problem
�е��ֵ����ĸо������ڵ����ӽڵ�ĺ�Ϊ����
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool prim[40];
int num[25];
bool used[25]; //����Ƿ�ʹ�� 
//ɸ��
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
    //�����1��ʼ����n��������t>nʱ��˵��n�������ź���
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
        num[1] = 1;//��һ����һ����1
        used[1] = 1;
        dfs(1, n, 2);
        used[1] = 0;
        printf("\n");

	}
    return 0;
}