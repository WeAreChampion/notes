#include<iostream>
using namespace std;
/**
	花money多的钱，买number数量鸡的情况种数
	A鸡 : 5元一只
	B鸡 : 3元一只
	C鸡 : 两只一元
*/
int getCounts(int money, int number) {
	int counts = 0;
	int nA, nB, nC;
	
	// 枚举A鸡的数量
	for(nA = 1; nA <= money / 5; nA++) {
		
		// 枚举B鸡的数量
		for(nB = 1; nB <= money / 3; nB++) {
			
			// C鸡的数量即剩余的钱数
			nC = (money - 5 * nA - 3 * nB) * 2;
			if(nA + nB + nC == number) {
				counts++;
				cout << nA << " " << nB << " " << nC << endl; 
			}
		}
	}
	return counts;
}
void test() {
	cout << getCounts(100, 100) << endl;
}
int main() {
	test();
	return 0;
}