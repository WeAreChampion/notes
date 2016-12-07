#include<iostream>
using namespace std;
int main()
{
	cout<<"请输入被除数：";
	double dividend,divisor;
	while(cin>>dividend)
	{
		cout<<"请输入除数：";
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
			cout<<"输入的除数不能为零！"<<endl;
			exit(0);//结束循环 
		}
		cout<<"请输入被除数：";
	}
	return 0;
}