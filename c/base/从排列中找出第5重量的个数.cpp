#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	int n;
	while(cin >> n) {
		int i, a;
		vector<int> v;
		v.clear();
		for(i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end(), comp);
		int count = 1, m = v[0], num = 0;
		for(i = 1; i < v.size(); i++) {
			if(v[i] == m) {
				if(count == 5) {
					num++;
				}
				continue;
			} else {
				m = v[i];
				count++;
				if(count == 5) {
					num++;
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}