#include<stdio.h>
/*
	递归求最大公约数 
*/ 
int GCD(int a, int b)
{
	int t;
	if(a < b) {
		t = a;
		a = b;
		b = t;
	}
	if(a % b == 0)
		return b;
	else { 
		return GCD(b, a % b);
	} 
}
int main()
{
	int t, a, b, c, d, e, f, gcd;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		//a / b + c / d = (ad + bc) / (bd) 
		e = a * d + b * c;
		f = b * d;
		gcd = GCD(e, f);
		printf("%d %d\n", e / gcd, f / gcd);
	}
	return 0;
}
/*
Sample Input
2
1 2 1 3
4 3 2 3
 

Sample Output
5 6
2 1

*/