#include<iostream>
using namespace std;
int main()
{
	int s1, s2, s3, n;
	while(cin >> n) {
		s1 = s2 = s3 = 0;
		int a = n;
		if(n == 0) {
			break;
		}
		while(n) {
			s1 += n % 10;
			n = n / 10;
		}
		n = a;
		while(n) {
			s2 += n % 16;
			n = n / 16;
		}
		n = a;
		while(n) {
			s3 += n % 12;
			n = n / 12;
		}
		if(s1 == s2 && s2 == s3) {
			cout<<a<<" is a Sky Number."<<endl;
		} 
		else { 
			cout<<a<<" is not a Sky Number."<<endl;
		} 
	}
	return 0;
}