#include<iostream>
using namespace std;
/*
	求m和n的平均数
*/
int getAverage(int m, int n){
	return (m + n) >> 1;
}
/*
	求m和n的平均数
	(m ^ n) >> 1 -> 获得m和n两个数中一个数的某些位为1的一半
	m & n -> 获得m和n两个数中都为1的某些位
*/
int getAverage_2(int m, int n){
	return ((m ^ n) >> 1) + (m & n);
}
void test() {
	cout << getAverage(1, 4) << endl;
	cout << getAverage(2, 4) << endl;
	cout << getAverage(3, 4) << endl;
	
	cout << getAverage_2(1, 4) << endl;
	cout << getAverage_2(2, 4) << endl;
	cout << getAverage_2(3, 4) << endl;
}
int main() {
	test();
	return 0;
}