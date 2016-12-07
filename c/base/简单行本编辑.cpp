#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c;
	string s = "";
	while((c = getchar()) != EOF) {
		if(c == '\n') { 
			cout<<s<<endl;
		} 
		else {
			if(c=='#') {
				if(s.length () >= 1) { 
					s.erase (s.length () - 1);
				} 
				else { 
					s = "";
				} 
			}
			else if(c=='@') {
				s = "";
			} else {
				s += c;
			}
		}
	}
	return 0;
}