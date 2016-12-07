#include<iostream>
using namespace std;
/*
	f(1, n) = n *(n + 1) / 2;
	
	f(m, 1) = m *(m + 1) / 2;
	
	f(m, n) = f(m, 1) * f(1, n);
*/ 
int getValue(int n)
{
	return (n + 1) * n / 2;
}
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca--) {
			int m, n;
			cin >> m >> n;
			cout << (getValue(m) * getValue(n)) <<endl;
		}	
 	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
2
1 2
2 4
 
Sample Output
3
30

*/