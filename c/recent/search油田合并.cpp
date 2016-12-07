#include<iostream>
#include <memory.h>
using namespace std;
/*
	对于所给的char数组，找出需要采集油田('@')的机器数量，
若油田间相邻接，则一台机器数量就可以。
*/
// the char array
char s[55][55];

//The visited mark
int map[55][55];
/*
	To dfs the char array and make the visited mark
*/
int dfs(int i, int j, int n, int m) {
	// To mark is visited
	map[i][j] = 1;
	
	// Go down search
	if(i + 1 < n && s[i + 1][j] == '@' && map[i + 1][j] == 0) {
		dfs(i + 1, j, n, m);
	}
	
	// Go right search
	if(j + 1 < m && s[i][j + 1] == '@' && map[i][j + 1] == 0) {
		dfs(i, j + 1, n, m);
	}
	
	// Go up search
	if(i - 1 >= 0 && s[i - 1][j] == '@' && map[i - 1][j] == 0) {
		dfs(i - 1, j, n, m);
	}
	// Go left search
	if(j - 1 >= 0 && s[i][j - 1] == '@' && map[i][j - 1] == 0) {
		dfs(i, j - 1, n, m);
	}
	return 1;
}
void test() {
	int m, n, many;
	while(cin >> n >> m) {
		many = 0;
		
		//quick set the map array with 0
		memset(map, 0, sizeof(map));
		//input array
		for(int i = 0; i < n; i++) {
			cin >> s[i];
		}
		
		// To search all node
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(map[i][j] == 0 && s[i][j] == '@') {
					many += dfs(i, j, n, m);
				}
			}
		}
		cout << many << endl;
	}
}
int main() {
	test();
	return 0;
}
/*
Input:
2 2
@*
*@
2 2
@@
@@

Output:
2
1

*/