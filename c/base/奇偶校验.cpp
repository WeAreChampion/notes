#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
char s[110];
int main() {
	while(gets(s) != NULL) {
		int len = strlen(s);
        int  s1[10];
        int ans = 0;
        for(int i = 0; i < len; i++) {
			memset(s1, 0, sizeof(s1));
			int k = 0;
			ans = 0;
			int temp = (int) s[i];
            while(temp != 0) {
				int value = (temp & 1);
               	s1[k++] = value;
               	if(temp & 1 == 1) { 
                  	ans++;
               	} 
               	temp = temp / 2;
            }
            //��ASCII��û�е����㹻λ����Ĭ�ϲ�0 
            //1�ĸ���Ϊ1�������У��λΪ1������Ϊ0
            if(ans % 2 == 1) { 
                s1[7] = 0;
            } 
            else {
                s1[7] = 1;
            }
            for(int j = 7; j >= 0; j--) { 
                printf("%d", s1[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
0��ASCII����48
1��ASCII����49 
...
9��ASCII����57
У��λΪ������ַ�����ʼ��
��У�飺�����ƴ���1�ĸ���Ϊż����У��λΪ1������Ϊ0��
żУ�飺�����ƴ���1�ĸ���Ϊ������У��λΪ1������Ϊ0��
3
3a
output:
10110011
10110011
01100001
*/ 