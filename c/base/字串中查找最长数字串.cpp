#include<iostream>
using namespace std;
int continumax(char *outputstr, char *inputstr) {
	int len = 0;
	char *pstart = NULL;
	int max = 0;
	while(1) {
		//If the char is number(digit) then len++
		if(*inputstr >= '0' && *inputstr <= '9') {
			len++;
		} else {//If the char isn't digit
			if(len > max) {
				pstart = inputstr - len;
				cout << "pstart = " << pstart << endl;
				max = len;
			}
			len = 0;
		}
		if(*inputstr++ == '\0') {
			break;
		}
	}
	for(int i = 0; i < max; i++) {
		*outputstr++ = *pstart++;
	}
	*outputstr = '\0';
	return max;
}
void test()
{
	char *inputstr = "abcd12345ed125ss123456789";
	cout << "inputstr = " << inputstr << endl;
	char *outputstr = new char[100];
	int length = continumax(outputstr, inputstr);
	cout << outputstr << endl;
}
void testChar()
{
	char *outputstr = "abcd12345ed125ss123456789";
	int i = 0;
	int length = strlen(outputstr);
	while(i < length) {
		cout << outputstr[i];
		i++;
	}
	cout << endl;
}
void testDispByPoint()
{
	char *outputstr = "abcd12345ed125ss123456789";
	char *point = outputstr;
	while(*point != '\0') {
		cout << (*point);
		point++;
	}
	cout << endl;
}
int main()
{
	test();
//	testChar();
//	testDispByPoint();
	return 0;
}
/*
output:
123456789
*/ 