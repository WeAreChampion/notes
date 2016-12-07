#include<iostream>
#include<map>
using namespace std;
map<int, int> m;
/*
 * To get the sum from the array that the elements aren't same
 */
int getSum(int array[], int length) {
	int sum = 0;
	// For each the array and add into the map.
	for(int i = 0; i < length; i++) {
		m[array[i]]++;	
	}
	// Iterator the map and if the value is equals 1 then add into the sum
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
	test();
	return 0;	
}