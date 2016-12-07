#include<iostream>
#include<map>
using namespace std;
map<int, int> m;
int getSum(int array[], int length) {
	int sum = 0;
	for(int i = 0; i < length; i++) {
		map[array[i]]++;	
	}
	map<int, int>::iterator it;
	for(it = m.begin(); it != m.end(); it++) {
		int value = it->first;
		int counts = it->second;
		if(counts == 1) {
			sum += value;
		}
	}
	return sum;
}
void test() {
	int array[] = {1, 5, 3, 1};
	int length = 4;
	cout << "The sum is = " << getSum(array, length) << endl;
}
int main()
{
	void test();
	return 0;	
}
