#include<iostream>
using namespace std; 
//c[]�������������ַ�����ʾ��λ������
//t[]����������ַ�����ʾ
//m���������޶�10 ����
void mult(char c[],char t[],int m)//������С�� 
{
	int i,l,k,flag,add=0;
	char s[100];
	l=strlen(c);
	for (i=0;i<l;i++)
		s[l-i-1]=c[i]-'0';
	for (i=0;i<l;i++)
	{
		k=s[i]*m+add;
		if (k>=10) 
		{
			s[i]=k%10;
			add=k/10;
			flag=1;
		} 
		else
		{
			s[i]=k;
			flag=0;
			add=0;
		}
	}
	if (flag)
 	{
		 l=i+1;
		 s[i]=add;
	 } 
	 else
	 	 l=i;
	for (i=0;i<l;i++)
		t[l-1-i]=s[i]+'0';
	t[l]='\0';
}
int main()
{
	char a[1000];
	int m;
	while(cin>>a>>m)
	{
		char b[1000];
		mult(a,b,m);
		int i=0;
		for(i=0;b[i]!='\0';i++)
		{
			cout<<b[i];
		}
		cout<<endl;
	}
	return 0;
}