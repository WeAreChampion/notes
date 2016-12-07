#include<iostream> 
using namespace std;
#include<string> 
class BorrowMessage
{
private:
	string userId;
	string bookId;
	string startDate;
	int amount;
public:
	void setUserId(string userId);
	string getUserId();
	void setBookId(string bookId);
	string getBookId();
	void setStartDate(string startDate);
	string getStartDate();
	void setAmount(string amount);
	string getAmount();
};
void BorrowMessage::setUserId(string userId)
{
	this->userId=userId;
}
string BorrowMessage::getUserId()
{
	return userId;
}
void BorrowMessage::setBookId(string bookId)
{
	this->bookId=bookId;
}
string BorrowMessage::getBookId()
{
	return bookId;
}
void BorrowMessage::setStartDate(string startDate)
{
	this->startDate=startDate;
}
string BorrowMessage::getStartDate()
{
	return startDate;
}
void BorrowMessage::setAmount(string amount)
{
	this->amount=amount;
}
string BorrowMessage::getAmount()
{
	return amount;
}