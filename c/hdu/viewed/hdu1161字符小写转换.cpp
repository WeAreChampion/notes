#include<iostream>
#include<cstring>
using namespace std;
void test()
{
	char s[1001];
	while(gets(s)) {
		int length = strlen(s);
		for(int i = 0; i < length; i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') {
				s[i] += 32;
			}
			cout << s[i];
		}
		cout<<endl;
	}
	
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
weLcOmE tO HDOj Acm 2005!
weLcOmE tO HDOj Acm 2005!
 

Sample Output
welcome to hdoj acm 2005!

*/