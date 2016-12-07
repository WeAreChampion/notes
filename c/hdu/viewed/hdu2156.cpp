#include<iostream>
using namespace std;
int main()
{
	int n, i;
	double sum = 0.0;
	while(cin>>n && n) {
		int k = 1;
		
		//the row
		for(i = 1; i <= n - 1; i++) {
			sum += (2.0 / (i + 1)) * (n - k);
			k++;
		}
		sum += n;
		printf("%.2lf\n", sum);
	}
}
/*
Sample Input
1
2
3
4
0

Sample Output
1.00
3.00
5.67
8.83

*/