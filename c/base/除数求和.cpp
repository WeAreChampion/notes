#include<iostream>
#include<cmath>
using namespace std;
/*
	To get n % m. And 
*/
int getMod(int n, int m, int &divNumber) {
	divNumber = n / m;
	return n - divNumber * m;
}
/*
	To ge the sum
*/
int getDivSum(int n) {
	if(n <= 0) {
		return 0;
	}
	int sqrtN = (int)(sqrt((double) n));
	//include 1
	int sum = 1;
	int divNumber;
	for(int i = 2; i <= sqrtN; i++) {
		// can divided by i and the mod is 0
		if(getMod(n, i, divNumber) == 0) { 
			sum += i;
			if(i != divNumber) {
				sum += divNumber;
			}
		}
	}
	return sum;
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		cout << getDivSum(n) << endl;
	}
	return 0;
}