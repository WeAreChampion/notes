#include<iostream.h>
#include<iomanip.h>
class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h,int m,int s);
	Time();
	void set();
	void display();
	Time operator++();
	Time Time::operator++(int);
};
void Time::display()
{
	if(min>=10&&sec>=10)
		cout<<hour<<":"<<min<<":"<<sec<<endl;
	if(min>=10&&sec<10)
		cout<<hour<<":"<<min<<":0"<<sec<<endl;
	if(min<10&&sec<10)
		cout<<hour<<":0"<<min<<":0"<<sec<<endl;
	if(min<10&&sec>=10)
		cout<<hour<<":0"<<min<<":"<<sec<<endl;
}
Time::Time(int h,int m,int s)
{
	hour=h;
	min=m;
	sec=s;
}
Time::Time()
{
	hour=min=sec=0;
}
void Time::set()
{
	cin>>hour>>min>>sec;
}
Time Time::operator++()
{
	++sec;
	if(sec>=60)
	{
		++min;
		sec=0;
	}
	if(min>=60)
	{
		++hour;
		min=0;
	}
	return *this;
}
Time Time::operator++(int)
{
	Time temp(*this);
	sec++;
	if(sec>=60)
	{
		min++;
		sec=0;
	}
	if(min>=60)
	{
		hour++;
		min=0;
	}
	return temp;
}
class Complex
{
private:
	double real;
	double imag;
public:
	void display();
	Complex(double r,double i){real=r;imag=i;}
	Complex();
	Complex operator*(Complex&c1);
	Complex operator/(Complex&c1);

};
void Complex::display()
{
	if(imag>0)
		cout<<real<<"+"<<imag<<"i"<<endl;
	else if(imag==0)
		cout<<real<<endl;
	else 
		cout<<real<<imag<<"i"<<endl;
}
Complex::Complex()
{
	real=0;
	imag=0;
}
Complex Complex::operator*(Complex&c1)
{
	Complex c;
	c.real=real*c1.real-imag*c1.imag;
	c.imag=real*c1.imag+imag*c1.real;
	return c;
}
Complex Complex::operator/(Complex&c1)
{
	Complex c;
	c.real=(real*c1.real+imag*c1.imag)/(c1.real*c1.real+c1.imag*c1.imag);
	c.imag=(imag*c1.real-real*c1.imag)/(c1.real*c1.real+c1.imag*c1.imag);
	return c;
}
int main()
{
	Time a[10];
	int i,n;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
	        a[i].display();
	    Time b(10,12,3);
	    b.display();
	    for(i=0;i<n;i++)
			(++b).display();
        Time c(10,58,57);
		for(i=0;i<n;i++)
			(c++).display();
		Time d;
		d.set();
		d.display();
		Complex aa(3,4),bb(2,3);
		(aa*bb).display();
		(aa/bb).display();
	}
	return 0;
}/*2 12 0 0*/