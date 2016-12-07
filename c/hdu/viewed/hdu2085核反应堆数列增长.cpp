#include<iostream>
using namespace std;
long long sumLow[34];
long long sumHigh[34];
void initCounts() {
	sumLow[0] = 0;
	sumHigh[0] = 1;
	for(int i = 1; i <= 33; i++) {
		sumLow[i] = sumLow[i - 1] + sumHigh[i - 1];
		sumHigh[i] = 2 * sumLow[i - 1] + 3 * sumHigh[i - 1];
	}
}
int main() {
	initCounts();
	int n;
	while(scanf("%d", &n) != EOF && n != -1) {
		cout << sumHigh[n] << ", " << sumLow[n] << endl;
	}
	return 0;
} 
/*
Sample Input
5 2
-1

 

Sample Output

571, 209
11, 4
*/