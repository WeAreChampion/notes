#include<iostream>
using namespace std;
/*
	To get n % d, not use the % operator.
*/ 
int mod(int n, int d)
{
	return n - (n / d) * d;
}
void test()
{
	cout << mod(10, 3) << endl;
	cout << mod(10, 10) << endl;
	cout << mod(10, 6) << endl;
}
int main()
{
	test();
	return 0; 
}