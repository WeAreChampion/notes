#include<iostream>
#include<cmath>
using namespace std;
int prime(int n)//ÅĞ¶ÏÊÇ·ñÎªËØÊı
{
	if(n == 2) {
		return 1;
	}
	if(n < 2 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
		return 0;
	}
	int length = (int)sqrt(double(n));
	for(int i = 2;i <= length; i++) {
		if(n % i== 0) { 
			return 0;
		} 
	}
	return 1;
}
int main()
{
	int n;
	while(cin>>n) {
		cout<<((prime(n) == 1) ? "Yes" : "No")<<endl;
	}
	return 0;
}