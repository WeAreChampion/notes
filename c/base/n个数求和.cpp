#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while(n--) {
		int a, sum = 0, b;
		cin >> a;
		for(int i = 0; i < a; i++) {
			cin >> b;
			sum += b;
		}
		cout << sum << endl;
	}
	return 0;
}
/*
1
4
1 2 3 4
*/