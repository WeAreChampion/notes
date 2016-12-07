#include<iostream>
#include<cstring>
using namespace std;
/*
������
str[]���ڴ�Դ�ַ������в��Ҳ���
key[]�������ҵ��ַ���������Ϊ�մ�
����ֵ��������ҳɹ�������key ��str �е�һ�γ��ֵ�λ�ã����򷵻�-1
ע�⣺
��Ҫstring.h
*/
int strfind(char str[], char key[])
{
	int l1, l2, i, j, flag;
	l1 = strlen(str);
	l2 = strlen(key);
	for (i = 0; i <= l1 - l2; i++) {
		flag = 1;
		for (j = 0; j < l2; j++) {
			if(str[i + j] != key[j]) {
				flag=0;
				break;
			}
		}
		if(flag) { 
			return i;
		} 
	}
	return -1;
}
int main()
{
	char a[100], b[100];
	while(cin>>a>>b) {
		int k = strfind(a, b);
		if(k == -1) {
			cout<<"Not find!\n";
		} else {
			cout<<"the positionis :"<<k<<endl;
		}
	}
	return 0;
}