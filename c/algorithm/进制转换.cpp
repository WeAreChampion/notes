#include<iostream>
using namespace std;
/*
�﷨��conversion(char s1[],char s2[],char t[]);
������
s[]��ת��ǰ������
s2[]��ת���������
d1��ԭ������
d2����Ҫת�����Ľ�����
����ֵ��null
ע�⣺
����9 ��λ���ô�д'A'��'Z'��ʾ��2��16 λ����ͨ����֤
*/
int conversion(char s[], char s2[], int d1, int d2)//�������ת�� 
{
	int i, j, t, num;
	char c;
	num = 0;
	for(i = 0; s[i] != '\0'; i++)//convert to 10
	{
		if(s[i] <= '9' && s[i] >= '0') { 
			t = s[i] - '0';
		} 
		else 
			t=s[i]-'A'+10;
		num=num*d1+t;
	}
	i=0;
	while(1)
	{
		t=num%d2;
		if (t<=9) 
			s2[i]=t+'0'; 
		else 
			s2[i]=t+'A'-10;
		num/=d2;
		if (num==0) 
			break;
		i++;
	}
	return i;
}
int main()
{
	int d1,d2;
	char a[1000];
	while(scanf("%s%d%d",a,&d1,&d2)!=EOF)
	{
		cout<<a<<" "<<d1<<" "<<d2<<endl;
		char b[1000];
		int k=conversion(a,b,d1,d2);
		for(int i=k;i>=0;i--)
		{
			cout<<b[i];
		} 
		cout<<endl;
	}
	return 0;
}