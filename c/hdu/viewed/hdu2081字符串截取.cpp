#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int n;
	while(cin >> n) {
		while(n--) {
			s = "";
			cin >> s;
			
			// print char 6
			cout << '6';
			//print the string's last 5
			for(int i = s.size() - 5;i <= s.size() - 1; i++) {
				cout<<s[i];
			}
			cout << endl;
		}
	}
	return 0;
}