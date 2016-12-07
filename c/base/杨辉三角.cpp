#include<iostream>
using namespace std;
int array[100][100];
/*
	To print the char ch n times and according to the flag print a line.
*/
void printNTimes(char ch, int n, bool flag) {
	for(int i = 0; i < n; i++) {
		cout << ch;
	}
	if(flag) {
		cout << endl;
	}
}
/*
	To calculate the array
*/
void getTriggle(int n) {
	int i, j;
	for(i = 0; i < n; i++) {
   	// for each the array
   	for(j = 0; j <= i; j++) {
	   	// is the first column element
   		if(j == 0) {
   			array[i][j] = 1;
   		} else if(i == j) {
	   		// the last column element
   			array[i][j] = 1;
	   	} else {
   			array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
   		}
   	}
   	array[i][j] = 1;
   	
	}
}
/*
	To print the triggle
*/
void printTriggle(int n) {
	getTriggle(n);
	int i, j;
	for(i = 0; i < n; i++) {
		// pring the space char and don't display a line.
		printNTimes(' ', n - i -1, false);
		// To display 
		for(j = 0; j < i; j++) {
			cout << array[i][j] << " ";
		}
		cout << array[i][j] << endl;
	}
}
void test() {
	int n;
	while(scanf("%d", &n) != EOF) {
		printTriggle(n);
	}
}
int main() {
	test();
	return 0;
}
