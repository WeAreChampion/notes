#include<iostream>
using namespace std;
typedef int KeyType;
#define INDEX_INFO_MAX_SIZE 20
typedef struct
{
	KeyType maxData;
	int maxDataPos;
	int startPos;
}IndexInfo;
typedef struct {
	IndexInfo indexInfo[INDEX_INFO_MAX_SIZE + 1];
	int length;
}Info;
int findInInfoByIndex(Info info, KeyType data, KeyType source[], int length)
{
	int high = info.length - 1;
	int low = 0;
	int pos;
	int mid;
	while(low < high) {
		mid = (high + low) / 2;
		if(info.indexInfo[mid].maxData < data) {
			low = mid + 1;
		} else if(info.indexInfo[mid].maxData == data) {
			return info.indexInfo[mid].maxDataPos;
		} else {
			high = mid - 1;
		}
	}
	cout << "low = " << low << endl;
	cout << "high = " << high << endl;
	
	int start;
	if(info.indexInfo[high].maxData < data) {
		start = info.indexInfo[high + 1].startPos;
	} else {
		start = info.indexInfo[high].startPos;
	}
	cout << "start pos : " << start << endl;
	int end;
	if(high >= (info.length - 2)) {
		end = length - 1;
	} else {
		end = info.indexInfo[high + 2].startPos;
	}
	cout << "end pos : " << end << endl;
	for(int i = start; i <= end; i++) {//info.indexInfo[high + 1].startPos
		if(source[i] == data) {
			return i;
		}
	}
	return -1;
}
void test()
{
	Info info;
	info.length = 3;
	info.indexInfo[0].maxData = 25;
	info.indexInfo[0].maxDataPos = 3;
	info.indexInfo[0].startPos = 0;
	
	info.indexInfo[1].maxData = 58;
	info.indexInfo[1].maxDataPos = 9;
	info.indexInfo[1].startPos = 5;
	
	info.indexInfo[2].maxData = 88;
	info.indexInfo[2].maxDataPos = 11;
	info.indexInfo[2].startPos = 10;
	
	int source[] = {
		18, 14, 12, 25, 8, 28, 32, 45, 36, 58, 60, 88, 71
	};
	int length = 13;
	
	cout << "result = " << findInInfoByIndex(info, 18, source, length) << endl;
	cout << endl; 
	
	cout << "result = " << findInInfoByIndex(info, 14, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 12, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 25, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 8, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 32, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 45, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 36, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 58, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 60, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 88, source, length) << endl;
	cout << endl;
	
	cout << "result = " << findInInfoByIndex(info, 71, source, length) << endl;
}
int main()
{
	test();
	return 0;
}