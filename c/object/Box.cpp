#include<iostream>
using namespace std;
class Box
{
public:
	int length;
	int width;
	int height;
	void Disp();
	Box();
	Box(int length,int width,int height);
	void setLength(int l);
	int getLength();
	void setWidth(int w);
	int getWidth();
	void setHeight(int h);
	int getHeight();
	int getVolume();
	int getArea(); 
	~Box(){}
};
void Box::Disp()
{
	cout<<"the Box length is:   "<<length;
	cout<<"\nthe Box Width is:  "<<width;
	cout<<"\nthe Box height is: "<<height<<endl;
}
Box::Box()
{
	length=width=height=0;
}
Box::Box(int length,int width,int height)
{
	this->length=length;
	this->width=width;
	this->height=height;
}
void Box::setLength(int l)
{
	length=l;
}
int Box::getLength()
{
	return length;
}
void Box::setWidth(int w)
{
	width=w;
}
int Box::getWidth()
{
	return width;
}
void Box::setHeight(int h)
{
	height=h;
}
int Box::getHeight()
{
	return length;
}
int Box::getArea()
{
	return 2*(length*width+length*height+width*height);
} 
int Box::getVolume()
{
	return length*width*height;
} 
int main()
{
	Box box(2,3,4);
	box.Disp();
	cout<<"the box area is: "<<box.getArea()<<endl;
	cout<<"the box volume is: "<<box.getVolume()<<endl;
	return 0;
} 