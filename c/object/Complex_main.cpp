#include<iostream>
#include "Complex.h"
#include "Complex.cpp"
using namespace std;
int main()
{   
	Complex a(10,5);
    Complex b(11,0);
    Complex c;

    a.Display();
    b.Display();

    c=a+b;	//�������Ԫ��������operator+(a,b)�ȼ�
    c.Display();
    
    return 0;
}
