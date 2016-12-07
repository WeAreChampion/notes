#include<iostream>
#include<string>
using namespace std;
int comp(string a, string b)
{
	if(a.length() != b.length()) {
		return a.length() - b.length();//value a>value b,return >0;else return <0
	} else {
		for(int i = 0; i < a.length(); ++i) {
			if(a[i] - '0' == b[i] - '0') {
				continue;
			} else {
				return (a[i] - '0') - (b[i] - '0');
			}
		}
	}
	return 0;
}
int main()
{
	string a,b;
	while(cin>>a>>b) {
		if(a.length()==1 && b.length() == 1 && a[0] == '0' && b[0] == '0') {
			break;
		}
		cout<<(comp(a,b)?"no\n":"yes\n");
	}
	return 0;
} 