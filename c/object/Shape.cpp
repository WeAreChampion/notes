#include<iostream>
using namespace std;
#include<string>
#include<cmath>
const double PI=3.1415926;
class Point
{
private:
	double x;
	double y;
public:
	Point(double x,double y);
	Point(Point &point);
	Point();
	void setX(double x);
	double getX();
	void setY(double y);
	double getY();
	~Point();
	double getDistance(Point x,Point y);
	double getDistance(Point x);
		//operator +
		//operator -
};
Point::Point(double x,double y)//���캯��(x,y) 
{
	this->x=x;
	this->y=y;
}
Point::Point(Point &point)//������ 
{
	x=point.x;
	y=point.y;
}
Point::Point()//�޲������캯�� 
{
	x=y=0;
}
void Point::setX(double x)//����X 
{
	this->x=x;
}
double Point::getX()//�õ�X 
{
	return x;
}
void Point::setY(double y)//����Y 
{
	this->y=y;
}
double Point::getY()//�õ�Y 
{
	return y;
}
Point::~Point()//�������� 
{
	cout<<"�ռ��Ѿ��ͷţ�\n";
} 
double Point::getDistance(Point x,Point y)//����֮��ľ��� 
{
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
double Point::getDistance(Point x)//��ԭ��ľ��� 
{
	return sqrt(x.x*x.x+x.y*x.y);
}
class Shape
{
public:
	virtual string getName();	//�õ�ͼ���� 
	virtual double getArea();	//area(���)
	virtual double getGirth();	//girth(�ܳ�) 
};
string Shape::getName()
{
	return "";
}
double Shape::getArea()
{
	return 0.0;
}
double Shape::getGirth()
{
	return 0.0;
} 
//���� 
class Rectangle:Shape
{
public:
	Rectangle();
	Rectangle(Rectangle &r);
	Rectangle(double length,double width);
	void setLength(int length);
	double getLength();
	void setWidth(int width);
	double getWidth();
	double getArea();
	double getGirth();
	string getName();
private:
	double length;
	double width;	
	Point point1,point2,point3,point4;
};
Rectangle::Rectangle()
{
	length=width=0;
}
Rectangle::Rectangle(Rectangle &r)
{
	length=r.length;
}
Rectangle::Rectangle(double length,double width)
{
	this->length=length;
	this->width=width;
}
void Rectangle::setLength(int length)
{
	this->length=length;
}
double Rectangle::getLength()
{
	return length;
}
void Rectangle::setWidth(int width)
{
	this->width=width;
}
double Rectangle::getWidth()
{
	return width;
}
double Rectangle::getArea()
{
	return length * width;
}
double Rectangle::getGirth()
{
	return 2 * (length + width);
}
string Rectangle::getName()
{
	return "Rectangle";
}
//circle
class Circle:Shape
{
public:
	void setR(int r);
	double getR();
	double getArea();
	double getGirth();
	void setPoint(Point point);
	Point getPoint();
	double getDiameter();
	Circle();
	Circle(double R);
	Circle(Circle &c);
	~Circle();
	string getName();
private:
	double R;
	Point point;
};
Circle::Circle()
{
	R=0;
	Point point(0,0);
}
Circle::Circle(double R)
{
	this->R=R;
}
Circle::Circle(Circle &c)
{
	R=c.R;
}
Circle::~Circle()
{
	cout<<"�ռ��Ѿ��ͷţ�\n";
}
void Circle::setR(int r)
{
	R=r;
}
double Circle::getR()
{
	return R;
}
double Circle::getArea()
{
	return PI * R * R;
}
double Circle::getGirth()
{
	return 2 * PI * R;
}
void Circle::setPoint(Point point)
{
	this->point=point;
}
Point Circle::getPoint()
{
	return point;
}
double Circle::getDiameter()//diameter
{
	return 2 * R;
}
string Circle::getName()
{
	return "Circle";
}
//triangle 
class Triangle:Shape
{
private:
	double height;
	double bottom;
	double length1,length2;
	Point point1,Point2,Point3;
public:
	double getHeight();
	void setHeight(double height);
	double getBottom();
	void setBottom(double bottom);
	void setLength1(double length);
	double getLength1();
	void setLength2(double length);
	double getLength2();
	string getName();
	double getArea();
	double getGirth();
};
double Triangle::getHeight()
{
	return height;
}
void Triangle::setHeight(double height)
{
	this->height=height;
}
double Triangle::getBottom()
{
	return bottom;
}
void Triangle::setBottom(double bootom)
{
	this->bottom=bottom;
}
void Triangle::setLength1(double length)
{
	this->length1=length;
}
double Triangle::getLength1()
{
	return length1;
}
void Triangle::setLength2(double length)
{
	this->length2=length2;
}
double Triangle::getLength2()
{
	return length2;
}
string Triangle::getName()
{
	return "Triangle";
}
double Triangle::getArea()
{
	return 0.5 * bottom * height;
}
double Triangle::getGirth()
{
	return length1 + length2 + bottom;
}