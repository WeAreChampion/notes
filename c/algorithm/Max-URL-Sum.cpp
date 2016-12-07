#include<iostream>
using namespace std;
int main()
{
	int n, ca = 0;
	while(cin >> n) {
		ca++;
		string s;
		int i, j;
		__int64 max = 0;
		// To get the max url sum
		for(i = 0; i < n; i++) {
			cin >> s;
			__int64 sum = 0;
			for(j = 0; j < s.length(); j++) {
				sum += s[j];
			}
			if(max < sum) {
				max = sum;
			}
		}
		printf("Case %d: %I64d\n", ca, max);
	}
	return 0;
}