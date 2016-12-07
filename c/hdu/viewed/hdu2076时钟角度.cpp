#include<iostream>
using namespace std;
double getAbs(double a) {
	return a > 0 ? a : -a;
}
int getC(int hour, int minute, int second) {
	// The minute's angle
	double x = 6 * minute + 1.0 * second / 10;

	//the hour's angle
	double y = 30 * hour + 1.0 * minute / 2 + 1.0 * second / 120;

	//To get the abs value
	double value = getAbs(x - y);
	if(value >= 180.0) {
		return (int)(360 - value);
	}
	return (int)value;
}
void test() {

	int ca;
	cin >> ca;
	while(ca--) {
		int hour, minute, second;
		cin >> hour >> minute >> second;
		if(hour > 12) {
			//If the hour is bigger 12 then substract 12
			hour = hour - 12;
		}
		cout << getC(hour, minute, second) << endl;
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input

2
8 3 17
5 13 30

 

Sample Output

138
75
*/