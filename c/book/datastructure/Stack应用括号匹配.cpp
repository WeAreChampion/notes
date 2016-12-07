#include<iostream>
#include<string>
using namespace std;
# define MaxSize 100
struct
{
	char data;
}stack[MaxSize];
bool Judge(string s)
{
	char c;
	int top=-1;
	for(int i=0;i<s.length ();i++)
	{
		switch(s[i])
		{
		case '{':
		case '[':
		case '(': ; stack[++top].data=s[i] ; break;
		case '}': c = stack[top--].data ; if(c != '{')  return false; break;
		case ']': c = stack[top--].data ; if(c != '[') 	return false; break;
		case ')': c = stack[top--].data ; if(c != '(')  return false; break;
		}
	}
	if(top!=-1)
		return false;
	return true;
}
int main()
{
	string s;
	cout<<"ÇëÊäÈëÒªÅÐ¶ÏÊÇ·ñÆ¥ÅäµÄÀ¨ºÅ´®:"<<endl;
	while(cin>>s)
	{
		cout<<"À¨ºÅÊÇ·ñÆ¥Åä:     ";
		cout<<(Judge(s)?"YES\n":"NO\n");
		cout<<"ÇëÊäÈëÒªÅÐ¶ÏÊÇ·ñÆ¥ÅäµÄÀ¨ºÅ´®:"<<endl;
	}
	return 0;
}
/*
{[(({[]}))]}
{[][][])
()[]{}[]()
90()()90[][]))((
*/