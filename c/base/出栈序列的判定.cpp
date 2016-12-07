#include<iostream>
using namespace std;
/*
	The element push into stack like 1, 2, 3... n.
*/ 
int findNPos(int array[], int length)
{
	for(int i = 0; i < length; i++) {
		if(array[i] == length) {
			return i;
		}
	}
	return -1;
}
/*
	From the startPos to endPos, If there is element is reversed then
	return false, else return true.
*/
bool isReversePath(int array[], int startPos, int endPos)
{
	for(int i = startPos + 1; i <= endPos; i++) {
		for(int j = i + 1; j<= endPos; j++) {
			if(array[i] < array[j]) {
				return false;
			}
		}
	}
	return true;
}
bool isTrueStackPath(int array[], int length)
{
	int maxPos = findNPos(array, length);
	if(isReversePath(array, maxPos, length - 1)) {
		return true;
	}
	return false;
}
void test()
{
	int length = 5;
	int array[] = {
		1, 2, 4, 5, 3
	};
	cout << (isTrueStackPath(array, length) ? "true" : "false") << endl;
	
	int arrayB[] = {
		1, 5, 4, 2, 3
	};
	cout << (isTrueStackPath(arrayB, length) ? "true" : "false") << endl;
	
	int arrayC[] = {
		1, 5, 4, 3, 2
	};
	cout << (isTrueStackPath(arrayC, length) ? "true" : "false") << endl;
	int arrayD[] = {
		5, 4, 3, 2, 1
	};
	cout << (isTrueStackPath(arrayD, length) ? "true" : "false") << endl;
}
int main()
{
	test();
	return 0;
}