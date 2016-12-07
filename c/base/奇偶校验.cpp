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
            //若ASCII码没有到达足够位数，默认补0 
            //1的个数为1，则表明校验位为1；否则为0
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
0的ASCII码是48
1的ASCII码是49 
...
9的ASCII码是57
校验位为在输出字符串开始处
奇校验：二进制串中1的个数为偶数，校验位为1，否则为0；
偶校验：二进制串中1的个数为奇数，校验位为1，否则为0；
3
3a
output:
10110011
10110011
01100001
*/ 