#include<iostream>
using namespace std; 
void sub(char s1[], char s2[], char t[])
{
	int i, l2, l1, k;
	l2 = strlen(s2);
	l1 = strlen(s1);
	t[l1] = '\0';
	l1--;
	for(i= l2 - 1;i >= 0; i--,l1--) {
		if (s1[l1] - s2[i]>=0) { 
			t[l1] = s1[l1] - s2[i] + '0';
		} else {
			t[l1] = 10 + s1[l1] - s2[i] + '0';
			s1[l1 - 1] = s1[l1 - 1] - 1;
		}
	}
	k=l1;
	while(s1[k] < 0) {
		s1[k] += 10;
		s1[k - 1] -= 1;
		k--;
	}
	while(l1 >= 0) {
		t[l1] = s1[l1];
		l1--;
	}
	loop:
	if(t[0] == '0') {
		l1 = strlen(s1);
		for(i = 0; i < l1 - 1; i++) {
			t[i] = t[i + 1];
		} 
		t[l1 - 1] = '\0';
		goto loop;
	}
	if(strlen(t) == 0) {
		t[0] = '0';
		t[1] = '\0';
	}
	return ;
}
int main()
{
	char a[1000], b[1000];
	while(cin>>a>>b) {
		char c[1000];
		int flag = 0;
		if(strlen(a) < strlen(b) || strcmp(a, b) == -1) {
			flag = 1;
			char d[1000];
			strcpy(d, a);
			strcpy(a, b);
			strcpy(b, d);
		}
		sub(a, b, c);
		int i = 0;
		if(flag) {
			cout<<"-";
		}
		for(; c[i] != '\0'; i++) {
			cout<<c[i];
		}
		cout<<endl;
	}
	return 0;
}