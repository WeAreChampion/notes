#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(int a, int b)
{
	return a > b;
}
int getAbs(int a)
{
	return a > 0 ? a : -a;
}
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca--) {
			int n, k;
			cin >>n >> k;
			vector<int> a;
			vector<int> v;
			int value;
			v.clear();
			for(int i = 0; i < n; i++) {
				cin >> value;
				a.push_back(value);
			}
			sort(a.begin(), a.end());
			cout << "Array a:" << endl;
			for(int i = 0; i < a.size(); i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			int N = (-1 + (int) sqrt((double) (8 * k + 1))) / 2;
//			cout << "N = " << N << endl;
			int t = k - N * (N + 1) / 2;
//			cout << "t = " << t << endl;
			int absoluteValue;
			int length;
			if(t == 0) {
				length = N;
			} else {
				length = N + 1;
			}
			absoluteValue = n - length;
//			cout << "absoluteValue = " << absoluteValue << endl;
			for(int i = 0; i < length; i++) {
				v.push_back(getAbs(a[i + absoluteValue] - a[i]));
			}
			sort(v.begin(), v.end(), comp);
			cout << "Array v:" << endl;
			for(int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			if(t != 0) {
				cout << v[t - 1] << endl;
			} else {
				cout << v[v.size() - 1] << endl;
			}
				
		}
	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
3
3 2
4 0 7
4 2
1 2 3 4
2 1
2 9

Sample Output
4
2
7

*/