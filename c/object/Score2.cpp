#include<iostream>
using namespace std;
#include<string>
#include<fstream>
int aaa=0,bbb=0,amount[11]= {0};
class Student
{
public:
	Student() {} //系统构造函数
	Student(string na,int num);//带有参数的构造函数
	friend void setInform(Student&s);
	string getName() {
		return name;
	}
	int getNumber() {
		return number;
	}
	friend void swapInform(Student&s1,Student&s2);
	void display();
	friend istream &operator>>(istream &input,Student&s) { //重载流提取运算符
		input>>s.name>>" ">>s.number;
		return input;
	}
	friend ostream &operator<<(ostream &output,Student&s) { //重载流插入运算符
		output<<s.name<<"\t"<<s.number<<"\t";
		return output;
	}
private:
	string name;
	int number;
};
Student::Student(string na,int num)
{
	name=na;
	number=num;
}
void setInform(Student&s)//类外定义输入信息的函数
{
	cout<<"\t"<<"请输入学生名字:";
	cin>>s.name;
	cout<<"\t"<<"请输入学生学号:";
	cin>>s.number;
}
void swapInform(Student&s1,Student&s2)//类外定义交换信息的函数
{
	Student temp;
	temp=s1;
	s1=s2;
	s2=temp;
}
void Student::display()//输出函数的类外定义
{
	cout<<name<<"\t"<<"\t"<<number<<"\t";
}
double get_highest_score(double a[100][12],int n,int m)//求最高分数学生信息
{
	double max=a[0][0];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(max<a[i][j]) {
				max=a[i][j];
				aaa=i;//保存其在学生信息中的下标
				bbb=j;//保存其在科目成绩中的下标
			}
	return max;
}
//统计60分以下学生人数
int get_Lower60_score(double a[100][12],int n,int m)
{
	int count=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j]<60)
				count++;
	return count;
}
//统计分数大于或等于90分人数
int get_higher90_score(double a[100][12],int n,int m)
{
	int count=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j]>=90)
				count++;
	return count;
}
//求其平均成绩
double get_average(double a[100][12],int n,int m)
{
	double sum=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			sum+=a[i][j];
	return sum/n;
}
//定义查找信息的函数
void findInform(Student &s,double a[100][12],int n,int m)
{
	s.display();
	for(int i=0; i<n; i++)
		cout<<a[m][i]<<"\t";
	cout<<endl;
}
//求不同分数段的人数
void get_differentScore_amount(double a[100][12],int n,int m)
{
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++) {
			if(a[i][j]>=0&&a[i][j]<=9)
				amount[0]++;
			if(a[i][j]>=10&&a[i][j]<=19)
				amount[1]++;
			if(a[i][j]>=20&&a[i][j]<=29)
				amount[2]++;
			if(a[i][j]>=30&&a[i][j]<=39)
				amount[3]++;
			if(a[i][j]>=40&&a[i][j]<=49)
				amount[4]++;
			if(a[i][j]>=50&&a[i][j]<=59)
				amount[5]++;
			if(a[i][j]>=60&&a[i][j]<=69)
				amount[6]++;
			if(a[i][j]>=70&&a[i][j]<=79)
				amount[7]++;
			if(a[i][j]>=80&&a[i][j]<=89)
				amount[8]++;
			if(a[i][j]>=90&&a[i][j]<=99)
				amount[9]++;
			if(a[i][j]==100)
				amount[10]++;
		}
}
int main()
{
	int n,nn,mm,deleteNumber;
	string b[12]= {"语文","数学","C++程序设计","计算机导论","离散数学","马克思","数学建模","网页设计","省情教育","线性代数","体育","数字逻辑"};
	//定义文件流对象，打开磁盘文件"f1.dat"
	ofstream outfile("f1.dat",ios::out);
	if(!outfile) { //判断文件流是否打开成功
		cerr<<"open error!"<<endl;
		exit(1);
	}
	double score[100][12],score2[100][12];
	Student stu[100],stu2[100];
	int student_amount,subject_amount,i,j;
	cout<<"\t"<<"请输入学生数:";
	cin>>student_amount;
	cout<<"\t"<<"请输入成绩考试科目数:";
	cin>>subject_amount;//输入学生数和成绩科目数
	outfile<<student_amount<<" "<<subject_amount<<endl;
	//cout<<"\t"<<"请输入学生的信息及考试成绩"<<endl;
	for(i=0; i<student_amount; i++) { //输入学生的信息及考试成绩
		setInform(stu[i]);
		for(j=0; j<subject_amount; j++) {
			cout<<"\t"<<b[j]<<"成绩:";
			cin>>score[i][j];
		}
	}
	for(i=0; i<student_amount; i++)
		stu2[i]=stu[i];
	for(i=0; i<student_amount; i++)
		for(j=0; j<subject_amount; j++)
			score2[i][j]=score[i][j];
	cout<<endl<<"\t"<<"当前的数据:"<<endl;//输出当前的信息
	for(i=0; i<student_amount; i++) {
		stu[i].display();
		outfile<<stu[i].getName()<<" "<<stu[i].getNumber()<<" ";
		for(j=0; j<subject_amount; j++) {
			cout<<score[i][j]<<"\t";
			outfile<<score[i][j]<<" ";
		}
		cout<<endl;
		outfile<<endl;
	}
	double student_average[50],subject_average[10];
	//统计学生平均成绩，并保存到数组中
	for(i=0; i<student_amount; i++) {
		student_average[i]=0;
		for(j=0; j<subject_amount; j++)
			student_average[i]+=score[i][j];
		student_average[i]/=subject_amount;
	}
	cout<<"\t"<<"同学的平均成绩:"<<endl;//输出学生的平均成绩及个人信息
	for(i=0; i<student_amount; i++) {
		stu[i].display();
		outfile<<stu[i].getName()<<" "<<stu[i].getNumber()<<" ";
		cout<<student_average[i]<<endl;
		outfile<<student_average[i]<<endl;
	}
	cout<<endl;
	outfile<<endl;
	//统计不同学科的平均成绩
	for(j=0; j<subject_amount; j++) {
		subject_average[j]=0;
		for(i=0; i<student_amount; i++)
			subject_average[j]+=score[i][j];
		subject_average[j]/=student_amount;
	}
	cout<<"\t"<<"每科的平均成绩是:"<<endl;//输出每一科的平均成绩
	for(j=0; j<subject_amount; j++) {
		cout<<subject_average[j]<<"\t";
		outfile<<subject_average[j]<<" ";
	}
	cout<<endl;
	outfile<<endl;
	cout<<endl<<"\t"<<"成绩排序后的数据:"<<endl;
	//利用选择排序法来对平均成绩排序，并置换其所有的信息
	for(i=0; i<student_amount-1; i++) {
		int max=i;
		for(j=i+1; j<student_amount; j++)
			if(student_average[max]<student_average[j])
				max=j;
		double temp=student_average[i];
		student_average[i]=student_average[max];
		student_average[max]=temp;
		swapInform(stu[i],stu[max]);
		for(int k=0; k<subject_amount; k++) {
			double temp=score[i][k];
			score[i][k]=score[max][k];
			score[max][k]=temp;
		}
	}
	for(i=0; i<student_amount; i++) { //输出排序后的学生信息及成绩
		stu[i].display();
		for(j=0; j<subject_amount; j++) {
			cout<<score[i][j]<<"\t";
			outfile<<score[i][j]<<" ";
		}
		cout<<student_average[i]<<endl;
		outfile<<student_average[i]<<endl;
	}
	//测试，对不同的要求，利用函数进行测试
	cout<<"\t"<<"分数低于60分的人数:"<<get_Lower60_score(score,student_amount,subject_amount)<<endl;
	cout<<"\t"<<"分数大于或等于90分的人数:"<<get_higher90_score(score,student_amount,subject_amount)<<endl;
	cout<<"\t"<<"分数最高者的信息:";
	stu[aaa].display();
	cout<<get_highest_score(score,student_amount,subject_amount)<<endl;
	cout<<"\t"<<"总的平均成绩是:"<<get_average(score,student_amount,subject_amount)<<endl;
	outfile.close();
	while(cout<<"请输入可进行选择的数字，1代表查找，2代表插入，3代表删除:"&&cin>>n) {
		if(n==1) {
			//输入查找学生的信息下标
			int findNumber;
			cout<<endl<<"输入要查找的学生信息的下标:"<<endl;
			cin>>findNumber;
			findInform(stu2[findNumber],score2,subject_amount,findNumber);
			cout<<endl;
		}
		if(n==2) {
			//插入几个学生的信息
			//int nn,mm;
			cout<<"要插入学生信息的人数和科目数:";
			cin>>nn>>mm;
			if(mm==subject_amount) {
				for(i=0; i<nn; i++) {
					setInform(stu2[student_amount+i]);
					for(j=0; j<subject_amount; j++)
						cin>>score2[student_amount+i][j];
				}
				//输出所有人的信息
				for(i=0; i<student_amount+nn; i++) {
					stu2[i].display();
					for(j=0; j<subject_amount; j++) {
						cout<<score2[i][j]<<"\t";
					}
					cout<<endl;
				}
			}
			cout<<"各分数段及人数:"<<endl;
			get_differentScore_amount(score2,student_amount+nn,subject_amount);
			int sss=0;
			for(i=0; i<10; i++) {
				cout<<sss<<"~"<<sss+9<<":"<<"\t";
				cout<<amount[i]<<endl;
				sss+=10;
			}
			cout<<100<<":"<<"\t"<<amount[i]<<endl;
		}
		if(n==3) {
			//输入要删除学生信息的下标
			//int deleteNumber;
			cout<<"输入要删除学生信息的下标:";
			cin>>deleteNumber;
			for(i=0; i<student_amount+nn; i++) {
				if(i==deleteNumber) continue;
				stu2[i].display();
				for(j=0; j<subject_amount; j++) {
					cout<<score2[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
