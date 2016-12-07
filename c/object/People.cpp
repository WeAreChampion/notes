#include<iostream> 
#include<string> 
using namespace std;
class People
{
	private:
	string name;
	string IDnumber;
	int age;
	string sex;
	public:
	People();
	People(string name,string IDnumber,int age,string sex);
	People(People &people);
	void setName(People &people);
	string getName();
	void setIDnumber(People &people);
	string getIDnumber();
	void setAge(People &people);
	int getAge();
	void setSex(People &people);
	string getSex();
	void Disp();
	~People();
};
People::People()
{
	name=IDnumber=sex="";
	age=0;
}
People::People(string name,string IDnumber,int age,string sex)
{
	this->name=name;
	this->IDnumber=IDnumber;
	this->age=age;
	this->sex=sex;
}
People::People(People &people)
{
	name=people.name;
	IDnumber=people.IDnumber;
	age=people.age;
	sex=people.sex;
}
void People::setName(People &people)
{
	cin>>people.name;
}
string People::getName()
{
	return name;
}
void People::setIDnumber(People &people)
{
	cin>>people.IDnumber;
}
string People::getIDnumber()
{
	return IDnumber;
}
void People::setAge(People &people)
{
	cin>>people.age;
}
int People::getAge()
{
	return age;
}
void People::setSex(People &people)
{
	cin>>people.sex;
}
string People::getSex()
{
	return sex;
}
void People::Disp()
{
	cout<<"name is: "<<name<<endl;
	cout<<"IDnumber is: "<<IDnumber<<endl;
	cout<<"age is: "<<age<<endl;
	cout<<"sex is: "<<sex<<endl;
}
People::~People(){}
int main()
{
	People people;
	cout<<"请输入姓名：";
	people.setName(people);
	cout<<"请输入身份证号：";
	people.setIDnumber(people);
	cout<<"请输入年龄：";
	people.setAge(people);
	cout<<"请输入性别：";
	people.setSex(people);
	people.Disp();
//	cout<<"age is: "<<people.getAge()<<endl;
	return 0;
}
/*
zengtao
143124134
20
男 
*/