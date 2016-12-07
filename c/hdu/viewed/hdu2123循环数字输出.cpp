#include<iostream>
using namespace std;
int main()
{
	int ca;
	cin>>ca;
	while(ca--) {
		int n, i, j;
		cin>>n;
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				cout<<i * j;
				if(j != n) { 
					cout<<" ";
				} 
			}
			cout<<endl;
		}
	}
	return 0;
}
/*
Sample Input
2
1
4

Sample Output
1
1 2 3 4
2 4 6 8
3 6 9 12
4 8 12 16

*/ 