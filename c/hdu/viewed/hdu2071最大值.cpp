#include <stdio.h>
int main()
{
	int t, n;
	double h, maxh;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		scanf("%lf", &h);
		maxh = h;
		n--;
		while(n--) {
			scanf("%lf", &h);
			if(maxh < h) { 
				maxh = h;
			} 
		}
		printf("%.2lf\n", maxh);
	}
	return 0;
}