#include<iostream>
using namespace std;
#include<string>
string getResult(string s1, string s2)
{
	string s = "";
	int length = s1.size() / 2;
	s += s1.substr(0, length);
	s += s2;
	s += s1.substr(length, length);
	return s;
}
void test()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		string s1, s2;
		cin>>s1;
		cin>>s2;
		cout<<getResult(s1, s2)<<endl;
	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
2
HDCM
UA
Aw
CFlo

Sample Output
HDUACM
ACFlow

*/