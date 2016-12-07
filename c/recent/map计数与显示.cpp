#include<iostream>
using namespace std;
#include<map>
#include<string>
/*
根据输入的字符串，统计字符串出现的次数，相同次数输出显示加1
*/
void test() {
	int n;
	while(cin >> n) {
		map<string, int> saveMap;
		map<int, int> countsMap;
		
		saveMap.clear();
		countsMap.clear();
		string s = "";
		for(int i = 0; i < n; i++) {
			cin >> s;
			// add into map and counts
			saveMap[s]++;
		}
		
		// To get counts and save into countsMap
		map<string, int>::iterator it;
		for(it = saveMap.begin(); it != saveMap.end(); it++) {
			int counts = it->second;
			countsMap[counts]++;
		}
		
		// To get counts and sort
		map<int, int>::iterator it1;
		for(it1 = countsMap.begin(); it1 != countsMap.end(); it1++) {
			int counts = it1->second;
			int value = it1->first;
			cout << value << " : " << counts << endl;
		}
	}
}
int main() {
	test();
	return 0;
}
/*
Input:
5
BBA
BBA
BEA
DEC
CCF

Output:
1 : 3
2 : 1
*/