#include<iostream>
using namespace std;
int main()
{
	int n, ca = 0;
	while(cin >> n && n > 0) {
		ca++;
		int a;
		__int64 sum = 0;
		
		//To get the sum
		for(int i = 0; i < n; i++) {
			cin >> a;
			sum += a;
		}
		printf("Sum of #%d is %I64d\n", ca, sum);
	}
	return 0;
}