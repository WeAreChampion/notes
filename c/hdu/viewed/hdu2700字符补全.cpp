#include<stdio.h>
#include<string.h>
char str[110];
/*
	һ���ַ��������ż����1������o����������1����e��
����ȱ�����һλ���ַ������������ԣ��������
һλ���ַ�����
*/ 
int main ()
{
    int i, cnt, len ;
    while (gets(str)) {
        if(strcmp(str, "#") == 0){
			break ;
		} 
        len = strlen(str) ;
        for(i = 0, cnt = 0; i < len - 1; i++){ 
            if(str[i] == '1') {
				cnt++;
			} 
        } 
        //1 �ĸ���Ϊż�� �� ���һ������Ϊ'o'����ζ�����һ��������1 
        if((cnt % 2 == 0 && str[len - 1] == 'o')
        //1�ĸ���Ϊ���� �� ���һ������Ϊ'e'����ζ�����һ��������1 
            || (cnt % 2 == 1 && str[len - 1] == 'e')) { 
            str[len - 1] = '1' ;
        } else {
			str[len-1] = '0' ;
		} 
        puts(str) ;
    }
    return 0 ;
}
/*
Sample Input
101e
010010o
1e
000e
110100101o
#

Sample Output
1010
0100101
11
0000
1101001010

*/