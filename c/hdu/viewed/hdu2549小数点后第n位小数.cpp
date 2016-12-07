#include<iostream>
#include<string>
using namespace std;
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca--) {
			string s;
			int n;
			cin>>s >>n;
			int length = s.find("."); 
			if(length + n < s.size()) { 
				cout<<s[length + n]<<endl;
			} 
			else {
				cout<<0<<endl;
			}
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
3
11.234 1
222.345 2
3333.456 3

Sample Output
2
4
6

*/