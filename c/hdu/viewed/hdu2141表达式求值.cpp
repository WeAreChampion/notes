/*
	集合中寻找A,B,C,判断是否存在整数i,j,k满足 
		Ai + Bj + Ck = X.
*/
#include<iostream>
#include<cmath>
using namespace std;
int sum;
int convert(int a, int b, int c, int x)
{
	int i = 0, j = 0;
	for(i = 0; ; i++) {
		int k = x - a * i - b * j;
		if(k < 0) { 
			break;
		} 
		for(j = 0; ; j++) {
			if(k < 0) {
				break;
			}
			if((x - a * i - b * j) % c == 0) {
				int kk = k / c;
				if((i == 0 && j != 0 && kk != 0) 
					|| (j == 0 && i != 0 && kk != 0) 
					|| (kk == 0 && j != 0 && i != 0))
					return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int l, m, n, i, ll[500], mm[500], nn[500], s, x[1000];
	int ca = 0;
	while(1) {
		ca++;
		cin>>l>>m>>n;
		for(i = 0; i < l; i++) { 
			cin>>ll[i];
		} 
		for(i = 0; i < m; i++) { 
			cin>>mm[i];
		} 
		for(i = 0; i < n; i++) { 
			cin>>nn[i];
		} 
		cin>>s;
		cout<<"Case "<<ca<<":"<<endl;
		for(i = 0; i < s; i++) {
			cin>>x[i];
		}
		for(i = 0; i < s; i++) {
			if(convert(ll[i], mm[i], nn[i], x[i])) { 
				cout<<"YES"<<endl;
			} 
			else { 
				cout<<"NO"<<endl;
			} 
		}
	}
	return 0;
}
/*
Sample Input
3 3 3
1 2 3
1 2 3
1 2 3
3
1
4
10

Sample Output
Case 1:
NO
YES
NO

*/