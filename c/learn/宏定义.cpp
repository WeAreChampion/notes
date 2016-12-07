#include<iostream>
using namespace std;
#define MAX(a, b) a > b ? a : b;
#define MIN(a, b) a < b ? a : b;
void testMax()
{
	int a = 12, b = 8;
	int intValue = MAX(a,b);
	cout<<intValue<<endl;
	double doubleA = 12.1, doubleB = 8.2;
	double doubleValue = MAX(doubleA,doubleB);
	cout<<doubleValue<<endl;
}
void testMin()
{
	int a = 12, b = 8;
	int intValue = MIN(a,b);
	cout<<intValue<<endl;
	double doubleA = 12.1, doubleB = 8.2;
	double doubleValue = MIN(doubleA,doubleB);
	cout<<doubleValue<<endl;
}
int main()
{
	testMax();
	testMin();
	return 0;
}