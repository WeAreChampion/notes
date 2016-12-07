#include<stdio.h>
/*
n个女生，答对一半或以上组合正确就算过关，请问有多少组答案能使他顺利过关
*/
/*
	组合数公式 C(n, m)(n个选m个)
*/
__int64 C(int n, int m) {
	__int64 u, d, i;         //组合数公式中的 分子u和分母d
	if(m > n / 2) {
		m = n - m;
	}                    //防止溢出 
	for(u = d = i = 1; i <= m; i++) {
		u = u * (n - i + 1);
		d = d * i;
	}
	return u / d;
}
int main() {
	int i, M, N;
	__int64 f[14] = {1, 0, 1}, sum;
	for(i = 3; i <= 13; i++)
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	while(scanf("%d", &N), N) {
		// To get the sum
		for(sum = i = 0; i <= N / 2; i++) {
			sum += C(N, N - i) * f[i];
		}
		printf("%I64d\n", sum);
		
	}
}
/*
Sample Input
1
2
0

 

Sample Output

1
1
*/ 