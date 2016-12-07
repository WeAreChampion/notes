#include<iostream>
using namespace std;
int a[27][7]= {0};
/**
	初始化组合数a[i][j]表示C(i,j);
*/
void InitComponent() {
	int i, j, k;
	for(i = 26; i >= 0; i--) {
		a[i][0] = 1;
		a[i][1] = i;
		k = i + 1;
		for(j = 2; j < 7; j++) {
			if(j > i)
				break;
			a[i][j] = a[i][j - 1] * (k - j) / j;
		}
	}
}
/**
	判断读入字符串是否升序
*/
int ISValidate(char c[]) {
	int len = strlen(c), i;
	for(i = 0; i < len - 1; i++) {
		if(c[i] >= c[i + 1])
			return 0;
	}
	return 1;
}
int main() {
	int i, j, k, n, s, r;
	char str[7];
	InitComponent();
	cin >> n;
	while(n--) {
		cin >> str;
		if(!ISValidate(str)) {
			cout << "Invalid!\n";
			continue;
		}
		r = 1;
		s = strlen(str);
		for(j = 1; j  < s; j++) {
			r += a[26][j];
		}
		for(i = 0; i < (int)(str[0] - 'a'); i++) {
			r += a[25 - i][s - 1];
		}
		for(k = 1; k < s; k++) {
			for(i = (int)(str[k - 1] - 'a') + 1; i < (int)(str[k] - 'a'); i++) {
				r += a[26 - i - 1][s - k - 1];
			}
		}
		cout << str <<"\t" << r << endl;
	}
	return 0;
}
/*
in:
2
a
b
out:
1
2
*/