#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--) {
		string s;
		char a[100];
		int i = 0, j = 0;
		cin>>s;
//		cout<<s<<endl;
		for(i = 0; i < s.length(); i++) {
			if(s[i] == 'E' || s[i] == 'C' 
				|| s[i] == 'J' || s[i] == 'T'
					|| s[i] == 'U' || s[i] == 'A'
						|| s[i] == 'M') {
				a[j] = s[i];
				j++;
			}
			if(s[i] == '-') {
				--j;
				a[j] = ' ';
			}
		}
		for(i = 0; i < j; i++) {
			if(a[i] == 'E') {
				cout<<"Effort";
			}	
			if(a[i]=='C') { 
				cout<<"Confident";
			} 
			if(a[i]=='J') { 
				cout<<"Judicious";
			} 
			if(a[i]=='T') { 
				cout<<"Team";
			} 
			if(a[i]=='U') { 
				cout<<"Unique";
			} 
			if(a[i]=='A') { 
				cout<<"Amity";
			} 
			if(a[i]=='M') { 
				cout<<"Meticulous";
			} 
		}
		cout<<endl;
	}
	return 0;
}