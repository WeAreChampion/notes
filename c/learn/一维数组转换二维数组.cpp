#include<iostream>
using namespace std;
#define MAX_SIZE 100
#define MAX_ROW 10
#define MAX_COL 10
//the array of integer
int arrayInteger[MAX_SIZE];
//convert to the array of row
int row;
//convert to the array of col
int col;
int integer[MAX_ROW][MAX_COL];
void DispArray(int array[MAX_ROW][MAX_COL], int _rows, int _cols)
{
	cout << "the array is :" << endl;
	for(int i = 0; i < _rows; i++) {
		for(int j = 0; j < _cols; j++) {
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void Test()
{
	int integerAmount;
	cout << "input the integer Amount: ";
	while(cin >> integerAmount) {
		cout << "input " << integerAmount << " integers :";
		for(int i = 0; i < integerAmount; i++) {
			cin >> arrayInteger[i];
		}
		cout << "Input the col value: ";
		cin >> col;
		row = integerAmount / col;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				integer[i][j] = arrayInteger[i * col + j];
			}
		}
		int k = 0;
		for(int j = row * col; j < integerAmount; j++) {
			integer[row][k++] = arrayInteger[j];
		}
		DispArray(integer, row + 1, col);
		cout<<"input the integer Amount: ";
	}
}
int main()
{
	Test();
	return 0;
} 
/*
8
1 2 3 4 5 6 7 8
3
*/