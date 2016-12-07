#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int k = 0, m, n, i, j;
		cin >> m >> n;
		
		cout << " ";
		for(j = 0; j < n; j++) { 
			cout << "_";
		} 
		cout << endl;
		while(k <= m) {
			int t = pow(2, k);
			for(i = 1; i <= t; i++) {
				for(j = 0; j <= n + 1; j++) {
					if(i == t) {
						if(j == 0) { 
							cout << k;
						} else if(j != n + 1) { 
							cout << "_";
						} else { 
							cout << "|";
						} 
					} else {
						if(j == 0 || j == n + 1) { 
							cout << "|";
						} else {
							cout << " ";
						}
					}
				}
				cout << endl;
			}
			k++;
		}
	}
	return 0;
}