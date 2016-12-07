/*
给定一个从原点开始且中心在原点的半圆，每天以50mile^2的速度向外扩充，
给你一个点,求第几天扩充的半圆能覆盖到它。
*/
#include <stdio.h>
#define PI 3.1415926
int main()
{
	int t;
	double x, y;
	scanf("%d", &t);
	//have counts t case
	for(int i = 1; i <= t; ++i) {
		scanf("%lf%lf", &x, &y);
		//PI * R^2 = PI * (x * x + y * y)
		printf("Property %d: This property will begin eroding in year %d.\n", i, int((x * x + y * y) * PI / 100 + 1));
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
/*
Sample Input
2 
1.0 1.0 
25.0 0.0
 

Sample Output
Property 1: This property will begin eroding in year 1. 
Property 2: This property will begin eroding in year 20. 
END OF OUTPUT. 

*/