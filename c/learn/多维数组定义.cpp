#include<iostream>
using namespace std;
void array(int **a)
{
	int i, j;
	a = new int*[10];
	for(i = 0; i < 10; i++) {
		a[i] = new int[10];
		for(j = 0; j < 10; j++) {
			a[i][j] = i + j;
		}
	}
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	for(i = 0; i < 10; i++) {
		delete []a[i];
	}
	delete []a;
}
//int (*aa)[5] = new int[5][5];
//int (*aa)[5][5] = new int[5][5][5];//the way to new int for room
void Array()
{
	int (*a)[10] = new int [10][10];
	int i, j;
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			a[i][j] = i + j;
		}
	}
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	for(i = 0; i < 10; i++) {
		delete []a[i];
	}
	delete []a;
}
int main()
{
	int **a;
	cout<<"array1:\n";
	array(a);
	cout<<"array2:\n";
	Array();
	return 0;
} 