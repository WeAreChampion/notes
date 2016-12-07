#include<iostream>
using namespace std;
#define LIST_SIZE 20
typedef int KeyType; 
typedef int OtherType;
typedef struct {
	KeyType key;
	OtherType otherData;
}RecordType;
struct RecordList{
	RecordType recordType[LIST_SIZE + 1];
	int length;
};
int seqSearch(RecordList recordList, RecordType recordType)
{
	//as the mark
	recordList.recordType[0] = recordType;
	int i = recordList.length;
	while(recordList.recordType[i].key != recordType.key) {
		i--;
	}
	//If not find then return 0, else return the pos i in the array
	return i;
}
void testSeqSearch()
{
	RecordType recordType[] = {
		{1, 'a'},
		{2, 'b'},
		{3, 'c'},
		{4, 'd'} 
	};
	RecordList recordList;
	recordList.length = 4;
	for(int i = 0; i < recordList.length ; i++) {
		recordList.recordType[i + 1] = recordType[i];
	}
	RecordType temp;
	temp.key = 2;
	cout << seqSearch(recordList, temp) << endl;
}
int main()
{
	testSeqSearch();
	return 0;
}
