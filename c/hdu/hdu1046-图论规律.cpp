#include <stdio.h>
#include <math.h>
/*
当n,m有一者能够为偶数时，结果是n*m
否者必有一条路需要斜着走，结果为n*m-1+1.41
*/
int main()
{
	int t, i = 1;
	scanf("%d", &t);
	while(t--) {
		double n, m;
		scanf("%lf%lf", &n, &m);
		printf("Scenario #%d:\n", i++);
		if((int) n % 2 ==0 || (int) m % 2==0) {
			printf("%.2lf\n", n * m);
		} else {//斜着走
			printf("%.2lf\n",n * m - 1 + sqrt(2.0));
		}
		printf("\n");
	}

	return 0;
}
