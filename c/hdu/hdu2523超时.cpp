#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
bool comp(int a, int b)
{
	return a > b;
}
int absolute(int a)
{
	return a > 0 ? a : -a;
}
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		int a[1001];
		while(ca--) {
			int n, k;
			cin >> n >>k;
			for(int i = 0; i < n; i++) {
				cin >> a[i];
			}
			vector<int> v;
			v.clear();
			for(int i = 0; i < n; i++) {
				for(int j = i + 1; j < n; j++) {
					v.push_back(absolute(a[i] - a[j]));
				}
			}
			sort(v.begin(), v.end(), comp);
			cout<<v[k - 1]<<endl;
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