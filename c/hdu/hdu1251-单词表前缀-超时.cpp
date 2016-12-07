#include<iostream>
using namespace std;
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
bool comp(string s, char array[], int length) {
	int iS = 0;
	int iArray = 0;
	while(true) {
		if(s[iS] == array[iArray]) {
			iS++;
			iArray++;
			
			if(iArray == length) {
				return true;
			}
		} else {
			break;
		}
	}
	return false;
}
/*
	字典中统计以s开头的字符串
*/
int getCounts(vector<string> words, char array[], int length) {
	int counts = 0;
	
	int l = words.size();
	string str = "";
	for(int i = 0; i < l; i++) {
		//get the sub string and compare
		if(comp(words[i], array, length)) {
			counts++;
		}
	}
	return counts;
}
void test()
{
	string s;
	vector<string> words;
	while(getline(cin, s)) {
		if(s != "") {
			words.push_back(s);
		}
		else {
			break;
		}
	}
	char array[11];
	while(scanf("%s", &array) != EOF) {
		cout << getCounts(words, array, strlen(array)) << endl;
	}
}
int main()
{
	test();
	return 0;
}
/*
Sample Input
banana
band
bee
absolute
acm

ba
b
band
abc
 

Sample Output
2
3
1
0

*/