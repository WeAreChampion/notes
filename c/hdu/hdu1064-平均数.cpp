#include<stdio.h>
int main()
{
	int i;
	double a, s;
	s = 0;
	for(i = 1; i <= 12; i++) {
		scanf("%lf", &a);
		s += a;
	}
	printf("$%.2lf\n", s / 12);
	return 0;
}
/*

Sample Input
100.00 
489.12 
12454.12 
1234.10 
823.05 
109.20 
5.27 
1542.25 
839.18 
83.99 
1295.01 
1.75
 

Sample Output
$1581.42
*/