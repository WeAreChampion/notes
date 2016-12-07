#include<stdio.h>
int main()
{
	int i, n, sum, h, m, s, flag, t;
	char str[500];
	float d;
	
	//n(counts n time) and d(distance)
	scanf("%d%f", &n, &d);
	
	//t
	while(~scanf("%d", &t)) {
		flag = 1, sum = 0;
		for(i = 0; i < n && flag; i++) {
			//输入参数为3个
			if(scanf("%d:%d:%d", &h, &m, &s) == 3) {
				
				// 时间转化为妙
				sum += h * 3600 + m * 60 + s;
			} else {
				//读入字符串
				gets(str);
				
				//标记数据无效
				flag = 0;
			}
		}
		
		//数据是否有效
		if(flag) {
			sum = sum / d + 0.5;
			printf("%3d: %d:%02d min/km\n", t, sum / 60, sum % 60);
		} else {
			printf("%3d: -\n", t);
		}
	}
	return 0;
}
/*

Sample Input
2 12.5
  5 0:23:21 0:25:01
 42 0:23:32 -:--:--
  7 0:33:20 0:41:35
 

Sample Output
  5: 3:52 min/km
 42: -
  7: 6:00 min/km
*/