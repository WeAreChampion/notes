#include<iostream>
using namespace std;
bool getScores(int counts, int score1, int score2) {
	int sum = score1;
	
	//没有红球了
	if(counts > 0 && counts <= 6) {
		for(int i = 7; i > 7 - counts; i--) {
			sum += i;
		}
	} else {
		//还有红球，余下的球全部打进
		sum += 8 * (counts - 6) + 27;
	}

	if(sum >= score2) {
		return true;
	}
	return false;
}
void test() {
	
	int ca;
	cin >> ca;
	while(ca--) {
		int counts, score1, score2;
		cin >> counts >> score1 >> score2;
		//当前分数已经够了
		if(score1 >= score2) {
			cout << "Yes" << endl;
			continue;
		}
		if(getScores(counts, score1, score2)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
2
12 1 1
1 30 39

 

Sample Output

Yes
No
*/