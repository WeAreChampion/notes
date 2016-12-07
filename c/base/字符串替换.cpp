#include<iostream>
using namespace std;
/*
参数：
str[]：在此源字符串进行替换操作
key[]：被替换的字符串，不能为空串
swap[]：替换的字符串，可以为空串，为空串表示在源字符中删除key[]
返回值：null
注意：
默认str[]长度小于1000，如否，重新设定设定tmp 大小
需要string.h
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
		//查找是否存在相应的被替换串
		for(j = 0; j < l2; j++) {
			if (str[i + j] != key[j]) {
				flag = 0;
				break;
			}
		}
		//存在	
		if (flag) {
			strcpy(tmp, str);//复制给新串tmp 
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