#include<iostream>
using namespace std;
void printHDU(int n)
{
	for(int i = 0; i < n; i++) {
		cout<<"HDU";
	}
}
void test()
{
	int ca;
	cin >> ca;
	while(ca--) {
		int n;
		cin >> n;
		for(int i = 0; i < n * 3; i++) {
			printHDU(n);
			cout<<endl;
		}
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
HDU
HDU
HDU
HDUHDU
HDUHDU
HDUHDU
HDUHDU
HDUHDU
HDUHDU

*/