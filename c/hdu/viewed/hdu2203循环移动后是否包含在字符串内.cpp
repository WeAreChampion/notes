#include<iostream>
#include<string>
using namespace std;
bool isInclude(string src, string dir) {
	
	if(dir.size() > src.size()) {
		return false;
	}
	if(src.size() == dir.size()) {
		if(src == dir) {
			return true;
		}
		return false;
	}
	
	//has find the dir in src then return true
	if(src.find(dir) != -1) {
		return true;
	}
	
	
	// index from string src to match dir
	int fromSrc = src.size() - dir.size() + 1;
	int initFromSrc = fromSrc;
	int endSrc = src.size();
	int fromDir = 0;
	int endDir = dir.size();
	bool flag = false;
	while(fromSrc < endSrc) {
		// is match
		if(dir[fromDir] == src[fromSrc]) {
			//is a circle in string src
			fromSrc = (fromSrc + 1) % endSrc;
			fromDir++;
			
			//
			if(fromDir == endDir) {
				flag = true;
				break;
			}
		} else {
			
			//reset the fromSrc
			if(fromSrc >= initFromSrc) {
				fromSrc = fromSrc - fromDir + 1;
			} else {
				fromSrc = endSrc - fromDir + 1;
			}
			
			//reset the fromDir index value with 0
			fromDir = 0;
		}
	}
	return flag;
}
void test() {
	
	string src, dir;
	while(cin >> src >> dir) {
		if(isInclude(src, dir)) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
AABCD
CDAA
ASD
ASDF
 

Sample Output
yes
no
*/