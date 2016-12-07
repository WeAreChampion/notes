#include<iostream>
using namespace std;
/*
	To get the minimum cards
*/
int getCountCard(double s) {
	double sum = 0.0;
	int i;
	for(i = 1; ; i++) {
		if(sum < s){
			sum = sum + 1.0 / (i + 1);
		} else {
			break;
		}
	}
	return i - 1;
}
void test() {
	double s;
	while(cin >> s) {
		if(s <= 0.0) {
			break;
		}
		cout << getCountCard(s) << " card(s)" << endl;
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
1.00
3.71
0.04
5.19
0.00
 

Sample Output
3 card(s)
61 card(s)
1 card(s)
273 card(s)
*/