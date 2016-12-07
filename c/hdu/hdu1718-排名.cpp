#include <stdio.h>
/*
	Tn = O(N)
	Sn = O(N)
*/
int main()
{
	int gd;
	int a[1100], b[1100];
	int i;
	while(~scanf("%d", &gd)) {
		int cnt = 0;
		
		//input the data
		while(scanf("%d%d", a + cnt, b + cnt),(a[cnt] || b[cnt]))
			cnt++;
		
		//find the pos
		for(i = 0; i < cnt; i++)
			if(gd == a[i])//学号相同
				gd = i;
		int ans = 1;
		for(i = 0; i < cnt; i++)
			if(b[i] > b[gd])//查找成绩比其大的
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
/*
Sample Input
20070101
20070102 100
20070101 33
20070103 22
20070106 33
0 0

20070103
20070102 100
20070101 33
20070103 22
20070106 33
0 0

20070106
20070102 100
20070101 33
20070103 22
20070106 33
0 0

Sample Output
2
*/