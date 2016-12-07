#include<iostream>
using namespace std;
int main()
{
	int ca;
	cin >> ca;
	while(ca--) {
		__int64 a = 1, b = 1, c, n;
		scanf("%I64d", &n);
		if(n > 0) {
			if(n == 1|| n == 2) {
				cout << 1 << endl;
			} else {
				for(int i = 0; i < n - 2; i++) {
					c = a + b;
					a = b;
					b = c;
				}
				printf("%I64d\n", c);
			}
		}
	}
	return 0;
} 