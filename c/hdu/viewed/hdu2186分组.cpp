#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n, m;
	cin>>n;
	while(n--) {
		int a1, a2, a3, sum=0;
		cin>>m;
		a1 = m / 2;
		if(a1 % 10 != 0) { 
			sum = sum + a1 / 10 + 1;
		} else {
			sum += a1/10;
		} 
		a2 = (m - a1) * 2 / 3;
		if(a2 % 10 != 0) { 
			sum += a2 / 10 + 1;
		} 
		else { 
			sum += a2/10;
		} 
		a3 = m - a1 - a2;
		if(a3 % 10 != 0) { 
			sum += a3 / 10 + 1;
		} 
		else { 
			sum += a3 / 10;
		} 
		cout<<sum<<endl;
	}
	return 0;
}