#include<iostream>
using namespace std;//去掉后面多余的0 
void RidLastZ(char *s)
{
	int len = strlen(s); 
	char *p = s + len - 1;
	//判断是不是含有小数
	if(strchr(s, '.')) {
		while(*p == '0') { 
			*p-- = NULL; //如果末尾是0，全部置空
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
		char *pa = a ,*pb = b;//指针跳过前面的0 
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
