#include<stdio.h>
#include<string.h>
char str[110];
/*
	一个字符串如果有偶数个1，就是o，有奇数个1就是e。
给出缺了最后一位的字符串和它的属性，求补足最后
一位的字符串。
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
        //1 的个数为偶数 且 最后一个数字为'o'，意味着最后一个数字是1 
        if((cnt % 2 == 0 && str[len - 1] == 'o')
        //1的个数为奇数 且 最后一个数字为'e'，意味着最后一个数字是1 
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