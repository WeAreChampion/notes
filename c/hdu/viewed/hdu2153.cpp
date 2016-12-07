#include <stdio.h>
int main()
{
	int n, i, j;
	while (~scanf("%d", &n), n) {
		for(i = 1; i <= n; i++)
			printf("%3d", i);
		printf("\n");
		for(i = 2; i < n; i++) {
			printf("%3d", 4 * n - 2 - i);
			for(j = 0; j < 3 * (n - 2); j++)
				printf(" ");
			printf("%3d\n", n + i - 1);
		}
		if(n != 1) {
			for(i = 3 * n - 2; i >= 2 * n - 1; i--) {
				printf("%3d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
