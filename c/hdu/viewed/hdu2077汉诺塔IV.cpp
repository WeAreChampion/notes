#include<iostream>
using namespace std;
#include<cmath>
void test() {
	int ca;
	cin >> ca;
	while(ca--) {
		int n;
		cin >> n;
		int value = pow(3.0, (double)(n - 1)) + 1;
		cout << value << endl;
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
2
1
10

 

Sample Output
2
19684
*/