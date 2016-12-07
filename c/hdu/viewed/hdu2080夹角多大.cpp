#include <stdio.h>
#include <math.h>

#define PI 3.141592654
/*
	求两点同原点连接的直线的夹角
*/
int main() {
	double x1, x2, y1, y2, c;
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		
		// is on a line
		if(!y1 && !y2 && x1 / y1 - x2 / y2 < 0.000001) {
			printf("0.00\n");
			continue;
		}
		c = acos((x1 * x2 + y1 * y2) / (sqrt(x2 * x2 + y2 * y2) * sqrt(x1 * x1 + y1 * y1))) * 180 / PI;
		printf("%.2lf\n", c);
		// PI / 180 * h = c
		//h = c * 180 / pi
	}
	return 0;
}
/*
Sample Input
2
1 1 2 2
1 1 1 0

 

Sample Output

0.00
45.00


*/