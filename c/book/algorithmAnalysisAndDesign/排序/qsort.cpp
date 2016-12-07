#include<iostream>
using namespace std;
/**
	The quick sort algorithm
	该方法的基本思想是：
	1．先从数列中取出一个数作为基准数。
	2．分区过程，将比这个数大的数全放到它的右边，小于或等于
	它的数全放到它的左边。
	3．再对左右区间重复第二步，直到各区间只有一个数。
*/
void quickSort(int v[], int left, int right)
{
	if(left < right) {
		// 以左边的为基准
		int key = v[left];
		int low = left;
		int high = right;
		while(low < high) {
			// 从左向右搜索
			while(low < high && v[high] > key) {
				high--;
			}

			// 交换，以前的v[low]保存在key上
			v[low] = v[high];

			// 从右向左搜索
			while(low < high && v[low] < key) {
				low++;
			}

			// 保存到v[high]，以前的v[high]已经被移走
			v[high] = v[low];
		}

		// 存储基准在v[low]中
		v[low] = key;

		//搜索左子集
		quickSort(v, left, low - 1);

		//搜索右子集
		quickSort(v, low + 1, right);
	}
}
void testQuickSort()
{
	int array[] = {1, 5, 3, 4, 2};
	int length = sizeof(array) / sizeof(int);

	for(int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	quickSort(array, 0, length - 1);

	for(int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main()
{
	testQuickSort();
	return 0;
}