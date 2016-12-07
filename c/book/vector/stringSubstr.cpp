#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void Test()
{
	string s = "E->TE'";
	s = "E'->+TE'|¦Å";
	int pos = s.find("->");
	string left = s.substr(0, pos);
	string right = s.substr(pos + 2, s.length() - pos-2);
	cout << left <<"->" << right << endl;
}
int main()
{
	Test();
	return 0;
} 