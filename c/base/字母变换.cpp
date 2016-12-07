#include<iostream>
#include<string>
using namespace std;
char a[27] = {' ', 'A', 'B', 'C', 'D', 
				'E', 'F', 'G', 'H', 'I', 'J',
				'K', 'L', 'M', 'N', 'O', 'P', 
				'Q', 'R', 'S', 'T', 'U', 'V',
				'W', 'X', 'Y', 'Z'};
int getNumber(string s)
{
	int sum = 0, k = 1;
	for(int i = s.length() - 1; i >= 0; i--) {
		sum += (s[i] - '0') * k;
		k *= 10;
	}
	return sum;
}
int main()
{
	int ca;
	cin>>ca;
	getchar();
	while(ca--) {
		char ch;
		string s = "";
		while((ch = getchar()) != '\n') {
			if(ch == '#') {
				cout<<a[getNumber(s)]<<" ";
				s = "";
			}
			else if(ch == '-') {
				cout<<a[getNumber(s)];
				s = "";
			}
			else if(ch >= '0' && ch <= '9') {
				s += ch;
			}
		}
		if(s != "") {
			cout<<a[getNumber(s)];
		}	
		cout<<endl;
	}
	return 0;
} 