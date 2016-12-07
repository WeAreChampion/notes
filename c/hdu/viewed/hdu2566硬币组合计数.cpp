#include<iostream>
using namespace std;
int getCounts(int n, int m)
{
	int counts = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= n - i; j++) {
			if((m - i - j * 2) % 5 == 0 
			&& ((i + j + (m - i - j * 2) / 5) == n)) {
				counts++;
			}
		}
	}
	return counts;
}
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca--) {
			int m, n;
			cin>>n>>m;
			cout<<getCounts(n, m)<<endl;
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
3 5
4 8

Sample Output
1
2

*/