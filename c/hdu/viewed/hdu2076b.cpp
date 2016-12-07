#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, h, m, s, t;
	double des;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d%d",&h,&m,&s);
		if(h > 12)
			h = h - 12;
		des = fabs(30 * h - 11.0 * m / 2- 11.0 * s / 120);
		if(des > 180) {
			t = (int)360 - des;
		} else {
			t = (int) des;
		}
		printf("%d\n", t);
	}
	return 0;
}