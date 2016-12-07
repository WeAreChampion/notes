#include <stdio.h>
int main()
{
	int n, i, y, r, b, l;
	char a[16];
	while(scanf("%d", &n) != EOF && n) {
		scanf("%s", a);
		y = r = b = l = 0;
		for(i = 0; i < n; i++) {
			if(a[i] == 'Y') {//打进黄球的数量 
				y++;
			} else if(a[i] == 'R') {//打进红球的数量 
				r++;
			} else if(a[i] == 'B') {//红方打进黑球 
				b++;
			} else if(a[i] == 'L') {//黄方打进黑球 
				l++;
			}
		}
		if(b == 1) {//红方打进黑球 
			if(r == 7) {//红球已经全进，红方胜 
				printf("Red\n");
			} else {//否则黄方胜 
				printf("Yellow\n");
			} 
		} else if(l == 1) {//黄方打进黑球 
			if(y == 7) {//黄球已经全进，黄方胜 
				printf("Yellow\n");
			} else {//否则红方胜 
				printf("Red\n");
			} 
		}
	}
	return 0;
}
/*
Sample Input
5
RYRRB
9
RRRRYRRRB
0
 

Sample Output
Yellow
Red


*/ 