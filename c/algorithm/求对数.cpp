#include<iostream>
#include<cmath>
using namespace std;
int f(int n)
{
	int m = log(n) / log(2);
	if(pow(2, (double)m) == n) {
		return m;
	}
	return m + 1;
}
int main()
{
	int n;
	while(cin >> n && n) {
		cout << f(n) << endl;
	}
	return 0;
}