#include<iostream>
using namespace std;//ȥ����������0 
void RidLastZ(char *s)
{
	int len = strlen(s); 
	char *p = s + len - 1;
	//�ж��ǲ��Ǻ���С��
	if(strchr(s, '.')) {
		while(*p == '0') { 
			*p-- = NULL; //���ĩβ��0��ȫ���ÿ�
		} 
	} 
	if(*p == '.') { 
		*p = NULL; 
	} 
} 
int main() 
{ 
	char a[100000], b[100000];
	while(cin>>a>>b)
	{ 
		char *pa = a ,*pb = b;//ָ������ǰ���0 
		while(*pa == '0') { 
			pa++;
		} 
		while(*pb == '0') {
			pb++;
		} 
		RidLastZ(pa);
		RidLastZ(pb); 
		cout<<(!strcmp(pa, pb) ? "YES" : "NO")<<endl;
	} 
	return 0; 
}
