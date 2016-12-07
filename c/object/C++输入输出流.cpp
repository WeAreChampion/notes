#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream infile("C:\\Users\\Administrator\\Desktop\\2.txt",ios::in);
	ofstream outfile("C:\\Users\\Administrator\\Desktop\\1.txt",ios::out);
	if(!infile)
	{
		cerr<<"open error!"<<endl;
		exit(0);
	}
	if(!outfile)
	{
		cerr<<"open error!"<<endl;
		exit(0);
	}
	char a;
	//method 1 true
	/* 
	while(!infile.eof())//可以读入换行和空格 is true
	{
		a=infile.get();
		outfile<<a;
		cout<<a;
	}
	*/
	//method 2 true
	while(infile.get(a))
	{
		cout<<a;//cout.put(a);//true
		outfile<<a;
	}
	infile.close();
	outfile.close();
	return 0;
}