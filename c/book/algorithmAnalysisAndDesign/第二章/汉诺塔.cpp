#include<iostream>
using namespace std;
/**
	To print disk move path from a to b
*/
void moveDish(char a, char b)
{
	printf("%c-->%c\n", a, b);
}
/**
	To print the move path from x to z with the help of y
*/
void hanoi(int n, char x, char y, char z)
{
	/*
		The exist
		only a dish,move a dish from x to z
	*/
	if(n == 1) {
		moveDish(x, z);
	} else {
		//move n-1 dishes from x to y by z
		hanoi(n - 1, x, z, y);

		//move a dish from x to z(the biggest dish)
		moveDish(x, z);
		//move n-1 dishes from y to z by x
		hanoi(n - 1, y, x, z);
	}
}
int main()
{
	int n;
	while(cin >> n) {
		hanoi(n, 'A', 'B', 'C');
	}
	return 0;
}