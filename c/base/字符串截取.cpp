#include<iostream>
using namespace std;
/* 
str[]��������Ŀ���ַ���
start���ӵ�start ���ַ�����ʼ����ȡ����Ϊlen ���ַ�
len���ӵ�start ���ַ�����ʼ����ȡ����Ϊlen ���ַ�
strback[]����ȡ�ĵ����ַ�
����ֵ��0�������ַ������ȣ���ȡʧ�ܣ�1����ȡ�ɹ�
*/
int mid(char str[], int start, int len, char strback[])
{
	int l, i, k = 0;
	l = strlen(str);
	if (start + len > l) { 
		return 0;
	} 
	for (i = start; i < start + len; i++) { 
		strback[k++] = str[i];
	} 
	strback[k] = '\0';
	return 1;
}
int main()
{
	char a[100], b[100];
	int len, start;
	while(cin>>a) {
		cout<<"start position: ";
		cin>>start;
		cout<<"the length: ";
		cin>>len;
		mid(a, start, len, b);
		cout<<b<<endl;
	}
	return 0;
}