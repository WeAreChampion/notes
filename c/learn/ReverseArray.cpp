#include<iostream>
using namespace std;
void Reverse(int array[], int left, int right) {
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
void Test() {
	int a[] = {1, 2, 3, 4, 5, 6}; 
	Reverse(a, 1, 4);
	for(int i = 0; i < 6; i++) {
		cout<<a[i]<<" "; 
	}
	cout<<endl;
}
int main() {
	Test();
	return 0;
}