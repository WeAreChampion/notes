#include<iostream>
#include<cmath>
/*
��ŵ������1,2,...,n��ʾn�����ӣ���Ϊ1���̣�2����,....���������Ӿʹ�
�����ӵ���ĿN(1<=N<=60)���̺�k(1<=k<=N)��

*/
using namespace std;
void test() {
	int ca, n, k;
	cin >> ca;
	while(ca--) {
		cin >> n >> k;
        printf("%I64d\n",(__int64)pow(2.0, n - k));
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input

2
60 1
3 1


Sample Output

576460752303423488
4
*/