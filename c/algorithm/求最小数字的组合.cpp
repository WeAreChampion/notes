#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(string s1, string s2)
{
	int i, j, k;
	for(i = 0,j = 0; i < s1.length() && j < s2.length(); i++, j++) {
		if(s1[i] - '0' == s2[j] - '0')
			continue;
		if(s1[i] - '0' > s2[j] - '0') {
			return true;
		}
	}
	k = 0;
	if(i == s1.length()) {
		while(k < s1.length() && j < s2.length()) {
			if(s1[k++] - '0' > s2[j]-'0')
				return false;
			j++;
		}
	}
	k = 0;
	if(j == s2.length()) {
		while(k < s2.length() && i < s1.length()) {
			if(s1[i] - '0' > s2[k++] - '0')
				return false;
			i++;
		}
	}
}
int main()
{
	int n;
	while(cin >> n && n) {
		int i;
		string s;
		vector<string> v;
		v.clear();
		for(i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(), comp);
		for(i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << endl;
	}
	return 0;
}