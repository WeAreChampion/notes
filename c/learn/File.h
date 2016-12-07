#include<iostream>
#include<string>
using namespace std;
typedef struct File
{
	string file_name;	//the file's name
	int file_size;		//the file's size
	int file_count; 	//the file contain child_file amount
	int file_type;		//0 is read only;1 is write;2 is read and write;
	string file_pos;	//the file's position
	string file_remark;	//the file's remark
	string file_create_time;//the file's create time
	string file_change_time;//the file's change time
	string file_visit_time;//the file's visit time
}File; 
/*init the file*/
void init_file(File file)
{
	file.file_name="";
	file.file_size=0;
	file.file_count=0;
	file.file_type=0;
	file.file_pos="";
	file.file_remark="";
	file.file_create_time="";
	file.file_change_time="";
	file.file_visit_time="";
}
/*set the file name*/
void set_file_name(File file,string name)
{
	file.file_name=name;
}
/*get the file name*/
string get_file_name(File file)
{
	return file.file_name;
}
/*set the file size*/
void set_file_size(File file,int size)
{
	file.file_size=size;
}
/*get the file size*/
int get_file_size(File file)
{
	return file.file_size;
}
/*get file count*/
int get_file_count(File file)
{
	return file.file_count;
}
/*set file count*/
void set_file_count(File file,int count)
{
	file.file_size=count;
}
/*get file type*/
int get_file_type(File file)
{
	return file.file_type;
}
/*set file type*/
void set_file_type(File file,int type)
{
	file.file_type=type;
}
/*disp file type*/
void disp_file_type(File file)
{
	cout<<"the file is";
	switch(file.file_type)
	{
		case '0':cout<<" read only!"<<endl;break;
		case '1':cout<<" write!"<<endl;break;
		case '2':cout<<" read and write!"<<endl;break;
	}
}