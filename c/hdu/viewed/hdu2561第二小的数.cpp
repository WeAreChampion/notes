#include<iostream>
using namespace std;
void test()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			int m;
			cin>>m;
			int a, b, c;	
			cin>>a;
			cin>>b;
			int min1 , min2;
			if(a > b) {
				min1 = b;
				min2 = a;
			} else {
				min1 = a;
			 	min2 = b;
			}
			for(int i = 0; i < m - 2; i++) {
				cin>>c;
				if(min1 >= c) {
					min2 = min1;
					min1 = c;
					continue;
				}
				if(min2 > c) {
					min2 = c;
				}
			}
			cout<<min2<<endl;
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
2
1 2
3
1 1 3

Sample Output
2
1

*/