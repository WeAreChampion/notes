#include<iostream>
using namespace std;
/*
0 < a < b < n and (a^2+b^2 +m)/(ab)is integer
count++;
*/ 
int main()
{
	int t, n, m;
	cin>>t;
	for(int k = 0; k < t; k++) {
		int ca = 0;
		if(k > 0) { 
			cout<<endl;
		} 
		while(cin>>n>>m) {
			ca++;
			if(n == 0 && m == 0) {
				break;
			}
			int i, sum, j, count = 0;
			for(i = 1; i < n; i++) {
				for(j=i + 1; j < n; j++) {
					if((i * i + j * j + m) % (i * j) == 0) { 
						count++;
					}
				} 
			}
			cout<<"Case "<<ca<<": "<<count<<endl;
		}
	}
	return 0;
}
