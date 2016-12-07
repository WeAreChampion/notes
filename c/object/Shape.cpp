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
Point::Point(double x,double y)//构造函数(x,y) 
{
	this->x=x;
	this->y=y;
}
Point::Point(Point &point)//对象构造 
{
	x=point.x;
	y=point.y;
}
Point::Point()//无参数构造函数 
{
	x=y=0;
}
void Point::setX(double x)//设置X 
{
	this->x=x;
}
double Point::getX()//得到X 
{
	return x;
}
void Point::setY(double y)//设置Y 
{
	this->y=y;
}
double Point::getY()//得到Y 
{
	return y;
}
Point::~Point()//析构函数 
{
	cout<<"空间已经释放！\n";
} 
double Point::getDistance(Point x,Point y)//两点之间的距离 
{
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
double Point::getDistance(Point x)//到原点的距离 
{
	return sqrt(x.x*x.x+x.y*x.y);
}
class Shape
{
public:
	virtual string getName();	//得到图形名 
	virtual double getArea();	//area(面积)
	virtual double getGirth();	//girth(周长) 
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
//矩形 
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
	cout<<"空间已经释放！\n";
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