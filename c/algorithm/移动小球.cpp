#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100
/**
	To find the value in array. If has find then return the index,
	else return -1.
*/
int findInArray(int array[], int n, int value) {
	int index = -1;
	for(int i = 1; i <= n; i++) {
		if(array[i] == value) {
			index = i;
			break;
		}
	}
	return index;
}
/**
	元素从from位置开始向右移动，添加value.
	即在from处添加value值的操作.
*/
void addInArray(int array[], int &n, int from, int value) {
	int i;
	for(i = n; i >= from; i--) {
		array[i + 1] = array[i];
	}
	array[from] = value;
	
	// 数据+1
	n++;
}
/**
	元素从from位置开始向左移动，删除value，返回删除的值.
	即在from处删除value值的操作，返回删除的值.
*/
int removeInArray(int array[], int &n, int from) {
	int value = array[from];
	for(int i = from; i < n; i++) {
		array[i] = array[i + 1];
	}
	// 数据-1
	n--;
	
	return value;
}
/**
	将x移到y的左边
	即在y的位置添加x的操作(先后移，再添加)
*/
void move2Left(int array[], int n, int x, int y) {
	int p = findInArray(array, n, x);
	int q = findInArray(array, n, y);
	
	// 1. y及y后的元素后移并添加x
	addInArray(array, n, q, x);
	
	// 2. x后的元素前移
	removeInArray(array, n, p);
}
void move2Right(int array[], int n, int x, int y) {
	int p = findInArray(array, n, x);
	int q = findInArray(array, n, y);
	
	// 1. y后的元素后移并添加x
	addInArray(array, n, q + 1, x);
	
	// 2. x后的元素前移
	removeInArray(array, n, p);
}
void displayArray(int array[], int n) {
	for(int i = 1; i <= n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
/**
	移动小球，考虑到小球的位置逻辑上是相邻的，可以使用数组存储
*/
void test() {
	int array[MAX_SIZE];
	int n, m;
	cin >> n >> m;
	
	// To init the array
	for(int i = 1; i <= n; i++) {
		array[i] = i;
	}
	
	string s = "";
	int x, y;
	
	/**
		输入移动形式
		A X Y   --> X 移到Y的左边
		B X Y   --> X 移到Y的右边
	*/
	for(int i = 0; i < m; i++) {
		cin >> s >> x >> y;
		if(s[0] == 'A') {
			move2Left(array, n, x, y);
		} else if(s[0] == 'B') {
			move2Right(array, n, x, y);
		}
	}
	displayArray(array, n);
}
int main() {
	test();
	return 0;
}
/*
Input
6 2
A 1 4
B 3 5

Output:
2 1 4 5 3 6

*/