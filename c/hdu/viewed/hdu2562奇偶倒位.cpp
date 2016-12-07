#include<iostream>
#include<string>
using namespace std;
string getResult(string s1)
{
	string s = "";
	int length = s1.size();
	for(int i = 0; i < length; i += 2) {
		s += s1[i + 1];
		s += s1[i];
	}
	return s;
}
void test()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			string s1;
			cin>>s1;
			cout<<getResult(s1)<<endl;	
		}
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
0110
1100

Sample Output
1001
1100

*/