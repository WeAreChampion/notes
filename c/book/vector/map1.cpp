#include<iostream>
using namespace std;
#include<map>
#include<string>
#include<vector>
void testMapString()
{
	map<string, int> mapString;
	vector<string> vString;
	int length = 6;
	vString.push_back("AAA");
	vString.push_back("AAA");
	vString.push_back("BBB");
	vString.push_back("AAA");
	vString.push_back("CCC");
	vString.push_back("BBB");
	for(int i = 0; i < length; i++) {
		mapString[vString[i]]++;
	}
	map<string, int>::iterator it;
	for(it = mapString.begin(); it != mapString.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
	mapString.clear();
	vString.clear();
}
void testMapInt()
{
	int array[] = {
		1, 2, 4, 5, 3, 1, 2, 1
	};
	int length = 8;
	map<int, int> mapInt;
	for(int i = 0; i < length; i++) {
		mapInt[array[i]]++;
	}
	map<int, int>::iterator it;
	for(it = mapInt.begin(); it != mapInt.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
}
int main()
{
//	testMapString();
	testMapInt();
	return 0;
}