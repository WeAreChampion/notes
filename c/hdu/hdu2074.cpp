#include<iostream>
#include<string>
using namespace std;
char array[80][80];
void fillChar(int n, int row, int start, int end, char ch1, char ch2) {
	for(int i = 1; i < n - 1; i++) {
		if(i >= start && i <= end){
			array[row][i] = ch1;
		} else {
			array[row][i] = ch2;
		}
	}
}
void copyArray(int rowSrc, int n, int rowDir) {
	for(int i = 0; i < n; i++) {
		array[rowDir][i] = array[rowSrc][i];
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
	cout << endl;
}
void getString(int n, char ch1, char ch2) {
	if(n == 1) {
		array[0][0] = ch1;
		return ;
	}
	int counts = n / 2;
	int length = counts;
	int i, j;
	//To init the first row's first element and the last element
	array[0][0] = ' ';
	array[0][n - 1] = ' ';
	
	//To init the first row
	for(i = 1; i < n - 1; i++) {
		array[0][i] = ch1;
	}
	//To init the counts - 1 row
	for(i = 1; i <= counts; i++) {
		for(j = 0; j < n; j++) {
			if(j == 0 || j == n - 1) {
				array[i][j] = ch1;
			} else {
				//fill char1
				int start = j + counts;
				int end = n - counts - j;
				if(counts % 1 == 0) {
					fillChar(n, i, start, end, ch1, ch2);
				} else {//fill char2 
					fillChar(n, i, start, end, ch2, ch1);
				}
			}
		}
	}
	copyArray2(n);
}
void test() {
	int n;
	string ch1;
	string ch2;
	while(scanf("%d", &n) != EOF) {
		cin >> ch1 >> ch2;
		getString(n, ch2[0], ch1[0]);
		displayArray(n);
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