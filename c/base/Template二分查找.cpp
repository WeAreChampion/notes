#include<iostream>
using namespace std;
#include<string>
#define LENGTH 8
/*
	To find the data in the array
*/
template<class Type>
int binarySearch(Type array[], int length, Type data)
{
	int left = 0;
	int right = length - 1;
	while(right >= left) {
		int middle = (left + right) / 2;
		if(array[middle] == data) {
			return middle;
		}
		if(array[middle] < data) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	} 
	return -1;
}
/*
	To find data from startPos to endPos by binary-search.
*/
template<class Type>
int binarySearch(Type array[], int startPos, int endPos, Type data)
{
	int left = startPos;
	int right = endPos;
	while(right >= left) {
		int middle = (startPos + endPos) / 2;
		if(array[middle] == data) {
			return middle;
		}
		if(array[middle] < data) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}
}
void test()
{
	double douArray[] = {
		1.2, 1.5, 1.8, 5.4, 6.8, 7.9, 9.0, 10.0
	};
	cout << binarySearch(douArray, LENGTH, 5.4) << endl;
	
	
	int intArray[] = {
		1, 2, 3, 4, 5, 6, 7, 8
	};
	cout << binarySearch(intArray, LENGTH, 7) << endl;
	
	float floatArray[] = {
		1.0f, 2.3f, 3.3f, 4.1f, 5.5f, 6.2f, 7.6f, 8.0f
	};
	cout << binarySearch(floatArray, LENGTH, 3.3f) << endl;
	
	char charArray[] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'
	};
	cout << binarySearch(charArray, LENGTH, 'z') << endl;
	
}
int main()
{
	test();
	return 0;
}