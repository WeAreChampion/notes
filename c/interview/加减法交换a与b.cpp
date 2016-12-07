#include<iostream>
using namespace std;
void swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void test() {
	int a = 3;
	int b = 4;
	
	cout << "a = " << a << ", b = " << b << endl;
	
	swap(a, b);
	
	cout << "a = " << a << ", b = " << b << endl;
}
int main() {
	test();
	return 0;
}