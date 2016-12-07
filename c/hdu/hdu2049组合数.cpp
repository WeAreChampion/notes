#include<stdio.h>
/*
	组合数公式 C(n, m)(n个选m个)
*/
__int64 C(int n, int m) {
	__int64 u, d, i;         
	if(m > n / 2) {
		m = n - m;
	}
	for(u = d = i = 1; i <= m; i++) {
		u = u * (n - i + 1);
		d = d * i;
	}
	return u / d;
}

int main()
{
	int i, M, N, T;
	__int64 f[21] = {1, 0, 1}, sum;
	for(i = 3; i <= 20; i++){
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	}
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d",&N, &M);
		printf("%I64d\n", C(N, M) * f[M]);
	}
}