#include<iostream>
using namespace std;
class arithmetic:public exception
{
	public:
 		virtual const char* what()const throw()
 		{
		 	return "�쳣�������쳣��";
		 }
};
class badoperator:public arithmetic
{
	public:
		virtual const char *what()const throw()
		{
			return "�쳣����Ч�������";
		}
};
class divbyzero:public arithmetic
{
	public:
		virtual const char* what()const throw()
		{
			return "�쳣�������쳣��"; 
		}
};
class divbyneg:public arithmetic
{
	public:
		virtual const char* what()const throw()
		{
			return "�쳣�����������塣"; 
		}
};
double operation(char oper,double data1,double data2)
{
	double result;
	switch(oper)
	{
		case '+':
			result=data1+data2;
			break;
		case '-':
			result=data1-data2;
			break;
		case '*':
			result=data1*data2;
			break;
		case '/':
			if(data2==0)
			{
				throw divbyzero();//�׳��� divbyzero�������� 
			} 
			if(data1<0)
			{
				throw divbyneg();
			}
			result=data1/data2;
			break;
		default:
			throw badoperator();
			break;
	}
	return result;
}
int main()
{
	while(true)
	{
		cout<<"�������һ����������"<<endl;
		double data1;
		cin>>data1;
		cout<<"������ڶ�����������"<<endl;
		double data2;
		cin>>data2;
		cout<<"�������������"<<endl;
		char oper;
		cin>>oper;
		cout<<"oper is :"<<oper<<endl;
		try
		{
			double result=operation(oper,data1,data2);
			cout<<"���Ϊ��"<<result<<endl; 
		}
		catch(exception &error)
		{
			cout<<error.what()<<endl; 
			exit(1);
		}	
	}
	return 0;
} 