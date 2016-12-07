#include<iostream>
using namespace std;
#include<map>
/*
	1.To get the value that the amount is the largest, 
	and the amount must is bigger than the value of 
 	length / 2.
 	2.The Tn = O(n), Sn = O(1).
*/
int getManyValue(int array[], int length) {
	
	// 出现次数渐变值(相对值)
	int count = 1;
	
	// 用于保存当前时期的众数
	int manyValue = array[0];
	
	// 使用同增异减法找出众数
	for(int i = 1; i < length; i++) {
		
		// 与当前时期的众数相同
		if(array[i] == manyValue) {
			// 累加
			count++;
		} else {// 与当前时期的众数不同
			// 大于0
			if(count > 0) {
				count--;
			} else {// 重置为1
				manyValue = array[i];
				count = 1;
			}
		}
	}
	return manyValue;
}
/**
	累计众数并判断是否超过一半
*/
bool isMostTimes(int array[], int length) {
	int value = getManyValue(array, length);
	int count = 0;
	for(int i = 0; i < length; i++) {
		if(array[i] == value) {
			count++;
		}
	}
	if(count > length / 2) {
		return true;
	}
	return false;
}
void testGetManyValue() {
	int length = 10;
	int array[] = {
		2, 5, 5, 2, 5, 2, 5, 2, 5, 2
	};
	cout << getManyValue(array, length) << endl;
	int arrayC[] = {
		2, 2, 2, 3, 5, 5, 5, 2, 5, 5
	};
	cout << getManyValue(arrayC, length) << endl;
	int arrayB[] = {
		2, 2, 3, 2, 5, 5, 2, 2, 5, 2
	};
	cout << getManyValue(arrayB, length) << endl;
}
void testIsMostTimes() {
	int length = 10;
	int array[] = {
		2, 5, 5, 2, 5, 2, 5, 2, 5, 2
	};
	cout << (isMostTimes(array, length) ? "true" : "false") << endl;
	int arrayB[] = {
		2, 2, 3, 2, 5, 5, 2, 2, 5, 2
	};
	cout << (isMostTimes(arrayB, length) ? "true" : "false") << endl;
	int arrayC[] = {
		2, 2, 2, 3, 5, 5, 5, 2, 5, 5
	};
	cout << (isMostTimes(arrayC, length) ? "true" : "false") << endl;
}
/*
	The Tn = O(n), Sn = O(n).
	To get the number that the amount is the larger in the array.
	通过Map统计众数，并返回相应的值
*/
int getManyByMap(int array[], int length)
{
	map<int, int> counts;
	for(int i = 0; i < length; i++) {
		counts[array[i]]++;
	}
	map<int, int>::iterator it = counts.begin();
	int maxValue = it->first;
	int maxCount = it->second;
	it++;
	while(it != counts.end()) {
		if(maxCount < it->second) {
			maxCount = it->second;
			maxValue = it->first;
		}
		it++;
	} 
	cout << "value = " << maxValue << endl;
	cout << "count = " << maxCount << endl;
	return maxValue;
}
void testGetManyByMap()
{
	int length = 10;
	int array[] = {
		2, 5, 5, 2, 5, 2, 5, 2, 5, 2
	};
	getManyByMap(array, length);
	int arrayB[] = {
		2, 2, 3, 2, 5, 5, 2, 2, 5, 2
	};
	getManyByMap(arrayB, length);
	int arrayC[] = {
		2, 2, 2, 3, 5, 5, 5, 2, 5, 5
	};
	getManyByMap(arrayC, length);
}
int main()
{
//	testGetManyValue();
//	testIsMostTimes();
	testGetManyByMap();
	return 0;
}