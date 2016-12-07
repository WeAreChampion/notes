#include<iostream>
using namespace std;
int f(int n)
{
	int i;
	if(n < 2) { 
		return 0;
	} 
	for(i = 2; i * i <= n; i++) { 
		if(n % i == 0) { 
			return 0;
		}
	} 
	return 1;
}
int main()
{
	int n, m, a[1000], i, j = 0, count;
	for(i = 2; i < 1000; i++)
		if(f(i) == 1) {
			a[j] = i;
			j++;
		}
//	for(i=0;i<10;i++)
	//	cout<<a[i]<<endl;
	cin>>n;
	while(n--) {
		count = 0;
		cin>>m;
		if(f(m) == 1) {
			count++;
		}
		for(i = 0; a[i] <= m / 2; i++) {
			for(j = i; a[i] + a[j] <= m; j++) { 
				if(a[i] + a[j] == m) { 
					count++;
				}
			} 
		}
		cout<<count<<endl;
	}
	return 0;
}