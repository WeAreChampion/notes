#include<iostream>
using namespace std;
/*
汉诺塔问题，a[n] = 3a[n-1] + 2;a[1] = 2;
添加条件：不能直接从最左边或最右边移到最右边或最左边
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