#include <iostream>
#include <iomanip> 
using namespace std ;
int main()
{
	double PI = 3.141592654;
	//输出PI，默认输出小数点后5位 
	cout<<PI<<endl;
	//设置有效位，保留两位有效数字 
	cout<<setprecision(2)<<PI<<endl;
	//设置输出小数点精度（精确到小数点后2位） 
	cout<<fixed<<setprecision(2)<<PI<<endl;	
	//设置浮点数的有效数字为n位，有效位为10位，宽度为20位，用*补齐，默认*向左补齐 
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<PI<<endl;
	//数字填充在左边，*填充在右边 
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<left<<PI<<endl;
	//设置输出格式为科学计数法，默认以e输出，有效位为10位 
	cout<<scientific<<setprecision(10)<<PI<<endl;
	//设置输出格式为科学计数法，以E输出，有效位为10位 
	cout<<scientific<<uppercase<<setprecision(10)<<PI<<endl;	
    return 0 ;
}
/*
Output:
3.14159
3.1
3.14
********3.1415926540
3.1415926540********
3.1415926540e+00
3.1415926540E+00
*/