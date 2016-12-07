#include<iostream>
using namespace std;
#include<map>
#include<cmath>
#define MAX_VALUE 88888
#define MAX_ARRAY_SIZE 10000
/**
	判断一个数是否是素数
*/
bool isPrime(int n) {
	if(n <= 1) {
		return false;
	}
	int length = (int) sqrt((double) n);
	for(int i = 2; i <= length; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}
/**
	初始化n以内是素数，并存在数组array中，且返回素数个数
*/
int initArray(int array[], int n) {
	int k = 0;
	for(int i = 2; i <= n; i++) {
		if(isPrime(i)) {
			array[k++] = i;
		}
	}
	return k;
}
/**
	根据prime数组因式分解n
	prime[] : prime array
	length : the prime array's length
	n : the divided number
	countsMap : 用于计数素数数量的map
*/
void dividedNumber(int prime[], int length, int n, map<int, int> &countsMap) {
	int currentValue = n;
	int i = 0;
	while(i < length && prime[i] <= currentValue) {
		if(currentValue % prime[i] == 0) {
			countsMap[prime[i]]++;
			
			currentValue = currentValue / prime[i];
		} else {
			i++;
		}
	}
}
/**
	根据素数数组array与长度，将n!进行因式分解并将结果保存在counts中，并返回其长度.
*/
int countPrime(map<int, int> &countsMap, int prime[], int primeLength, int n) {
	// 保存counts数组的长度
	int k = 0;
	// 模拟n的阶乘，依次对其[2-n]间的数进行因式分解
	for(int i = 2; i <= n; i++) {
		
		// 因式分解i
		dividedNumber(prime, primeLength, i, countsMap);
	}
}
void iteratroMap(map<int, int> m) {
	map<int, int>::iterator it;
	for(it = m.begin(); it != m.end(); it++) {
		int value = it->first;
		int counts = it->second;
		if(counts != 0) {
			cout << counts << " ";
		}
	}
	cout << endl;
}
void test() {
	int n;
	map<int, int> countsMap;
	int prime[MAX_ARRAY_SIZE];
	
	int length = initArray(prime, MAX_VALUE);
	while(cin >> n) {
		
		countsMap.clear();
		
		countPrime(countsMap, prime, length, n);
		
		iteratroMap(countsMap);
	}
}
int main() {
	test();
	return 0;
}
/**
Input:
5
53
Output:
3 1 1
49 23 12 8 4 4 3 2 2 1 1 1 1 1 1 1

*/