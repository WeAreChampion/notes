#include<iostream>
using namespace std;
#include<fstream>
const PI=3.14;
template<class Type>
class Point
{
protected:
	Type x;
	Type y;
public:
	Point(Type x,Type y);
	Point();
	Point(const Point &p);
	void setPoint(Type x,Type y);
	void setX(Type x);
	Type getX();
	void setY(Type Y);
	Type getY();
	virtual void Display();
	friend ostream &operator<<(ostream &output,Point &p)
	{
		output<<"("<<p.x<<","<<p.y<<")"<<endl;
		return output;
	}
	friend istream &operator>>(istream &input,const Point&p)
	{
		input>>p.x>>p.y;
		return input;
	} 
	~Point();
};
template<class Type>
Point<Type>::Point()
{
	x=y=0;
}
template<class Type>
Point<Type>::Point(Type x,Type y)
{
	this->x=x;
	this->y=y;
}
template<class Type>
Point<Type>::Point(const Point &p)
{
	x=p.x;
	y=p.y;
}
template<class Type>
void Point<Type>::setPoint(Type x,Type y)
{
	this->x=x;
	this->y=y;
}
template<class Type>
void Point<Type>::setX(Type x)
{
	this->x=x;
}
template<class Type>
Type Point<Type>::getX()
{
	return x;
}
template<class Type>
void Point<Type>::setY(Type Y)
{
	this->y=y;
}
template<class Type>
Type Point<Type>::getY()
{
	return y;
}
template<class Type>
void Point<Type>::Display()
{
	cout<<"the Point is: ("<<x<<","<<y<<")"<<endl;
}
template<class Type>
Point<Type>::~Point()
{
	cout<<"存储空间已经释放！"<<endl;
}
template<class Type>
class Circle :public Point<Type>
{
protected:
	double r;
public:
	Circle(Type x,Type y,double R):Point(x,y),r(R){}
	void setR(double r);
	double getR();
	double getArea();
};
template<class Type>
void Circle<Type>::setR(double r)
{
	this->r=r;
}
template<class Type>
double Circle<Type>::getR()
{
	return r;
}
template<class Type>
double Circle<Type>::getArea()
{
	return PI*r*r;
}
template<class Type>
int main()
{
	Point<int> p(1,2);
	p.Display();
	cout<<"the point is: "<<p;
	Circle<double> c;
	cout<<"the Area is: "<<c.getArea()<<endl;
	return 0;
}