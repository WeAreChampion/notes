#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int f(string s)//��0,1��ת��Ϊʮ������ֵ 
{
	int sum=0,i,a,k = 0;
	for(i=s.length() - 1; i >= 0; i--)//ĩβ��ʼ 
	{
		a = s[i]-'0';
		sum +=a * ((int)pow(2,(double)k));
		k++;
	}
	return sum;
}
int main()
{
	int n;
	while(cin>>n)
	{
		string str="";
		while(n--)
		{
			char ch;
			getchar();
			string s="";
			int flag=1,count=0;
			while((ch=getchar())!='\n')//�ж��Ƿ�Ϊ���� 
			{
				//�ַ�ת��Ϊ0,1�� 
				if(ch==' ')//count the ' ' 
				{
					count++;
				}
				else if(count!=0)
				{
					if(count%2==1)// count is ���� 
						s+='1';
					else		//count is ż�� 
						s+='0';
					count=0;	//�г�ʼ��count=0 
				}
			}
			char aaa=f(s);
			str+=aaa;
		}
		cout<<str<<endl;//���ַ���ʽ����� 
	}
	return 0;
} 
/*
9
* *  *  *  * *  * *
* *  *  *  *  * * *
* *  *  * *  * *  *
* *  * *  * *  *  *
* *  *   *  * *  * *
*   *  *   * * * * *
* *  *  *  *  *  * *
* *  *  *  *  * * *
*   *  *  * * *  * *
*/
