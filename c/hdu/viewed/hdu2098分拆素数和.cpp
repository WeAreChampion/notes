#include<iostream>
using namespace std;
int aaa(int n)
{
	int i;
	for(i = 2; i * i <= n; i++) {
		if(n % i == 0) { 
			return 0;
		} 
	}
	return 1;
}
int main()
{
	int a[8000];
	int i, n, t = 1, k = 2, j;
	a[0] = 2;
	a[1] = 3;
	for(i = 5; i < 10000; i = i + 2) {
		if(aaa(i) == 1) {
			a[k] = i;
			k++;
		}
	}
	while(scanf("%d", &n) != EOF && n) {
		int count = 0;
		for(i = 0; a[i] < n; i++) { 
			for(j = i; a[j] < n; j++) { 
				if(a[i] != a[j] && a[i] + a[j] == n) { 
					count++;
				}
			}
		} 
		cout << count << endl;
	}
	return 0;
}
/*
Sample Input
30
26
0
 

Sample Output
3 2
*/ 