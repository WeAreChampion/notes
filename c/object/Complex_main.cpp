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

    c=a+b;	//与类的友元函数调用operator+(a,b)等价
    c.Display();
    
    return 0;
}
