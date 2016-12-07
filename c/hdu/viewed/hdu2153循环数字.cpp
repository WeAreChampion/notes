#include<iostream>
#include<string>
using namespace std;
int array1[11];
int arrayN[11];
/*
	To print the number start with initValue times. According to the flag to
	display a line.
*/
void printIncrease(int initValue, int times, bool flag) {
	int i;
	int number = initValue;
	for(i = 1; i <= times; i++) {
		cout.width(3);
		cout.fill(' ');
		cout << number;
		number++;
	}
	if(flag) {
		cout << endl;
	}
}
/*
	To print the decrease number from initValue to initValue - times
*/
void printDecrease(int initValue, int times, bool flag) {
	int i;
	int number = initValue;
	for(i = 1; i <= times; i++) {
		cout.width(3);
		cout.fill(' ');
		cout << number;
		number--;
	}
	if(flag) {
		cout << endl;
	}
}
/*
	To init the array by initValue count times, the value from initValue to initValue + times.
*/
void increaseArray(int array[], int initValue, int times) {
	for(int i = 1; i <= times; i++) {
		array[i] = initValue + i - 1;
	}
}
/*
	To init the array by initValue count times, the value from initValue to initValue - times.
*/
void decreaseArray(int array[], int initValue, int times) {
	for(int i = 1; i <= times; i++) {
		array[i] = initValue - i + 1;
	}
}

/*

*/
void printChar(int times) {
	for(int i = 0; i < times; i++) {
		cout.width(3);
		cout.fill(' ');
		cout << " ";
	}
}
void printCenter(int n) {
	int ininValue1 = 4 * n - 4;
	int times = n - 2;
	decreaseArray(array1, ininValue1, times);
	
	int ininValue2 = n + 1;
	increaseArray(arrayN, ininValue2, times);
	for(int i = 1; i <= times; i++) {
		cout.width(3);
		cout.fill(' ');
		cout << array1[i];
		//printChar(n);
		for(int j = 0; j < n - 2; j++) {
			cout.width(3);
			cout.fill(' ');
			cout << "";
		}
		cout.width(3);
		cout.fill(' ');
		cout << arrayN[i];
		cout << endl;
	}
	
}
void printShape(int n) {
	if(n == 1) {
		cout.width(3);
		cout.fill(' ');
		cout << 1 << endl << endl;
		return ;
	}
	printIncrease(1, n, true);
	
	printCenter(n);
	
	printDecrease(3 * n - 2, n, true);
}
void test() {
	int n;
	while(scanf("%d", &n) != EOF) {
		printShape(n);
	}
}
int main() {
	test();
	return 0;
}
