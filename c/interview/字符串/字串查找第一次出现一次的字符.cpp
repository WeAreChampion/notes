#include <iostream>
#include <string>
#include <cassert>
using namespace std;
/**
	���ݽṹ�洢�ַ���Ϣ������λ�ã������������ִ���
	Tn = O(n)
	Sn = O(1)
*/
struct Record
{
	int index;//��¼λ�� 
	int count;//��¼���� 
};
/*
	1. ����26�����ݽṹ����¼ÿ���ַ����ֵĴ��������һ����λ�á�
	2. ����ַ��������ֻ����������ŵĻ�����������256������������
	�ṹ���洢��
*/ 
char getFirstOnlyOneChar(string& str)
{
	// all char in str should be lower case
	Record records[26];
	
	// �������������ֵΪ0
	memset(records, 0, sizeof(Record) * 26);
	
	// �����ַ���
	int length = str.length();
	for (int i = 0; i < length; i++) {
		
		//ʹ�ö��ԣ���������ĸ������ 
		assert((str[i] <= 'z') && (str[i] >= 'a'));
		
		// ���м�����ͳ��
		records['z' - str[i]].count++;
		records['z' - str[i]].index = i;
	}
	
	// �����洢�ַ���Ϣ�����ݽṹ��index�����һ�γ��ֵ�λ��
	int index = length;
	for (int i = 0; i < 26; i++) {
		
		// ֻ����һ��
		if (records[i].count == 1) {
			
			// �����С����������һ�γ��� 
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