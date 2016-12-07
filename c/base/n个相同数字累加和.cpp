#include<iostream>
using namespace std;
/*
 * To get the sum like a+aa+aaa+..+aa..a.
 * And a has n counts.
 */
int getDigitalSum(int n, int element) {
	int an = element;
	int sum = element;
	for(int i = 2; i <= n; i++) {
		an = an * 10 + element;
		sum = sum + an;
	}
	return sum;
}
void test() {
	cout << getDigitalSum(2, 2) << endl;
	cout << getDigitalSum(2, 3) << endl;
	cout << getDigitalSum(3, 3) << endl;
	cout << getDigitalSum(4, 3) << endl;
}
int main() {
	test();
	return 0;
}
