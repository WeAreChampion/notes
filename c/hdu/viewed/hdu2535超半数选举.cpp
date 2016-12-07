#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
bool comp(int a, int b)
{
	return a < b;
}
void test()
{
	int n;
	while(scanf("%d", &n) != EOF && n) {
		vector<int> v;
		v.clear();
		int i;
		for(i = 0; i < n; i++) {
			int a;
			cin >>a;
			v.push_back(a);
		}
		sort(v.begin(), v.end(), comp);
		int length = v.size() / 2 + 1;
		int sum = 0;
		for(i = 0; i < length; i++) {
			sum += v[i] / 2 + 1;
		}
		cout<<sum<<endl;
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
5 7 5
0

Sample Output
6

*/