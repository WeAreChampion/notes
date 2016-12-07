#include<iostream>
using namespace std;
#define MAX_SIZE 50
#define MAX_P 50
//the method 1
void MoveArray(int array[], int length, int p)
{
	if(p == length) {
		return ;
	}
	if(p > length) {
		p = p % length;
	}
	int *temp = new int[p];
	for(int i = 1; i <= p; i++) {
		temp[i] = array[i + length - p];
	}
	for(int i = length - p; i >= 1; i--) {
		array[i + p] = array[i];
	}
	for(int i = 1; i <= p; i++) {
		array[i] = temp[i];
	}
	delete temp;
}
void DispArray_0(int array[], int length)
{
	for(int i = 1;i <= length; i++) {
		cout<<array[i]<<"  ";
	}
	cout<<endl;
}
void DispArray_1(int array[], int length)
{
	for(int i = 0; i < length; i++) {
		cout<<array[i]<<"  ";
	}
	cout<<endl;
}
//the method 2
void Reverse(int array[], int left, int right)
{
	int length = right - left + 1;
	if(length <= 1) {
		return ;
	}
	for(int i = left; i <= (left + right) / 2; i++) {
		//swap the item
		int temp = array[i];
		array[i] = array[left + right - i];
		array[left + right - i] = temp;
	}
}
void TestReverse()
{
	int array[] = {1,2,3,4,5};
	int length = 5;
	Reverse(array, 1, 3); 
	for(int i = 0; i < length; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void sift_left(int array[], int length, int p)
{
	if(p == length) {
		return ;
	}
	if(p > length) {
		p = p % length;
	}
	Reverse(array, 0, length - 1);
	//DispArray_1(array,length);
	Reverse(array, 0, p - 1);
	//DispArray_1(array,length);
	Reverse(array, p, length - 1);
	DispArray_1(array, length);
} 
void Test()
{
	int length;
	int array[MAX_SIZE];
	cout<<"the length of array: ";
	while(cin>>length) {
		for(int i = 0; i < length; i++) {
			cin>>array[i];
		}
		cout<<"the move times: ";
		int p;
		cin>>p;
		DispArray_1(array, length);
		//MoveArray(array,length,p);
		//DispArray_0(array,length);
		sift_left(array, length, p);
		//DispArray_1(array,length);
		cout<<"the length of array: ";
	}
}
/*
5
1 2 3 4 5
3
*/
int main()
{
	//Test();
	TestReverse();
	return 0;
}