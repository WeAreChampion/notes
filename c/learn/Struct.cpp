#include<iostream>
using namespace std;
struct Student
{
	string name;
	int studentId;
}student;
void DispStudent(Student student)
{
	cout<<"Name is :"<<student.name<<endl;
	cout<<"StudentId is :"<<student.studentId<<endl;
}
void Test()
{
	student.studentId = 9;
	student.name = "ÕÅÈı";
	DispStudent(student);
}
int main()
{
	Test();
	return 0;
}