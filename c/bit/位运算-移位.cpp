#include<iostream>
using namespace std;
/*
	n左移m位，返回移位后的值
	value is equal n * pow(2, m)
*/
int goLeft(int n, int m) {
	return n << m;
}
void testGoLeft() {
	cout << "Test Go Left :" << endl;
	
	//value is 20
	cout << "5<<2 =  " << goLeft(5, 2) << endl;
	
	//value is -20
	cout << "-5<<2 =  " << goLeft(-5, 2) << endl;
}
/*
	n右移m位，返回移位后的值
	value is equal n / pow(2, m)
*/
int goRight(int n, int m) {
	return n >> m;
}
void testGoRight() {
	cout << "Test Go Right :" << endl;
	
	//value is 1
	cout << "5>>2 =  " << goRight(5, 2) << endl;
	
	//value is -2
	cout << "-5>>2 =  " << goRight(-5, 2) << endl;
}
/*
a = a << 1;
a <<= 1; //a左移一位等效于a = a * 2;
a = a * 2;


a = a << 2;
a <<= 2; //a左移2位等效于a = a * 2的2次方(4);
a = a * 4;
*/
void test() {
	testGoLeft();
	testGoRight();
	
	int a = 2;
	
	//a << = 1 is error
	a <<= 1;
	cout << "a = " << a << endl;
	
	a >>= 2;
	cout << "a = " << a << endl;
}
int main() {
	test();
	return 0;
}