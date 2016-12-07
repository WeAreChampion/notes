#include<iostream>
using namespace std; 
union Student{  
	int i;  
	unsigned char ch[2];  
};  
int main()  
{  
	Student student;  
	student.i = 0x1420;//16 ½øÖÆ
	//14(16) = 1 * 16 + 4 = 20(10);
	//20(16) = 2 * 16 = 32(10)
	printf("%d  %d", student.ch[0], student.ch[1]);
	//result is 32 20
	return 0;  
}