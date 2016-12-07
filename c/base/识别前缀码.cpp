#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
bool comp(string a, string b)
{
	return a < b;
}
/*
	判断dest串是否为source串的前缀，
	若是，返回true；否则返回false。 
*/ 
bool isPreString(string source, string dest)
{
	int length = dest.size();
	for(int i = 0; i < length; i++) {
		if(source[i] != dest[i]) {
			return false;
		}
	}
	return true;
}
/*
	判断vector<string> vString 容器中的编码是否是前缀码，
	若是，返回true；否则返回false。 
*/ 
bool isPreCode(vector<string> vString)
{
	int length = vString.size();
	for(int i = 0; i < length; i++) {
		for(int j = i + 1; j < length; j++) {
			if(isPreString(vString[j], vString[i])) {
				return false;
			}
		}
	}
	return true;
}
void test()
{
	vector<string> vString;
	vString.push_back("110");
//	vString.push_back("11");
	vString.push_back("010");
	vString.push_back("011");
	vString.push_back("10");
	sort(vString.begin(), vString.end(), comp);
	cout << (isPreCode(vString) ? "true" : "false") << endl;
}
int main()
{
	test(); 
	return 0;
}