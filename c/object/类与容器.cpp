#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Student 
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
void Student::setUsername(string username)
{
	this->username=username;
}
string Student::getUsername()
{
	return username;
}
void Student::setPassword(string password)
{
	this->password=password;
}
string Student::getPassword()
{
	return password;
}
int main()
{
	string sa,sb;
	vector<Student> v;
	v.clear();
	int n;
	cin>>n;
	while(n--)
	{
		cin>>sa>>sb;
		Student s;
		s.setUsername(sa);
		s.setPassword(sb);
		v.push_back(s);
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].getUsername()<<endl;
		cout<<v[i].getPassword()<<endl;
	}
	return 0;
}