#include<iostream>
using namespace std;
/**
	To get the counts of one from n(10)
*/
int countsOne(int n) {
	int temp = n;
	int counts = 0;
	while(temp) {
		if(temp % 10 == 1) {
			counts++;
		} 
		temp = temp / 10;
	}
	return counts;
}
/**
	To get the counts of one between m and n
*/
int countsOneMine(int m, int n) {
	int small = m;
	int big = m;
	// To get the small and big value
	if(m > n) {
		small = n;
	} else {
		big = n;
	}
	int sum = 0;
	for(int i = small; i <= big; i++) {
		sum += countsOne(i);
	}
	return sum;
}
/**
	Tn = O(nlogn)
*/
void testCountsOneMine() {
	int m, n;
	while(cin >> m >> n) {
		cout << "counts : " << countsOneMine(m, n) << endl;
	}
}
int main() {
	testCountsOneMine();
	return 0;
}