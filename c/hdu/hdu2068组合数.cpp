#include<stdio.h>
/*
n��Ů�������һ������������ȷ������أ������ж��������ʹ��˳������
*/
/*
	�������ʽ C(n, m)(n��ѡm��)
*/
__int64 C(int n, int m) {
	__int64 u, d, i;         //�������ʽ�е� ����u�ͷ�ĸd
	if(m > n / 2) {
		m = n - m;
	}                    //��ֹ��� 
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