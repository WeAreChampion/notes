#include<iostream>
using namespace std;
#include<string>
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		int n,i;
		cin>>n;
		char ch;
		string s = "", ss = "";
		getchar();
		for(i = 0; i < n; i++) {
			while((ch = getchar()) != '\n') {
				if(ch != ' ') {
					s += ch;
				} else {
					reverse(s.begin(), s.end());
					ss += s;
					s = "";
					ss += ch;
				}
			}
			if(ch == '\n') {
				reverse(s.begin(), s.end());
				ss += s;
				cout<<ss<<endl;
				ss = "";
				s = "";
			}
		}
	}
	return 0;
}
/*
1
3
I am happy today
To be or not to be
I love you
*/