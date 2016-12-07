#include<iostream>
#include<string>
using namespace std;
template<class Type>
void displayArray(Type array[], int length, string split) {
	for(int i = 0; i < length; i++) {
		cout << array[i] << split;
	}
	cout << endl;
}
void testDisplayArray() {
	int array[] = {1, 3, 4};
	int length = 3;
	displayArray(array, length, " ");
}
int main() {
	testDisplayArray();
	return 0;
}