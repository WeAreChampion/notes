#include<iostream>
using namespace std;
int main()
{
	int ca = 0;
	while(cin>>ca) {
		while(ca--) {
			int n, m, i, count = 0, a[1001];
			cin>>n>>m;
			for(i = 1; i <= n; i++) { 
				cin>>a[i];
			} 
			for(i = 1;i <= n; i++) { 
				if(a[i] > a[m]) { 
					count++;
				}
			} 
			cout<<count<<endl;
		}
	}
	return 0;
}