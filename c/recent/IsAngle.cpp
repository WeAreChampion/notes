#include<iostream>
using namespace std;
bool isAngle(double vexA, double vexB, double vexC) {
	if(vexA * vexA == vexB * vexB + vexC * vexC
		|| vexB * vexB == vexA * vexA + vexC * vexC
		|| vexC * vexC == vexB * vexB + vexA * vexA) {
		return true;
	}
	return false;
}
void testIsAngle() {
	double vexA, vexB, vexC;
	while(cin >> vexA >> vexB >> vexC) {
		cout << "Is an Angle : " << isAngle(vexA, vexB, vexC) << endl;
	}
}
int main() {
	testIsAngle();
	return 0;
}