#include<iostream>
#include<string>
using namespace std;
char array[80][80];
/*
To fill char row is row and column from start to end
*/
void fillChar(int row, int start, int end, char ch) {
	for(int i = start; i <= end; i++) {
		array[row][i] = ch;
	}
}
/*
	To copy array from array[rowSrc][] to array[rowDir][]
*/
void copyArray(int rowSrc, int n, int rowDir) {
	for(int j = 0; j < n; j++) {
		array[rowDir][j] = array[rowSrc][j];
	}
}
void copyArray2(int n) {
	int length = n / 2;
	for(int i = 0; i < length; i++) {
		int rowDir =  n - i - 1;
		copyArray(i, n, rowDir);
	}
}
void displayArray(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%c", array[i][j]);
		}
		cout << endl;
	}
}
void getString(int n, char ch11, char ch22) {
	if(n == 1) {
		array[0][0] = ' ';
		return ;
	}
	int counts = n / 2;
	int i, j;
	//To init the first row's first element and the last element
	array[0][0] = ' ';
	array[0][n - 1] = ' ';
	
	char ch1, ch2;
	if(counts % 2 == 0) {
		ch1 = ch22;
		ch2 = ch11;
	} else {
		ch1 = ch11;
		ch2 = ch22;
	}
	
	//To init the first row where the row index is 0
	for(i = 1; i < n - 1; i++) {
		array[0][i] = ch1;
	}
	
	//To init the counts - 1 row
	for(i = 1; i <= counts; i++) {
		//fill char1
		int start = i;
		int end = n - i - 1;
		// fill the char ch2 from  start to end where the row is i
		if(i % 2 == 1) {
			fillChar(i, start, end, ch2);
		} else {//fill char1 
			fillChar(i, start, end, ch1);
		}
		array[i][0] = ch1;
		array[i][n - 1] = ch1;
		//copy the array[i-1] to array[i]
		copyArray(i, n, i + 1);
		
	}
	copyArray2(n);
}
void test() {
	int n;
	string ch1;
	string ch2;
	int ca = 0;
	while(scanf("%d", &n) != EOF) {
		ca++;
		cin >> ch1 >> ch2;
		if(ca != 1) {
			cout << endl;
		}
		if(n == 1) {
			cout << ch1 << endl;
		} else {
			getString(n, ch2[0], ch1[0]);
			displayArray(n);
		}
	}
}
int main() {
	test();
}
/**
Sample Input

11 B A
5 @ W

 

Sample Output

 AAAAAAAAA 
ABBBBBBBBBA
ABAAAAAAABA
ABABBBBBABA
ABABAAABABA
ABABABABABA
ABABAAABABA
ABABBBBBABA
ABAAAAAAABA
ABBBBBBBBBA
 AAAAAAAAA 

 @@@ 
@WWW@
@W@W@
@WWW@
 @@@ 
*/