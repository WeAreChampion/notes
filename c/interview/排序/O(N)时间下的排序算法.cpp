#include<iostream>
#include<cstring>
using namespace std;
#define MAX_VALUE 256
/*
	O(N)时间的排序算法，要求是数字比较小
*/
//display the element by times
void dispNumber(int element, int times)
{
	for(int i = 0; i < times; i++) {
		cout << element << " ";
	}
}
void sortInN(int array[], int length) {
	int *temp = new int[MAX_VALUE];
	//quick set the array's value with 0
	memset(temp, 0, sizeof(temp) * MAX_VALUE);
	int maxValue = 0;
	for(int i = 0; i < length; i++) {
		if(maxValue < array[i]) {
			maxValue = array[i];
		}
		temp[array[i]]++;
	}
//	cout << "maxValue = " << maxValue << endl;
	for(int i = 0; i < maxValue; i++) {
		if(temp[i] != 0) {
			dispNumber(i, temp[i]);
		}
	}
	cout << endl;
	delete temp;
}
void test()
{
	int array[] = {
		1, 5, 4, 5, 7, 2, 9, 11, 20, 9
	};
	int length = 10;
	sortInN(array, length);
}
int main()
{
	test();
	return 0;
}