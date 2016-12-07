#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
/*
	To get the Key Word Counts from long string dir (length is less 100000)
	by keywords map .
	But the time is limited.
*/
int getKeyWordCounts(map<string, int> keywords, string dir) {
	map<string,int>::iterator it;
	int sum = 0;
    for(it = keywords.begin(); it != keywords.end(); ++it) {
		//has find the key in dir
		if(dir.find(it->first) != -1) {
			//count the keyword
			sum += it->second;
		}
	}
	return sum;
}
void test() {
	int ca;
	cin >> ca;
	while(ca--) {
		int n;
		cin >> n;
		map<string, int> keywords;
		keywords.clear();
		string keyword;
		//input keyword and count the keyword
		for(int i = 0; i < n; i++) {
			cin >> keyword;
			keywords[keyword]++;
		}
		//input the dir string
		string dir;
		cin >> dir;
		
		cout << getKeyWordCounts(keywords, dir) << endl;
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
1
5
she
he
say
shr
her
yasherhs
 

Sample Output
3
*/