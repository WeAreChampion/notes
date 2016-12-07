#include<iostream>
using namespace std;
int main()
{
	__int64 a[100000], j, t, m;
	int n, i, s;
	cin>>n;
	for(i = 1; i <= n; i++) {
		s = 0;
		scanf("%I64d", &t);
		for(j = 0; j < t; j++) { 
			scanf("%I64d", &a[j]);
		} 
		m = a[0];
		cout<<"Case "<<i<<":"<<endl;
		for(j = 0; j < t; j++) { 
			if(m >= a[j]) { 
				m = a[j];
			} 
		} 
		for(j = 0; j < t; j++) { 
			s = s + a[j];
		} 
		s = s - 2 * m;
		printf("%I64d 1 %d\n", s, t - 1);
	}
	return 0;
}