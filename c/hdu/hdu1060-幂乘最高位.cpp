#include<iostream>
#include<cmath>
using namespace std;
/*
x是N^N的位数.实际上就是 x 就是lg(N^N) 向下取整数，表示为[lg(N^N)]
a = 10^(N*lg(N) - [lg(N^N)]);
*/
int main()
{
	int ncase;
	__int64 n, ans;
	long double t;
	scanf("%d", &ncase);
	while (ncase--) {
		scanf("%I64d", &n);
		
		//value nlog(n)
		t = n * log10(n + 0.0);
		
		//强转之后的整数[lg(N^N)]，并作差
		t -= (__int64) t;
		
		ans = pow((long double)10, t);
		printf("%I64d\n", ans);
	}
	return 0;
}