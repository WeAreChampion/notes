#include<iostream>
using namespace std;
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca--) {
			double u, v, w, l;
			cin>>u >>v >> w >>l;
			printf("%.3lf\n", l / (u + v) * w);
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
1
10 20 30 100
 

Sample Output
100.000

*/ 