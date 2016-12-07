#include<iostream>
using namespace std;
int isPrime(int n)
{
	if(n == 3 || n == 5 || n == 7) {
		return 1;
	}
	if(n == 1 || n == 2) {
		return 0;
	}
	if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
		return 0;
	}
	int length = (int) sqrt((double) n);
	for(int i = 2; i <= length; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n, ca = 0;
	while(cin>>n && (n > 0)) {
		ca++;
		if(f(n) == 1) { 
			cout<<ca<<": yes"<<endl;
		} 
		else { 
			cout<<ca<<": no"<<endl;
		} 
	}
	return 0;
}