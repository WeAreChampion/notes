#include<iostream>
#include<cmath>
using namespace std;
double getValue(double x, double y, double m, double n)
{
	return sqrt(x * x + y * y + m * m + n * n - 2 * m * x - 2 * n * y );
}
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca--) {
			double a, b, c, d;
			cin>> a >> b >> c >>d;
			printf("%.1lf\n", getValue(a, b, c, d));
		}
	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
2
0 0 3 4
4 0 0 3
 

Sample Output
5.0
5.0

*/