#include<iostream.h>
#include<cmath>
const double PI=3.1415927;
class Shape//抽象基类
{
public:
	~Shape(){}
	virtual double area() const{return 0.0;}
	virtual double volume() const{return 0.0;}
	virtual void shapeName() const=0;
};
//===============================================
class Rectangle:public Shape//矩形类
{
public:
	double getLength() const{return length;}
	double getHeight() const{return height;}
	virtual void shapeName()const{cout<<"Rectangle:";}
	Rectangle(double l,double h):length(l),height(h){}
	void setRectangle(double ll,double hh);
	friend ostream &operator<<(ostream &output,const Rectangle &R);
	~Rectangle(){}
	virtual double area() const;
private:
	double length;
	double height;
};
void Rectangle::setRectangle(double ll,double hh)
{
	length=ll;
	height=hh;
}
ostream &operator<<(ostream &output,const Rectangle &R)
{
	output<<"length="<<R.length<<"\t"<<"height="<<R.height<<endl;
	return output;
}
double Rectangle::area() const
{
	return length*height;
}
//===========================================
class Triangle:public Shape//三角形类
{
public:
	double getFooter() const{return footer;}
	double getHeight() const{return height;}
	virtual void shapeName()const{cout<<"Triangle:";}
	Triangle(double f,double h):footer(f),height(h){}
	void setTriangle(double f,double h);
	friend ostream &operator<<(ostream &output,const Triangle &t);
	~Triangle(){}
	virtual double area() const;
private:
	double footer;
	double height;
};
void Triangle::setTriangle(double f,double h)
{
	footer=f;
	height=h;
}
ostream &operator<<(ostream &output,const Triangle &t)
{
	output<<"footer="<<t.footer<<"\t"<<"Height="<<t.height<<endl;
	return output;
}
double Triangle::area() const
{
	return 0.5*footer*height;
}
//=======================================
class Point:public Shape
{
public:
	double getX() const{return x;}
	double getY() const{return y;}
	virtual void shapeName()const{cout<<"Point:";}
	Point(double a,double b);
	void setPoint(double a,double b);
	friend ostream &operator<<(ostream &output,const Point &p);
	~Point(){}
protected:
	double x;
	double y;
};
Point::Point(double a,double b)
{
	x=a;
	y=b;
}
void Point::setPoint(double a,double b)
{	x=a;
	y=b;
}
ostream &operator<<(ostream &output,const Point &p)
{
	output<<"("<<p.x<<","<<p.y<<")"<<endl;
	return output;
}
//==========================================
class Circle:public Point
{
public:
	double getRadius() const{return radius;}
	virtual void shapeName()const{cout<<"Circle:";}
	void setRadius(double r);
	Circle(double a,double b,double r):Point(a,b),radius(r){}
	friend ostream &operator<<(ostream &output,const Circle &p);
	~Circle(){}
	virtual double area() const;
protected:
	double radius;
};
void Circle::setRadius(double r)
{
	radius=r;
}
ostream &operator<<(ostream &output,const Circle &c)
{
	output<<"("<<c.x<<","<<c.y<<")"<<"\t"<<"r="<<c.radius<<endl;
	return output;
}
double Circle::area()const
{
	return PI*radius*radius;
}
//========================================
class Cylinder:public Circle
{
public:
	double getHeight() const{return height;}
	virtual void shapeName()const{cout<<"Cylinder:";}
	void setHeight(double h);
	Cylinder(double a,double b,double r,double h):Circle(a,b,r),height(h){}
	friend ostream &operator<<(ostream &output,const Cylinder &cy);
	~Cylinder(){}
	virtual double area() const;
	virtual double volume() const;
protected:
	double height;
};
void Cylinder::setHeight(double h)
{
	height=h;
}
double Cylinder::area() const
{
	//return 2*PI*radius*height+2*PI*radius*radius;
	return 2*PI*radius*height+2*Circle::area();
}
double Cylinder::volume() const
{
	return Circle::area()*height;
}
ostream &operator<<(ostream &output,const Cylinder &cy)
{
	output<<"("<<cy.x<<","<<cy.y<<")"<<"\t"<<"r="<<cy.radius<<"\t"<<"h="<<cy.height<<endl;
	return output;
}
//=====================================================
class Cone:public Circle
{
public:
	double getBus() const{return bus;}
	virtual void shapeName()const{cout<<"Cone:";}
	void setBus(double bu);
	Cone(double a,double b,double r,double bu):Circle(a,b,r),bus(bu){}
	friend ostream &operator<<(ostream &output,const Cone &co);
	~Cone(){}
	virtual double area() const;
	virtual double volume() const;
protected:
	double bus;
};
void Cone::setBus(double bu)
{
	bus=bu;
}
ostream &operator<<(ostream &output,const Cone &co)
{
	output<<"("<<co.x<<","<<co.y<<")"<<"\t"<<"r="<<co.radius<<"\t"<<"bus="<<co.bus<<endl;
	return output;
}
double Cone::area() const
{
	return 0.5*bus*Circle::area();
}
double Cone::volume() const
{
	return Circle::area()*sqrt(bus*bus-radius*radius)/3;
}
//=================================================
class Ball:public Circle
{
public:
	double getBall() const{return R;}
	virtual void shapeName()const{cout<<"Ball:";}
	void setBall(double ba);
	Ball(double a,double b,double r,double rr):Circle(a,b,r),R(rr){}
	friend ostream &operator<<(ostream &output,const Ball &ba);
	~Ball(){}
	virtual double area() const;
	virtual double volume() const;
protected:
	double R;
};
void Ball::setBall(double ba)
{
	R=ba;
}
ostream &operator<<(ostream &output,const Ball &ba)
{
	output<<"("<<ba.x<<","<<ba.y<<")"<<"\t"<<"r="<<ba.radius<<"\t"<<"R="<<ba.R<<endl;
	return output;
}
double Ball::area() const
{
	return 4*PI*R*R;
}
double Ball::volume() const
{
	return 4*PI*R*R*R/3;
}
int main()
{
	Rectangle rectangle(4.0,8.0);
	Triangle triangle(3.0,6.0);
	Point point(1.1,2.2);
	Circle circle(2.4,1.2,5.6);
	Cylinder cylinder(3.5,6.4,5.2,10.5);
	rectangle.shapeName();
	cout<<rectangle;
	triangle.shapeName();
	cout<<triangle;
	point.shapeName();
	cout<<point;
	circle.shapeName();
	cout<<circle;
	cylinder.shapeName();
	cout<<cylinder;
    cout<<endl;

	Shape *pt;
	pt=&rectangle;
	pt->shapeName();
	cout<<"Length="<<rectangle.getLength()<<"\t"<<"Height="<<rectangle.getHeight()<<endl
		<<"area="<<pt->area()<<endl<<endl;
	pt=&triangle;
	pt->shapeName();
	cout<<"Footer="<<triangle.getFooter()<<"\t"<<"Height="<<triangle.getHeight()<<endl
		<<"area="<<pt->area()<<endl<<endl;
	pt=&point;
	pt->shapeName();
	cout<<"x="<<point.getX()<<"\t"<<"y="<<point.getY()<<endl<<"area="<<pt->area()<<endl
        <<"volume="<<pt->volume()<<endl<<endl;
	pt=&circle;
	pt->shapeName();
	cout<<"x="<<circle.getX()<<"\t"<<"y="<<circle.getY()<<endl<<"area="<<pt->area()<<endl
        <<"volume="<<pt->volume()<<endl<<endl;
	pt=&cylinder;
	pt->shapeName();
	cout<<"x="<<cylinder.getX()<<"\t"<<"y="<<cylinder.getY()<<endl<<"area="<<pt->area()<<endl
        <<"volume="<<pt->volume()<<endl;
	return 0;
}