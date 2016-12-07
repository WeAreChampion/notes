#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n && n) {
		int a, i, max = 0;
		for(i = 0; i < n; i++) {
			cin >> a;
			if(a > max) { 
				max = a;
			} 
		}
		cout<<max<<endl;
	}
	return 0;
}