#include<iostream>
using namespace std;
#include<algorithm>
#define MAX_SIZE 1000
/**
	在数组中从尾部查找两个相邻元素，满足order[i] < order[i + 1]
	找到返回 index； 否则返回-1
*/
int findIsSmallerLastOf(int array[], int n) {
	for(int i = n - 2; i >= 0; i--) {
		if(array[i + 1] > array[i]) {
			return i;
		}
	}
	return -1;
}
/**
	从数组尾部开始找第一个大于order[i]的数order[k]（k>i）
	找到返回 index，未找到返回-1
*/
int findIsBiggerLastOf(int array[], int n, int valueIndex) {
	for(int i = n - 1; i > valueIndex; i--) {
		if(array[valueIndex] < array[i]) {
			return i;
		}
	}
	return -1;
}
/**
	To swap the array's value by index pos1 and pos2
*/
void swap(int array[], int pos1, int pos2) {
	int temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}
/**
	将array数组中start到end位置中的数据进行从小到大排序
*/
void sortArray(int array[], int start, int end) {
	for(int i = start; i <= end; i++) {
		for(int j = i + 1; j <= end; j++) {
			if(array[i] > array[j]) {
				swap(array, i, j);
			}
		}
	}
	
}
/**
	产生下一个排列：
	从数组尾部开始找相邻两个元素，满足order[i] < order[i + 1]，
	再从数组尾部开始找第一个大于order[i]的数order[k]（k>i），
	交换order[i]和order[k]，order[i+1]~order[n-1]进行逆向重排。
*/
void createNext(int array[], int n) {
	int pos1 = findIsSmallerLastOf(array, n);
	int pos2 = findIsBiggerLastOf(array, n, pos1);
	
	// 交换
	swap(array, pos1, pos2);
	
	// 排序
	sortArray(array, pos1 + 1, n - 1);
}
/**
	To display the array
*/
void displayArray(int array[], int n) {
	for(int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void test() {
	int array[MAX_SIZE];
	int n;
	while(cin >> n) {
		// 输入当前排列
		for(int i = 0; i < n; i++) {
			cin >> array[i];
		}
		
		// 根据当前排列产生下一个排列
		createNext(array, n);
		
		displayArray(array, n);
	}
}
int main() {
	test();
	return 0;
}
/**
Input:
8
2 6 4 5 8 1 7 3
8
2 6 4 5 8 3 1 7
8
2 6 4 5 8 3 7 1
8
2 6 4 5 8 7 1 3
8
2 6 4 5 8 7 3 1
Output:
2 6 4 5 8 3 1 7
2 6 4 5 8 3 7 1
2 6 4 5 8 7 1 3
2 6 4 5 8 7 3 1

*/