#include<iostream>
#include<string>
using namespace std;
int a[50][50];
int b[50][50];
int cc[50][50];
int f(int na, int ma, int nb, int mb)
{
	if(ma != nb) {
		return 0;
	}
	for(int i = 0; i < na; i++) {
		for(int j = 0; j < mb; j++) {
			cc[i][j] = 0;
			for(int k = 0; k < nb; k++) {
				cc[i][j] = a[i][k] * b[k][j];
			}
		}
	}
	return 1;
}
int main()
{
	int ca;
	cin >> ca;
	for(int i = 1; i <= ca; i++) {
		int c, n, m, j, k, nn, mm, flag = 1;
		cin >> c;
		cin >> n >> m;
		for(j = 0; j < n; j++) {
			for(k = 0; k < m; k++) {
				cin >> a[j][k];
			}
		}
		c = c - 1;
		while(c--) {
			cin >> nn >>  mm;
			for(j = 0; j < n; j++) {
				for(k = 0;k < m; k++) {
					cin>>b[j][k];
				}
			}
			if(nn != m) {
				flag = 0;
			} else {
				f(n, m, nn, mm);
			}
			if(flag) {
				for(j = 0; j < n; j++) {
					for(k = 0; k < mm; k++) {
						a[j][k] = cc[j][k];
					}
				}
			}
			m = mm;
		}
		cout << "Case " << i << ":\n";
		if(flag) {
			for(j = 0; j < n; j++) {
				for(k = 0; k < m; k++) {
					if(k != m - 1)
						cout << a[j][k] << " ";
					else 
						cout << a[j][k] << endl;
				}
			}
		} else
			cout << -1 << endl;
	}
	return 0;
}