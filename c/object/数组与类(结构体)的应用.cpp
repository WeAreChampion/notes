#include<iostream>
using namespace std;
class Student
{
public:
	char ch;
	int i;
};
int main()
{	char a[3][2]={
		{'a',11},
		{'b',21},
		{'c',31} };
	Student stu[3];
	for(int i=0;i<3;i++)
	{
		stu[i].ch=a[i][0];
		stu[i].i=a[i][1];
	}
	int sum=0;
	for(int i=0;i<3;i++)
	{
		cout<<stu[i].ch<<"\t"<<stu[i].i<<endl;
		sum+=stu[i].i;
	}
	cout<<"sum="<<sum<<endl;
	return 0;
}