#include<iostream>
using namespace std;
/*
������
str[]���ڴ�Դ�ַ��������滻����
key[]�����滻���ַ���������Ϊ�մ�
swap[]���滻���ַ���������Ϊ�մ���Ϊ�մ���ʾ��Դ�ַ���ɾ��key[]
����ֵ��null
ע�⣺
Ĭ��str[]����С��1000����������趨�趨tmp ��С
��Ҫstring.h
*/
void Replace(char str[], char key[], char swap[])
{
	int l1, l2, l3, i, j, flag;
	char tmp[1000];
	l1 = strlen(str);
	l2 = strlen(key);
	l3 = strlen(swap);
	for(i = 0; i <= l1 - l2; i++) {
		flag = 1;
		//�����Ƿ������Ӧ�ı��滻��
		for(j = 0; j < l2; j++) {
			if (str[i + j] != key[j]) {
				flag = 0;
				break;
			}
		}
		//����	
		if (flag) {
			strcpy(tmp, str);//���Ƹ��´�tmp 
			strcpy(&tmp[i], swap);
			strcpy(&tmp[i + l3], &str[i + l2]);
			strcpy(str, tmp);
			i += l3 - 1;
			l1 = strlen(str);
		}
	}
}
int main()
{
	char a[100], b[100], c[100];
	while(cin>>a>>b>>c) {
		Replace(a, b, c);
		cout<<a<<endl;
	} 
	return 0;
}