#include<iostream>
using namespace std;
template<class Type>
void Reverse(Type array[], int length) {
	for(int i = 0; i < length / 2; i++) {
		Type temp;
		temp = array[i];
		array[i] = array[length - 1 - i];
		array[length - 1 - i] = temp;
	}
}
template<class Type>
void Reverse(Type array[], int start, int end) {
	for(int i = start; i <= (end + start) / 2; i++) {
		Type temp = array[i];
		array[i] = array[start + end - i];
		array[start + end - i] = temp;
	}
}
template<class Type>
void DispArray(Type array[], int length) {
	for(int i = 0; i < length; i++) {
		cout<<array[i]<<"  ";
	}
	cout<<endl;
}
void Test()
{
	int length = 5;
	int array1[] = {1, 2, 3, 4, 5}; 
	Reverse(array1, length);
	DispArray(array1, length);
	float array2[] = {1.1, 2.1, 3.1, 4.1, 5.1};
	Reverse(array2, length);
	DispArray(array2, length);
	double array3[] = {1.11, 2.11, 3.11, 4.11, 5.11};
	Reverse(array3, length);
	DispArray(array3, length);
	Reverse(array3, 1, 4);
	DispArray(array3, length);
}
int main()
{
	Test();
	return 0;
}