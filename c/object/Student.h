#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	string studentId;
	int age;
	string adress;
	string phoneNumber;
	string profession;
public:
	void setName(string name);
	string getName();	
	void setStudentId(string studentId);
	string getStudentId();
	void setAge(int age);
	int getAge(); 
	void setAdress(string adress);
	string getAdress();
	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();
	void setProfession(string profession);
	string getProfession();
};
void Student::setName(string name)
{
	this->name=name;
}
string Student::getName()
{
	return name;
}
void Student::setStudentId(string studentId)
{
	this->studentId=studentId;
}
string Student::getStudentId()
{
	return studentId;
}
void Student::setAge(int age)
{
	this->age=age;
}
int Student::getAge()
{
	return age;
}
void Student::setAdress(string adress)
{
	this->adress=adress;
}
string Student::getAdress()
{
	return adress;
}
void Student::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber=phoneNumber;
}
string Student::getPhoneNumber()
{
	return phoneNumber;
}
void Student::setProfession(string profession)
{
	this->profession=profession;
}
string Student::getProfession()
{
	return profession;
}