#include<iostream>
using namespace std;
/*
��ŵ�����⣬a[n] = 3a[n-1] + 2;a[1] = 2;
�������������ֱ�Ӵ�����߻����ұ��Ƶ����ұ߻������
*/
long long array[36];
void initArray() {
	array[1] = 2;
	for(int i = 2; i <= 35; i++) {
		array[i] = array[i - 1] * 3 + 2;
	}
}
long long getCounts(int n) {
	return array[n];
}
int main() {
	initArray();
	int n;
	while(scanf("%d", &n) != EOF) {
		cout << getCounts(n) << endl;
	}
	return 0;
}