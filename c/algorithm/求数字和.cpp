#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int sum = 0;
		string s;
		cin >> s;
		for(int i = 0; i < s.length(); i++)
			sum += s[i] - '0';
		cout << sum << endl;
	}
	return 0;
}
/**
Input:
2
12345
123456789

Output:
15
45
*/