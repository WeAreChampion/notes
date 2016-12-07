#include <iostream>
#include <string>
#include <cassert>
using namespace std;
/**
	数据结构存储字符信息，包含位置，与数量即出现次数
	Tn = O(n)
	Sn = O(1)
*/
struct Record
{
	int index;//记录位置 
	int count;//记录数量 
};
/*
	1. 申请26个数据结构来记录每个字符出现的次数及最后一个的位置。
	2. 如果字符包含数字或者其他符号的话，可以申请256个该类型数组
	结构来存储。
*/ 
char getFirstOnlyOneChar(string& str)
{
	// all char in str should be lower case
	Record records[26];
	
	// 快速设置数组的值为0
	memset(records, 0, sizeof(Record) * 26);
	
	// 变量字符串
	int length = str.length();
	for (int i = 0; i < length; i++) {
		
		//使用断言，若不是字母，结束 
		assert((str[i] <= 'z') && (str[i] >= 'a'));
		
		// 进行计数与统计
		records['z' - str[i]].count++;
		records['z' - str[i]].index = i;
	}
	
	// 遍历存储字符信息的数据结构，index保存第一次出现的位置
	int index = length;
	for (int i = 0; i < 26; i++) {
		
		// 只出现一次
		if (records[i].count == 1) {
			
			// 保存较小的索引即第一次出现 
			if (records[i].index < index)
				index = records[i].index;
		}
	}
	return str[index];
}
int main()
{
	string str = "abaccdeff";
	cout << getFirstOnlyOneChar(str) << endl;
	system("pause");
	return 0;
}