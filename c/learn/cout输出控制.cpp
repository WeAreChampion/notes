#include <iostream>
#include <iomanip> 
using namespace std ;
int main()
{
	double PI = 3.141592654;
	//���PI��Ĭ�����С�����5λ 
	cout<<PI<<endl;
	//������Чλ��������λ��Ч���� 
	cout<<setprecision(2)<<PI<<endl;
	//�������С���㾫�ȣ���ȷ��С�����2λ�� 
	cout<<fixed<<setprecision(2)<<PI<<endl;	
	//���ø���������Ч����Ϊnλ����ЧλΪ10λ�����Ϊ20λ����*���룬Ĭ��*������ 
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<PI<<endl;
	//�����������ߣ�*������ұ� 
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<left<<PI<<endl;
	//���������ʽΪ��ѧ��������Ĭ����e�������ЧλΪ10λ 
	cout<<scientific<<setprecision(10)<<PI<<endl;
	//���������ʽΪ��ѧ����������E�������ЧλΪ10λ 
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