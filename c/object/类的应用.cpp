#include<iostream>
using namespace std;
#include<string>
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
//-------------------------------------------------
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
	Complex operator+(Complex&c1);
	Complex operator-(Complex&c1);

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
Complex Complex::operator+(Complex&c1)
{
	Complex c;
	c.real=real+c1.real;
	c.imag=imag+c1.imag;
	return c;
}
Complex Complex::operator-(Complex&c1)
{
	Complex c;
	c.real=real-c1.real;
	c.imag=imag-c1.imag;
	return c;
}
//-----------------------------------------------------
class Date
{
private:
	int year;
	int month;
	int day;
public:
	void display();
	Date();
	Date(int y,int m,int d):year(y),month(m),day(d){}
};
Date::Date()
{
	year=month=day=0;
}
void Date::display()
{
	cout<<year<<"/"<<month<<"/"<<day<<endl;
}
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//-----------------------------------------------------
class Teacher
{
protected:
	string name;
	int age;
	char sex;
	string adress;
	int number;
	string title;
public:
	void display();
	Teacher::Teacher(string na,int a,char s,string ad,int n,string t);
};
void Teacher::display()
{
	cout<<name<<"\t"<<age<<"\t"<<sex<<"\t"<<endl<<adress<<"\t"<<number<<"\t"<<title<<endl;
}
Teacher::Teacher(string na,int a,char s,string ad,int n,string t)
{
	name=na;
	age=a;
	sex=s;
	adress=ad;
	number=n;
	title=t;
}
//-----------------------------------------------------
class Cadre
{
	protected:
		string name;
		int age;
		char sex;
		string adress;
		int number;
		string post;
	public:
		void out();
		Cadre::Cadre(string na,int a,char s,string ad,int n,string p);
};
Cadre::Cadre(string na,int a,char s,string ad,int n,string p)
{
	name=na;
	age=a;
	sex=s;
	adress=ad;
	number=n;
	post=p;
}
void Cadre::out()
{
	cout<<name<<"\t"<<age<<"\t"<<sex<<"\t"<<endl<<adress<<"\t"<<number<<"\t"<<post<<endl;
}
class Teacher_Cadre:public Teacher,public Cadre
{
protected:
	int wages;
public:
	void show();
	Teacher_Cadre(string na,int a,char s,string ad,int n,string t,string p,int w):
	Teacher(na,a,s,ad,n,t),Cadre(na,a,s,ad,n,p),wages(w){}
};
void Teacher_Cadre::show()
{
	display();
	cout<<post<<"\t"<<wages<<endl;
}
int main()
{
	Time a[10];
	int i,n;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
	        a[i].display();
		Date t(2011,1,2);
		t.display();
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
		(aa+bb).display();
		(aa-bb).display();
		Teacher_Cadre tt("zhangshan",20,'M',"YICHUN",123456,"Manager","BOSS",1234);
	    tt.show();
	}
	return 0;
}/*2 12 0 0*/