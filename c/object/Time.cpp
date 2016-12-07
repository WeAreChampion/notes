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
	void setHour(int hour);
	int getHour();
	void setMin(int min);
	int getMin();
	void setSec(int sec);
	int getSec();
	void Display();
	void Input();
	Time operator++();
	Time Time::operator++(int);
};
void Time::setHour(int hour)
{
	this->hour=hour;
}
int Time::getHour()
{
	return hour;
}
void Time::setMin(int min)
{
	this->min=min;
}
int Time::getMin()
{
	return min;
}
void Time::setSec(int sec)
{
	this->sec=sec;
}
int Time::getSec()
{
	return sec;
}
//输出当前时间 
void Time::Display()
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
//有参数构造函数 
Time::Time(int h,int m,int s)
{
	hour=h;
	min=m;
	sec=s;
}
//无参数构造函数 
Time::Time()
{
	hour=min=sec=0;
}
//输入相应的时间 
void Time::Input()
{
	cout<<"Input hour: ";
	cin>>hour;
	cout<<"Input Min: ";
	cin>>min;
	cout<<"Input Sec: ";
	cin>>sec;
}
//重载++运算符，++time
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
//重载++运算符，time++ 
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
int main() 
{
	Time t(11,2,3);
	t.Display();
	t++;
	t.Display();
	++t;
	t.Display(); 
	return 0;
}