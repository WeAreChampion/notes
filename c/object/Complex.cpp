#include "Complex.h"
#include<iostream>
using namespace std;

Complex::Complex() {}
Complex:: Complex(int real,int imag):real_(real),imag_(imag) {}

void Complex::Display()const
{   cout<<real_<<','<<imag_<<endl;
}

Complex operator+(const Complex& one,const Complex& other)//友元函数的定义
{   int i,j;
    i=one.real_+other.real_;
    j=one.imag_+other.imag_;

    return Complex (i,j);
}

Complex::~Complex()
{
}
