#include<iostream>
using namespace std;
int f(char a)
{
	int value;
	if(a >= '0' && a <= '9') { //is number
		value = a - '0';
	} else if(a >= 'a' && a <= 'z') { //is lower word[a-z] 
		value = a - 87;
	} else if(a >= 'A' && a <= 'Z') { //is upper word[A-Z]
		value = a - 55;
	} 
	return value;
}
int main()
{
	char a[10], b[10];
	while(cin>>a>>b) {
		//calculate a + b
		cout<<f(a[0]) + f(b[0])<<endl;
	}
	return 0;
}