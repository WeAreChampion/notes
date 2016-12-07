#include<iostream>
using namespace std;
int main() 
{
	try {
		char *chararray = new char[100000];
		cout << "内存分配异常" << endl;
		delete []chararray;
	} catch(exception &error) {
		cout << error.what() << endl;
	}
	return 0;
}