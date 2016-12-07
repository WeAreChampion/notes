#include<iostream>
using namespace std;
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca--) {
			int m, n;
			cin >> m >> n;
			int value;
			int counts = 0;
			for(int i = 0; i < m * n; i++) {
				cin>>value;
				if(value == 1) {
					counts++;
				}
			}
			cout<<counts<<endl;
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
2 2
1 1
0 0
3 3
1 0 1
0 0 1
1 1 0

Sample Output
2
5

*/