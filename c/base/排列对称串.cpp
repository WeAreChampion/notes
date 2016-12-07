#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool comp(const string s1, const string s2)
{
	return s1.length() != s2.length() ? s1.length() < s2.length() : s1 < s2;
}
int main()
{
	vector<string> v;
	string t, s;
	int n, i;
	while(cin>>n) {
		v.clear();
		for(i = 0; i < n; i++) {
			cin>>s;
			t = s;
			reverse(t.begin(), t.end());
			if(t == s) {
				v.push_back(s);
			}
		}
		sort(v.begin(), v.end(), comp);
		for(i = 0; i < v.size(); i++) {
			cout<<v[i]<<endl;
		}
	}
	return 0;
}
/*
Input:
7
123321
123454321
123
321
sdfsdfd
121212
\\dd\\
*/