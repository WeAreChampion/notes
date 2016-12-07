#include<iostream>
#include"Person.cpp"
using namespace std; 
class Student :public Person
{
public:
	string schoolName;
	string schoolId;
	void setSchoolName(string na);
	string getSchoolName();
	void setSchoolId(string Id);
	string getSchoolId();
	void Disp();
	Student();
	Student(string na,string se,string number,string Name,string sid):
		Person(na,se,number),schoolName(Name),schoolId(sid){}
	Student(Student &s);
	~Student(){}
};
void Student::setSchoolName(string na)
{
	schoolName=na;
}
string Student::getSchoolName()
{
	return schoolName;
}
void Student::setSchoolId(string Id)
{
	schoolId=Id;
}
string Student::getSchoolId()
{
	return schoolId;
}
void Student::Disp()
{
	Person::Disp();
	cout<<"schoolName is: "<<schoolName<<endl;
	cout<<"schoolId is: "<<schoolId<<endl;
}
Student::Student():Person()
{
	schoolName="";
	schoolId="";
}
Student::Student(Student &s)
{
	name=s.name;
	sex=s.sex;
	Id=s.Id;
	schoolName=s.schoolName;
	schoolId=s.schoolId;
}
int main()
{
	Student s("ZengTao","ÄÐ","123456","ECJTU","9999");
	s.Disp();
	return 0;
}