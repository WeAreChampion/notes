#include<iostream>
using namespace std;
/*
	字符串数字求和
	或者为整数转为字符串求和
*/
int main() {
	int n, a[100], sum, i, k, ca = 0;
	while(cin >> n)
	{
		// not the first row then print a line
		if(ca > 0)
			cout << endl;
		sum = 0, k = 0;
		while(n != 0) {
			a[k] = n % 10;
			n = n / 10;
			k++;
		}
		// to get the sum
		for(i = 0; i < k; i++)
			if(a[i] % 2 == 0)
				sum += a[i];
		cout << sum << endl;
		
		//count the case
		ca++;
	}
	return 0;
}