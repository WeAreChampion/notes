#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
	if(n == 2 || n == 3 || n == 5 || n == 7) {
		return true;
	} else if(n == 1) {
		return false;
	} else if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
		return false;
	}
	int length = (int) sqrt((double) n);
	for(int i = 2; i <= length; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}
void testIsPrime()
{
	cout<<isPrime(2)<<endl;
	cout<<isPrime(3)<<endl;
	cout<<isPrime(9)<<endl;
	cout<<isPrime(25)<<endl;
}
int main()
{
	testIsPrime();
	return 0;
}