#include<iostream>
using namespace std;
int main()
{
	cout<<"�����뱻������";
	double dividend,divisor;
	while(cin>>dividend)
	{
		cout<<"�����������";
		cin>>divisor;
		try
		{
			if(divisor==0.00)
			{
				throw divisor;
			}
			double quotient=dividend/divisor;
			cout<<"the result is: "<<quotient<<endl;
		}
		catch(double &filter)
		{
			cout<<"����ĳ�������Ϊ�㣡"<<endl;
			exit(0);//����ѭ�� 
		}
		cout<<"�����뱻������";
	}
	return 0;
}