#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int N;
struct matrix {
	int a[3][3];
} origin, res;
/**
	To calculate the matrix Z = X * Y and return
*/
matrix multiply(matrix x, matrix y)
{
	matrix temp;

	// quick set matrix temp 0
	memset(temp.a, 0, sizeof(temp.a));

	// multiply temp = x * y
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				temp.a[i][j] += x.a[i][k]*y.a[k][j];
			}
		}
	}
	return temp;
}
void init()
{
	// random set matrix origin
	printf("�����������:\n");
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			origin.a[i][j] = rand() % 10;
			printf("%8d", origin.a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// quick set matrix res 0
	memset(res.a, 0, sizeof(res.a));

	//��res.a��ʼ��Ϊ��λ����
	res.a[0][0] = res.a[1][1] = res.a[2][2] = 1;
}
/**
	��������ݳ�
	A^n = AAAA...A

*/
void calc(int n)//�����ݳ�
{
	int m = n;
	while(n) {
		// ����
		if(n & 1) {
			//	res = res I* origin
			res = multiply(res, origin);
		}
		// ����1λ���൱�� n = n / 2;
		n >>= 1;

		// origin = origin * origin
		origin = multiply(origin, origin);
	}

	// To output the result matrix res
	printf("%d���ݽ�����£�\n", m);
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			printf("%8d", res.a[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	while(cin >> N) {
		init();
		calc(N);
	}
	return 0;
}