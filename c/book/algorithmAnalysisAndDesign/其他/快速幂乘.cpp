#include<iostream>
using namespace std;
/*
	奇数时，将单个a乘给b，偶数时，采用a*a，最后a*b->a
	To calculate a^n return the value and calculate the multiply counts
	
	n为奇数
		sum = sum * a;
		n--;
	n为偶数
		a = a * a
		n = n / 2;
*/
int pow(int a, int n, int &count)
{
	int b = 1;
	while(n > 1) {
		if(n & 1) { //为奇数
			b = b * a % 1000;
			n--;
		} else {
			a = a * a % 1000;
			n /= 2;
		}
		count++;
	}
	return (a * b) % 1000;
}
int main()
{
	int a, b; //caculate a^b
	while(cin >> a >> b) {
		int count = 0;
		cout << "a^b = " << pow(a, b, count) << endl;
		cout << "count = " << count << endl;
	}
	return 0;
}
/*
Input:
5 6
3 7

Output:
a^b = 625
count = 3
a^b = 187
count = 4
*/