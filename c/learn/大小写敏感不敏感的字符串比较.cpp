#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
bool caseInsCharCompareN(char a, char b)
{
	return (toupper(a) == toupper(b));
}
bool caseInsCharCompareW(wchar_t a, wchar_t b)
{
	return (towupper(a) == towupper(b));
}
bool caseInsCompare(const string &s1, const string &s2)
{
	return ((s1.size() == s2.size()) && equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
}
bool caseInsCompare(const wstring &s1, const wstring &s2)
{
	return ((s1.size() == s2.size()) && equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareW));
}
void Test()
{
	string s1 = "In the BEGINNING...";
	string s2 = "In the beginning...";
	wstring ws1 = L"The END";
	wstring ws2 = L"the endd";
	if(caseInsCompare(s1, s2)) { 
		cout<<"Equal!"<<endl;
	} 
	else { 
		cout<<"Not Equal!"<<endl;
	} 
	if(caseInsCompare(ws1,ws2)) { 
		cout<<"Equal!"<<endl;
	} 
	else { 
		cout<<"Not Equal!"<<endl;
	} 
}
int main()
{
	Test();
	return 0;
}