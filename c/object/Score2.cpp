#include<iostream>
using namespace std;
#include<string>
#include<fstream>
int aaa=0,bbb=0,amount[11]= {0};
class Student
{
public:
	Student() {} //ϵͳ���캯��
	Student(string na,int num);//���в����Ĺ��캯��
	friend void setInform(Student&s);
	string getName() {
		return name;
	}
	int getNumber() {
		return number;
	}
	friend void swapInform(Student&s1,Student&s2);
	void display();
	friend istream &operator>>(istream &input,Student&s) { //��������ȡ�����
		input>>s.name>>" ">>s.number;
		return input;
	}
	friend ostream &operator<<(ostream &output,Student&s) { //���������������
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
void setInform(Student&s)//���ⶨ��������Ϣ�ĺ���
{
	cout<<"\t"<<"������ѧ������:";
	cin>>s.name;
	cout<<"\t"<<"������ѧ��ѧ��:";
	cin>>s.number;
}
void swapInform(Student&s1,Student&s2)//���ⶨ�彻����Ϣ�ĺ���
{
	Student temp;
	temp=s1;
	s1=s2;
	s2=temp;
}
void Student::display()//������������ⶨ��
{
	cout<<name<<"\t"<<"\t"<<number<<"\t";
}
double get_highest_score(double a[100][12],int n,int m)//����߷���ѧ����Ϣ
{
	double max=a[0][0];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(max<a[i][j]) {
				max=a[i][j];
				aaa=i;//��������ѧ����Ϣ�е��±�
				bbb=j;//�������ڿ�Ŀ�ɼ��е��±�
			}
	return max;
}
//ͳ��60������ѧ������
int get_Lower60_score(double a[100][12],int n,int m)
{
	int count=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j]<60)
				count++;
	return count;
}
//ͳ�Ʒ������ڻ����90������
int get_higher90_score(double a[100][12],int n,int m)
{
	int count=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j]>=90)
				count++;
	return count;
}
//����ƽ���ɼ�
double get_average(double a[100][12],int n,int m)
{
	double sum=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			sum+=a[i][j];
	return sum/n;
}
//���������Ϣ�ĺ���
void findInform(Student &s,double a[100][12],int n,int m)
{
	s.display();
	for(int i=0; i<n; i++)
		cout<<a[m][i]<<"\t";
	cout<<endl;
}
//��ͬ�����ε�����
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
	string b[12]= {"����","��ѧ","C++�������","���������","��ɢ��ѧ","���˼","��ѧ��ģ","��ҳ���","ʡ�����","���Դ���","����","�����߼�"};
	//�����ļ������󣬴򿪴����ļ�"f1.dat"
	ofstream outfile("f1.dat",ios::out);
	if(!outfile) { //�ж��ļ����Ƿ�򿪳ɹ�
		cerr<<"open error!"<<endl;
		exit(1);
	}
	double score[100][12],score2[100][12];
	Student stu[100],stu2[100];
	int student_amount,subject_amount,i,j;
	cout<<"\t"<<"������ѧ����:";
	cin>>student_amount;
	cout<<"\t"<<"������ɼ����Կ�Ŀ��:";
	cin>>subject_amount;//����ѧ�����ͳɼ���Ŀ��
	outfile<<student_amount<<" "<<subject_amount<<endl;
	//cout<<"\t"<<"������ѧ������Ϣ�����Գɼ�"<<endl;
	for(i=0; i<student_amount; i++) { //����ѧ������Ϣ�����Գɼ�
		setInform(stu[i]);
		for(j=0; j<subject_amount; j++) {
			cout<<"\t"<<b[j]<<"�ɼ�:";
			cin>>score[i][j];
		}
	}
	for(i=0; i<student_amount; i++)
		stu2[i]=stu[i];
	for(i=0; i<student_amount; i++)
		for(j=0; j<subject_amount; j++)
			score2[i][j]=score[i][j];
	cout<<endl<<"\t"<<"��ǰ������:"<<endl;//�����ǰ����Ϣ
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
	//ͳ��ѧ��ƽ���ɼ��������浽������
	for(i=0; i<student_amount; i++) {
		student_average[i]=0;
		for(j=0; j<subject_amount; j++)
			student_average[i]+=score[i][j];
		student_average[i]/=subject_amount;
	}
	cout<<"\t"<<"ͬѧ��ƽ���ɼ�:"<<endl;//���ѧ����ƽ���ɼ���������Ϣ
	for(i=0; i<student_amount; i++) {
		stu[i].display();
		outfile<<stu[i].getName()<<" "<<stu[i].getNumber()<<" ";
		cout<<student_average[i]<<endl;
		outfile<<student_average[i]<<endl;
	}
	cout<<endl;
	outfile<<endl;
	//ͳ�Ʋ�ͬѧ�Ƶ�ƽ���ɼ�
	for(j=0; j<subject_amount; j++) {
		subject_average[j]=0;
		for(i=0; i<student_amount; i++)
			subject_average[j]+=score[i][j];
		subject_average[j]/=student_amount;
	}
	cout<<"\t"<<"ÿ�Ƶ�ƽ���ɼ���:"<<endl;//���ÿһ�Ƶ�ƽ���ɼ�
	for(j=0; j<subject_amount; j++) {
		cout<<subject_average[j]<<"\t";
		outfile<<subject_average[j]<<" ";
	}
	cout<<endl;
	outfile<<endl;
	cout<<endl<<"\t"<<"�ɼ�����������:"<<endl;
	//����ѡ����������ƽ���ɼ����򣬲��û������е���Ϣ
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
	for(i=0; i<student_amount; i++) { //���������ѧ����Ϣ���ɼ�
		stu[i].display();
		for(j=0; j<subject_amount; j++) {
			cout<<score[i][j]<<"\t";
			outfile<<score[i][j]<<" ";
		}
		cout<<student_average[i]<<endl;
		outfile<<student_average[i]<<endl;
	}
	//���ԣ��Բ�ͬ��Ҫ�����ú������в���
	cout<<"\t"<<"��������60�ֵ�����:"<<get_Lower60_score(score,student_amount,subject_amount)<<endl;
	cout<<"\t"<<"�������ڻ����90�ֵ�����:"<<get_higher90_score(score,student_amount,subject_amount)<<endl;
	cout<<"\t"<<"��������ߵ���Ϣ:";
	stu[aaa].display();
	cout<<get_highest_score(score,student_amount,subject_amount)<<endl;
	cout<<"\t"<<"�ܵ�ƽ���ɼ���:"<<get_average(score,student_amount,subject_amount)<<endl;
	outfile.close();
	while(cout<<"������ɽ���ѡ������֣�1������ң�2������룬3����ɾ��:"&&cin>>n) {
		if(n==1) {
			//�������ѧ������Ϣ�±�
			int findNumber;
			cout<<endl<<"����Ҫ���ҵ�ѧ����Ϣ���±�:"<<endl;
			cin>>findNumber;
			findInform(stu2[findNumber],score2,subject_amount,findNumber);
			cout<<endl;
		}
		if(n==2) {
			//���뼸��ѧ������Ϣ
			//int nn,mm;
			cout<<"Ҫ����ѧ����Ϣ�������Ϳ�Ŀ��:";
			cin>>nn>>mm;
			if(mm==subject_amount) {
				for(i=0; i<nn; i++) {
					setInform(stu2[student_amount+i]);
					for(j=0; j<subject_amount; j++)
						cin>>score2[student_amount+i][j];
				}
				//��������˵���Ϣ
				for(i=0; i<student_amount+nn; i++) {
					stu2[i].display();
					for(j=0; j<subject_amount; j++) {
						cout<<score2[i][j]<<"\t";
					}
					cout<<endl;
				}
			}
			cout<<"�������μ�����:"<<endl;
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
			//����Ҫɾ��ѧ����Ϣ���±�
			//int deleteNumber;
			cout<<"����Ҫɾ��ѧ����Ϣ���±�:";
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
