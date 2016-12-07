#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n, a;
	while(cin >> n) {
		set<int> v;
		v.clear();
		int i, j, count = 0;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				cin >> a;
				if(a == 1 && i > j) {
					v.insert(i);
					v.insert(j);
				}
			}
		}
		if(v.size() == n) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
	return 0;
}