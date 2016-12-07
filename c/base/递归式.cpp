#include<iostream>
using namespace std;
int getCount(int n, int m)
{
	if(n == 1 && m == 0) {
		return 2;
	} else if(n == 0) {
		return 1;
	} else if(m == 0) {
		return n + 2;
	} else {
		return getCount(getCount(n - 1, m), m - 1);
	}
}
int main()
{
	int n, m;
	while(cin >> n >> m) {
		cout << getCount(n, m) << endl;
	}
	return 0;
}