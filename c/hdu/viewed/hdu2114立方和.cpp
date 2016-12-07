#include<iostream>
using namespace std;
int main()
{
	__int64 s, n;
	while(scanf("%I64d", &n) != EOF) {
		n = n % 10000;
		s = (n * n * (n + 1) * (n + 1) / 4) % 10000;
		printf("%04I64d\n", s);
	}
	return 0;
}
