#include<iostream>
using namespace std;
template<class Type>
void reverseArray(Type array[], int length)
{
	int len = length / 2;
	for(int i = 0; i < len; i++) {
		Type temp = array[i];
		int targetPos = length - 1 - i;
		array[i] = array[targetPos];
		array[targetPos] = temp;
	}
}
template<class Type>
void reverseArray(Type array[], int startPos, int endPos)
{
	int len = endPos - startPos + 1;
	int subLen = endPos + startPos;
	int length = len / 2;
	for(int i = startPos; i < length; i++) {
		Type temp = array[i];
		int targetPos = subLen - i;
		array[i] = array[targetPos];
		array[targetPos] = temp;
	}
}
template<class Type>
void reverseLeftPTime(Type array[], int length, int p)
{
	reverseArray(array, length);
	reverseArray(array, 0, length - p - 1);
	reverseArray(array, length - p, length - 1);
}
template<class Type>
void dispArray(Type array[], int length) 
{
	cout << "The array is :" << endl;
	for(int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void test()
{
	int p = 5;
	int length = 8;
	int array[] = {
		1, 2, 3, 4, 5, 6, 7, 8
	};
	dispArray(array, length);
	reverseLeftPTime(array, length, p);
	dispArray(array, length);
}
int main()
{
	test();
	return 0;
} 