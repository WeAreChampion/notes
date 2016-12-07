#include<iostream>
using namespace std;
int main()
{
	char a[210], b[210];
	int a1[210], b1[210], c[210];
	while(cin >> a >> b) {
		int i1 = strlen(a) - 1, i2 = strlen(b) - 1, k = 0, j, i;
		int flag = 0;
		while(1) {
			if(i1 < 0 && i2 < 0) { 
				break;
			} 
			if(i1 >= 0 && i2 >= 0) {
				a1[i1] = a[i1] - 65;
				b1[i2] = b[i2] - 65;
				c[k] = a1[i1] + b1[i2] + flag;
			}
			if(i1 < 0 && i2 >= 0) {
				b1[i2] = b[i2] - 65;
				c[k] = b1[i2] + flag;
			}
			if(i2 < 0 && i1 >= 0) {
				a1[i1] = a[i1] - 65;
				c[k] = a1[i1] + flag;
			}
			if(c[k] >= 26) {
				c[k] = c[k] - 26;
				flag = 1;
			} else {
				flag = 0;
			}
			k++;
			i1--;
			i2--;
		}
		if(flag) {
			c[k] = 1;
			for(i = 0; i <= k; i++) {
				a[i] = c[i] + 65;
			}
			for(i = k; i >= 0; i--) {
				if(a[i] != 'A') { 
					break;
				} 
			}			
		} else {
			for(i = 0; i < k; i++) {
				a[i] = c[i] + 65;
			} 
			for(i = k - 1; i >= 0; i--) {
				if(a[i] != 'A') { 
					break;
				} 
			}
		}
		for(j = i; j >= 0; j--) { 
			cout << a[j];
		} 
		cout << endl;
	}
	return 0;
}