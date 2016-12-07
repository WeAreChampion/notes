#include<iostream>
using namespace std;
class Box
{
/*
 * The attribute about Box
 */
public:
	double getLength();
	void setLength(double length);
	double getWidth();
	void setWidth(double width);
protected:
private:
	double length;
	double width;
};
/*
 * The method is getXXX()
 * To get Box's length
 */
double Box::getLength()
{
	return length;
}
/*
 * The method is setXXX()
 * To set Box's length
 */
void Box::setLength(double length)
{
	this->length=length;
}
/*
 * The method is getXXX()
 * To get Box's width
 */
double Box::getWidth()
{
	return width;
}
/*
 * The method is setXXX()
 * To set Box's width
 */
void Box::setWidth(double width)
{
	this->width=width;
}
void Test()
{
	Box *box=new Box();
	box->setLength(2);
	box->setWidth(3);
	cout<<"The box's length is :"<<box->getLength()<<"\n";
	cout<<"The box's width is :"<<box->getWidth()<<"\n";
}
int main()
{
	Test();
	return 0;
}