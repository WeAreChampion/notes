#include<iostream>
using namespace std;
/*
 1^2+3^2+5^2+бнбн+ n ^2
*/ 
int main()
{
	__int64 n, sum;
	while(scanf("%I64d", &n) != EOF) {
		if(n % 2) {
			sum = n * (n + 1) * (n + 2) / 6;
			printf("%I64d\n", sum);
		}
	}
	return 0;
}
