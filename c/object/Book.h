#include<iostream> 
using namespace std;
#include<string>
class Book
{
private:
	string bookId;
	string bookName;
	string bookAuthor;
	string bookPress;
	string bookInformation;
	double bookPrice;
	int bookCount;
public:
	void setBookId(string bookId);
	string getBookId();
	void setBookName(string bookName);
	string getBookName();
	void setBookAuthor(string bookAuthor);
	string getBookAuthor();
	void setBookPress(string bookPress);
	string getBookPress();
	void setBookInformation(string bookInformation);
	string getBookInformation();
	void setBookPrice(double bookPrice);
	double getBookPrice();
	void setBookCount(int bookCount);
	int getBookCount();
};
void Book::setBookId(string bookId)
{
	this->bookId=bookId;
}
string Book::getBookId()
{
	return bookId;
}
void Book::setBookName(string bookName)
{
	this->bookName=bookName;
}
string Book::getBookName()
{
	return bookName;
}
void Book::setBookAuthor(string bookAuthor)
{
	this->bookAuthor=bookAuthor;
}
string Book::getBookAuthor()
{
	return bookAuthor;
}
void Book::setBookPress(string bookPress)
{
	this->bookPress=bookPress;
}
string Book::getBookPress()
{
	return bookPress;
}
void Book::setBookInformation(string bookInformation)
{
	this->bookInformation=bookInformation;
}
string Book::getBookInformation()
{
	return bookInformation;
}
void Book::setBookPrice(double bookPrice)
{
	this->bookPrice=bookPrice;
}
double Book::getBookPrice()
{
	return bookPrice;
}
void Book::setBookCount(int bookCount)
{
	this->bookCount=bookCount;
}
int Book::getBookCount()
{
	return bookCount;
}