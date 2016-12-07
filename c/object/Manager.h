#include<iostream>
using namespace std;
#include<string>
class Manager
{
private:
	string username;
	string password;
public:
	void setUsername(string username);
	string getUsername();
	void setPassword(string password);
	string getPassword();
};
void Manager::setUsername(string username)
{
	this->username=username;
}
string Manager::getUsername()
{
	return username;
}
void Manager::setPassword(string password)
{
	this->password=password;
}
string Manager::getPassword()
{
	return password;
}