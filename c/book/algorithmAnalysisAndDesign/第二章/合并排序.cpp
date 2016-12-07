#include<iostream>
using namespace std;
#define MAX_SIZE 100
/**
	To display array from start to end
*/
template<class Type>
void display(Type array[], int start, int end) {
	for(int i = start; i <= end; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
/**
	merge array[left, center] and array[center + 1, right] into temp[left, right]
*/
template<class Type>
void merge(Type array[], Type temp[], int left, int center, int right) {
	int i = left;
	int j = center + 1;
	int k = left;
	
	// merge the common counts array 
	while((i <= center) && (j <= right)) {
		// merge array[i] into temp
		if(array[i] <= array[j]) {
			temp[k++] = array[i++];
		} else {// merge array[j] into temp
			temp[k++] = array[j++];
		}
	}
	
	// merge last array[j] to array[right] into temp
	if(i > center) {
		for(int p = j; p <= right; p++) {
			temp[k++] = array[p];
		}
	} else {// merge last array[i] to array[left] into temp
		for(int p = i; p <= center; p++) {
			temp[k++] = array[p];
		}
	}
}
/**
	To copy temp to array from left to right
*/
template<class Type>
void copy(Type array[], Type temp[], int left, int right) {
	for(int i = left; i <= right; i++) {
		array[i] = temp[i];
	}
}
/**
	meegeSort array[left, right]
	使用分治实现对n个元素进行排序的算法
	基本思想是：
		将待排序元素分成大小大致相同的两个子集合，分别对两个子集合进行排序，最终将
		排好序的子集合进行合成有序的集合
*/
template<class Type>
void mergeSort(Type array[], int left, int right) {
	Type temp[MAX_SIZE];
	// more than 2 elements
	if(left < right) {
		int center = (left + right) / 2;
		
		// meegeSort array[left, center]
		mergeSort(array, left, center);
		
		// meegeSort array[center + 1, right]
		mergeSort(array, center + 1, right);
		
		// merge array into temp from left->center->right
		merge(array, temp, left, center, right);
		
		// copy temp to array from left to right
		copy(array, temp, left, right);
		
		display(array, left, right);
	}
}
void testMergeSort() {
	int array[10] = {
		3, 4, 8, 1, 6, 9, 7, 0, 2, 5
	};
	int left = 0;
	int right = 9;
	cout << "The init data : ";
	display(array, left, right);
	
	mergeSort(array, left, right);
	
	cout << "After sort data : ";
	display(array, left, right);
}
int main() {
	testMergeSort();
	return 0;
}