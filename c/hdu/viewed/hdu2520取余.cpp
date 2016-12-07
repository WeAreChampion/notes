#include<iostream>
using namespace std;
/*
	要求结果对10000取余。 
	即求 n * n ，但是数字很大，所以要对10000取余。 
*/
void test()
{
	int ca;
	cin>>ca;
	while(ca--) {
		int n;
		cin >> n;
		int value =  n % 10000;
		cout << (value * value ) % 10000 <<endl;
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
1
2


Sample Output
1
4

*/