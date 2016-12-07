#include<iostream>
using namespace std;
int getMax(int a, int b) {
	return a > b ? a : b;
}
/*
	获取数组中最先出现的最大元素下标
*/
int getMaxIndex(int array[], int length) {
	int index = 0;
	int max = 0;
	for(int i = 0; i < length; i++) {
		if(max < array[i]) {
			max = array[i];
			index = i;
		}
	}
	return index;
}
/*
	求不包含index位置数组的平方和
*/
int getSum(int array[], int length, int index) {
	int sum = 0;
	for(int i = 0; i < length; i++) {
		if(i != index) {
			sum += array[i] * array[i];
		}
	}
	return sum;
}
/*
	判断是否为直角三角形
*/
bool isAncle(int array[], int length, int index) {
	if(getSum(array, length, index) == array[index] * array[index]) {
		return true;
	}
	return false;
}
void test() {
	
	int ca;
	cin >> ca;
	int array[3];
	int counts = 0;
	while(ca--) {
		counts++;
		cin >> array[0] >> array[1] >> array[2];
		cout << "Scenario #" << counts << ":" << endl;
		if(isAncle(array, 3, getMaxIndex(array, 3))) {
			cout << "yes" << endl << endl;
		} else {
			cout << "no" << endl << endl;
		}
		
	}
}
int main() {
	test();
	return 0;
}
/*
2
36 77 85
40 55 69
 

Sample Output
Scenario #1:
yes

Scenario #2:
no
*/