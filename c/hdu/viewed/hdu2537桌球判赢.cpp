#include <stdio.h>
int main()
{
	int n, i, y, r, b, l;
	char a[16];
	while(scanf("%d", &n) != EOF && n) {
		scanf("%s", a);
		y = r = b = l = 0;
		for(i = 0; i < n; i++) {
			if(a[i] == 'Y') {//������������ 
				y++;
			} else if(a[i] == 'R') {//������������ 
				r++;
			} else if(a[i] == 'B') {//�췽������� 
				b++;
			} else if(a[i] == 'L') {//�Ʒ�������� 
				l++;
			}
		}
		if(b == 1) {//�췽������� 
			if(r == 7) {//�����Ѿ�ȫ�����췽ʤ 
				printf("Red\n");
			} else {//����Ʒ�ʤ 
				printf("Yellow\n");
			} 
		} else if(l == 1) {//�Ʒ�������� 
			if(y == 7) {//�����Ѿ�ȫ�����Ʒ�ʤ 
				printf("Yellow\n");
			} else {//����췽ʤ 
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