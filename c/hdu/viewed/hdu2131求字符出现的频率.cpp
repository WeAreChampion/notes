#include<iostream>
#include<string>
using namespace std;
int main()
{
	char a;
	string s = "";
	int i, sum;
	while(cin>>a>>s) {
		sum = 0;
		getchar();
		int length = s.size();
		for(i = 0; i < length; i++) {
			if(s[i] == a || s[i] == a - 32 || s[i] == a + 32) { 
				sum++;
			} 
		}
		double ss;
		ss = sum * 1.0 / s.size();
		printf("%.5lf\n", ss);
	}
	return 0;
}