#include<cstdio>  
#include<cstring>  
#include<queue>  
#include<vector>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
vector<int> V[1000];  
int link[1000], use[1000];
void init(int n) {  
    int i;  
    for(i = 0; i <= n; i++)  
      V[i].clear();  
}
/*
	DFS from v and return can dfs 
*/
bool Dfs(int v) {
    int i, j, k;
	
	//To dfs the array's column index where the row index is v
    for(i = 0; i < V[v].size(); i++) {
		
		// the next node
        k = V[v][i];
		
		//not visited
        if(!use[k]) {
            use[k] = 1;// visited the node
			
			//the node isn't linked or can search dfs from k 
            if(!link[k] || Dfs(link[k])) {
				// mark by node v that means can be linked by node v
                link[k] = v;
                return true;  
            }  
        }  
    }  
    return false;  
}
/*
	To get the max match
*/
int MaxMatch(int n) {  
    int i, j, ans = 0;
	
	//quick set array link
    memset(link, 0, sizeof(link));
	
	// For each all row
    for(i = 1; i <= n; i++) {
		//init the use array
        memset(use, 0, sizeof(use));
		
		// if can dfs that means can arrive then ans++;
        if(Dfs(i))
			ans++;
    }
    return ans;
}
int main()
{
    int i, j, n, m, k, t;
    while(scanf("%d", &n) && n) {
        scanf("%d", &m);
        init(n);
        k = 0;
        for(i = 1; i <= n; i++)
            for(j = 1;j <= m; j++) {
				scanf("%d",&t);
				if(t) {
					k++;
					V[i].push_back(j);  
				}  
			}
        int ans = MaxMatch(n);  
        printf("%d\n", ans);  
    }  
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