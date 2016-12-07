#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void test() {
	
	int ca;
	cin >> ca;
	while(ca--) {
		int n;
		cin >> n;
		vector<int> v;
		v.clear();
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int sum = 0;
		int value = v[n / 2];
		for(int i = 0; i < n; i++) {
			sum += abs(value - v[i]);
		}
		cout << sum << endl;
	}
}
int main() {
	test();
	return 0;
}
/**
Sample Input
2
2 
2 4 
3 
2 4 6

 

Sample Output

2
4


*/