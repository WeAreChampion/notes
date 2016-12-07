#include<iostream>
#include<string>
using namespace std;
int main()
{
	int ca;
	//having many cases.
	cin>>ca;
	while(ca--) {
		string a, b;
		cin>>a>>b;
		//a save the big number
		if(a.length() < b.length()) {
			string s = a;
			a = b;
			b = s;
		}
		int flag = 0, i, ss[1000], k = 0;
		//To calculate the sum
		for(i = b.length() - 1; i >= 0; i--) {
			ss[k] = a[i] - '0' + b[i] - '0' + flag;
			if(ss[k] > 9) {
				//进位标志 
				flag = 1;
				ss[k] = ss[k] - 10;
			} else {
				flag=0;
			}
			k++;
		}
		for(int j = a.length() - b.length() - 1; j >= 0; j--) {
			ss[k] = a[j] - '0' + flag;
			if(ss[k] > 9) {
				flag = 1;
				ss[k] = ss[k] - 10;
			}
			else {
				flag=0;
			}
			k++;
		}
		if(flag) {
			ss[k] = 1;
			cout<<1;
		}	
		for(i = k - 1; i >= 0; i--) {
			cout<<ss[i];
		}	
		cout<<endl;
	}
	return 0;
}