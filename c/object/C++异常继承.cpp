#include<iostream>
using namespace std;
class arithmetic:public exception
{
	public:
 		virtual const char* what()const throw()
 		{
		 	return "异常：算数异常。";
		 }
};
class badoperator:public arithmetic
{
	public:
		virtual const char *what()const throw()
		{
			return "异常：无效运算符。";
		}
};
class divbyzero:public arithmetic
{
	public:
		virtual const char* what()const throw()
		{
			return "异常：除零异常。"; 
		}
};
class divbyneg:public arithmetic
{
	public:
		virtual const char* what()const throw()
		{
			return "异常：除数无意义。"; 
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
				throw divbyzero();//抛出类 divbyzero匿名对象 
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
		cout<<"请输入第一个操作数："<<endl;
		double data1;
		cin>>data1;
		cout<<"请输入第二个操作数："<<endl;
		double data2;
		cin>>data2;
		cout<<"请输入运算符："<<endl;
		char oper;
		cin>>oper;
		cout<<"oper is :"<<oper<<endl;
		try
		{
			double result=operation(oper,data1,data2);
			cout<<"结果为："<<result<<endl; 
		}
		catch(exception &error)
		{
			cout<<error.what()<<endl; 
			exit(1);
		}	
	}
	return 0;
} 