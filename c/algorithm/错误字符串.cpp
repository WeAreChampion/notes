#include<iostream>
using namespace std;
#include<cstdio>
/**
	电脑中的串错位，如Q->W，J->K
*/
void test() {
	char ch;
	// 电脑中键盘字符组成的字符串
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; 
	int i;
	while((ch = getchar()) != '\n') {
		for(i = 1; s[i] && s[i] != ch; i++);
		if(ch != ' ') {
			putchar(s[i - 1]);
		} else {
			putchar(ch);
		}
	}
}
int main() {
	test();
	return 0;
}
/**
Input:
O S, GOMR YPFSU/

Output:
I AM FINE TODAY
*/