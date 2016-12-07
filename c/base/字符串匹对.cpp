#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	char c[101];
	getchar();
	while(cin.getline(c, 101)) {
		string s = "";
		for(int i = 0; i < strlen(c); i++) {
			//is a word
			if((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')) {
				s += c[i];
			} else {
				if(a == s) {
					cout<<b;
				} else {
					cout<<s;
				}
				cout<<c[i];
				s = "";
			}
		}
		cout<<endl;
	}
	return 0;
}