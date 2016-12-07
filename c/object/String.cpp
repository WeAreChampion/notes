#include<iostream>
using namespace std;
class String
{
private:
	char *p;
public:
	String();
	String(char *str);
	~String();
	friend bool operator >(String s1,String s2);
	friend bool operator <(String s1,String s2);
	friend bool operator ==(String s1,String s2);
	void Display();
};
String::String()
{
	p=NULL;
}
String::String(char *str)
{
	p=str;
}
String::~String()
{
	//add information
}
bool operator >(String s1,String s2)
{
	if(strcmp(s1.p,s2.p)>0)
		return true;
	return false;
}
bool operator <(String s1,String s2)
{
	if(strcmp(s1.p,s2.p)<0)
		return true;
	return false;
}
bool operator ==(String s1,String s2)
{
	if(strcmp(s1.p,s2.p)==0)
		return true;
	return false;
}
void String::Display()
{
	cout<<p;
}
void Compare(String s1,String s2)
{
	if(operator>(s1,s2)==true)
	{
		s1.Display();
		cout<<">";
		s2.Display();
		cout<<endl;
	}
	else if(operator<(s1,s2)==true)
	{
		s1.Display();
		cout<<"<";
		s2.Display();
		cout<<endl;
	}
	else if(operator==(s1,s2)==true)
	{
		s1.Display();
		cout<<"=";
		s2.Display();
		cout<<endl;
	}
}
int main()
{
	String s1("Hello"),s2("Book"),s3("Computer"),s4("Hello");
	Compare(s1,s2);
	Compare(s2,s3);
	Compare(s1,s4);
	return 0;
} 