#include<iostream>
using namespace std;
int main()
{
	int a, b;
	while(cin >> a >> b) {
		a = a % 86;
		b = b % 86;
		cout << ((a + b) % 86 == 0 ? "yes" : "no") << endl;
	}
	return 0;
}