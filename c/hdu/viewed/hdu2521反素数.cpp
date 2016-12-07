#include<iostream>
#include<cmath>
using namespace std;
int countFactor(int n)
{
	int counts = 0;
	int length = (int) sqrt((double) n);
	for(int i = 2; i <= length; i++) { 
		if(n % i == 0) { 
			counts++;
		}
	}
	if(length * length == n) {
		return 2 * counts + 1;
	}
	return 2 * counts + 2;
}
void test()
{
	int ca;
	cin >> ca;
	while(ca--) {
		int a, b;
		cin >> a >> b;
		int val;
		int maxCounts = 0;
		for(int i = a; i <= b; i++) {
			int counts = countFactor(i);
			if(counts > maxCounts) {
				maxCounts = counts;
				val = i;
			}
		}
		cout << val << endl;
	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
3
2 3
1 10
47 359


Sample Output
2
6
240
Hint
2的因子为：1 2
10的因子为:1 2 5 10

*/