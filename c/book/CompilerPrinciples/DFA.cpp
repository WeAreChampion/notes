#include<iostream>
#include<string>
using namespace std;
#define VERTEX_COUNT_MAX 10
const int VERTEX_COUNT = 4; 
#define ARC_COUNT_MAX 4
const int ARC_COUNT = 2;
#define MAX_FINAL_COUNT 5
typedef char VElemType;
typedef char AElemType;
//the Vertex's data structure
struct Vertex
{
	VElemType data;
	int Vid;
}vertex[VERTEX_COUNT_MAX];
//the arc's data structure
typedef struct Arc
{
	AElemType data;
	int Aid;
}arc[ARC_COUNT_MAX];
//the final word about the DFA
char arrayFinal[MAX_FINAL_COUNT];
//the array about DFA
char arrayDFA[VERTEX_COUNT + 1][ARC_COUNT + 1]={
	' ','a','b',
	'S','U','V',
	'U','Q','V',
	'V','U','Q',
	'Q','Q','Q'
};
int findFinal(char ch)
{
	for(int i=1;i<ARC_COUNT+1;i++)
	{
		if(arrayDFA[0][i]==ch)
		{
			return i;
		}
	}
	return -1;//not find
}
int findNotFinal(char ch)
{
	for(int i=1;i<VERTEX_COUNT+1;i++)
	{
		if(arrayDFA[i][0]==ch)
		{
			return i;
		}
	}
	return -1;//not find
}
//recognize the right str
string isRightStr(string str)
{
	char start='S';//init the start
	char end='Q';
	for(int i=0;i<str.size();i++)
	{
		char ch=str[i];
		int row=findNotFinal(start);
		int col=findFinal(ch);
		if(row==-1||col==-1)
		{
			return "no";
		}
		start=arrayDFA[row][col];//change the start
	}
	if(start==end)
		return "yes";
	return "no";
}
//delete the ' ' from the string where start and ending
string Trim(string str)
{
	string newStr="";
	int start;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]!=' ')
		{
			start=i;
			break;
		}
	}
	int end;
	for(int i=str.size()-1;i>=0;i--)
	{
		if(str[i]!=' ')
		{
			end=i;
			break;
		}
	}
	for(int i=start;i<=end;i++)
	{
		newStr+=str[i];
	}
	return newStr;
} 
void TestTrim()
{
	string s="  aa av b  ";
	string news=Trim(s);
	cout<<news.size()<<endl<<news<<endl;
}
string string1="S→aU|bV";
//the char is lower like 'a','b'...'z'
bool isLower(char ch)
{
	if(ch>='a'&&ch<='z')
	{
		return true;
	}
	return false;
}
//the char is Uper like 'A','B'...'Z'
bool isUper(char ch)
{
	if(ch>='A'&&ch<='Z')
	{
		return true;
	}
	return false;
}
void TestChar()
{
	char ch;
	cout<<"Please type a word: ";
	while(cin>>ch)
	{
		if(isUper(ch)) 
			cout<<ch<<" is upper!"<<endl;
		else if(isLower(ch))
			cout<<ch<<" is lower!"<<endl;
		else
			cout<<ch<<" is not word!"<<endl;
		getchar();
		cout<<"Please type a word: ";
	} 
}
void divideString(string str)
{
	//delete the ' ' from the start and ending
	string newStr=Trim(str);
	int vertex_count=0;
	int arc_count=0;
}
void Test()
{
	string str;
	cout<<"请输入要验证的串:";
	while(cin>>str)
	{
		cout<<isRightStr(str)<<endl;
		system("pause");
		system("cls");
		cout<<"请输入要验证的串:";
	}
}
int main()
{
	Test();
	return 0;
}
/*
4
S→aU|bV
U→bV|aQ
V→aU|bQ
Q→aQ|bQ
1
Q
*/ 