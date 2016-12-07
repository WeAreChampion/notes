#include<iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	 a = b;
	 b = temp;
}
/**
	类型冒泡法排序
*/
void sort(int array[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = n; j > i; j--) {
			if(array[j] < array[j - 1]) {
				swap(array[j], array[j - 1]);
			}
		}
	}
}
void test() {
	int array[] = {
		2, 4, 3, 5, 1
	};
	int n = 5;
	for(int i = 0; i < 5; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	
	sort(array, n);
	
	for(int i = 0; i < 5; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main() {
	test();
	return 0;
}