#include<iostream>
#include<cmath>
using namespace std;
int initPrimer(int n)
{
	int length = (int)sqrt((double) n);
	for(int i = 2; i <= length; i++) { 
		if(n % i == 0 && (n /= i)) { 
			i--;
		}
	}
	return n;
}
void test()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		int maxPrime = 0;
		int maxValue = 0;
		while(n--) {
			int a;
			cin>>a;
			int value = initPrimer(a);
			if(maxValue < value) {
				maxPrime = a;
				maxValue = value;
			}
		}
		cout << maxPrime <<endl;
	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
4
36
38
40
42

Sample Output
38

*/