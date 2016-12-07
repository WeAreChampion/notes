#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int f(string s)//对0,1串转化为十进制数值 
{
	int sum=0,i,a,k = 0;
	for(i=s.length() - 1; i >= 0; i--)//末尾开始 
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
			while((ch=getchar())!='\n')//判断是否为换行 
			{
				//字符转化为0,1串 
				if(ch==' ')//count the ' ' 
				{
					count++;
				}
				else if(count!=0)
				{
					if(count%2==1)// count is 奇数 
						s+='1';
					else		//count is 偶数 
						s+='0';
					count=0;	//行初始化count=0 
				}
			}
			char aaa=f(s);
			str+=aaa;
		}
		cout<<str<<endl;//以字符形式输出！ 
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
