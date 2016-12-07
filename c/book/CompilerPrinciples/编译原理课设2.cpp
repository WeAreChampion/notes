#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define STACK_MAX_SIZE 20
//the array of X[6][7]
string LLTable[]={
	" ","i","+","*","(",")","#",
	"E","TE'"," "," ","TE'"," "," ",
	"E'"," ","+TE'"," "," ","ε","ε",
	"T","FT'"," "," ","FT'"," "," ",
	"T'"," ","ε","*FT'"," ","ε","ε",
	"F","i"," "," ","(E)"," "," "
};
//Disp the LLTable
void DispLLTable()
{
	cout<<"The LLTable is :"<<endl;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<LLTable[i*7+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
} 
//find the strt from LLTable
int findLLTable(string str)
{
	for(int i=1;i<42;i++)
	{
		if(str==LLTable[i])
		{
			return i;//return the position
		}
	}
	return -1;//not find
}
char stack[STACK_MAX_SIZE];
int top=0;//the stack top point
string start="E";
//reverse the str and push into the stack
void PushStr(string str)
{
	if(str.size()==1)
	{
		stack[top++]=str[0];
		return ;
	}
	for(int i=str.size()-1;i>=0;)
	{
		if(str[i]=='\'')//is the char '
		{
			stack[top++]=str[i-1];
			stack[top++]=str[i];
			i-=2;
		}
		else
		{
			stack[top++]=str[i];
			i--;
		}
	}
}
//Pop the str from the stack
string PopStr()
{
	string str="";
	if(stack[top-1]=='\'')//is '
	{
		str+=stack[top-2];
		str+=stack[top-1];
		top-=2;
	}
	else
	{
		str+=stack[--top];
	}
	return str;
}
//get the top from the satck
string getTop()
{
	string str="";
	if(stack[top-1]=='\'')
	{
		str+=stack[top-2];
		str+=stack[top-1];
	}
	else
	{
		str+=stack[top-1];
	}
	return str;
}
//output the stack's information
void DispStack()
{
	cout<<setiosflags(ios::left);
	for(int i=0;i<top;i++)
	{
		cout<<stack[i];
	}
	cout<<"\t\t";
}
//convert stack to string
string stackToString()
{
	string str="";
	for(int i=0;i<top;i++)
	{
		str+=stack[i];
	}
	str+="\t\t";
	return str;
}
//Disp str from startPos
void DispStr(string str,int startPos)
{
	cout<<setiosflags(ios::right);
	for(int i=startPos;i<str.size();i++)
	{
		cout<<str[i];
	}
	cout<<"\t\t";
}

string StrToString(string str,int startPos)
{
	string newStr="";
	for(int i=startPos;i<str.size();i++)
	{
		newStr+=str[i];
	}
	newStr+="\t\t";
	return newStr;
}
bool IsRightStr(string str,string &dispString)
{
	string startString=start;
	PushStr("#");
	PushStr(startString);
	for(int i=0;i<str.size();)
	{
		string s=stackToString();
		dispString=dispString+s;
		dispString+=StrToString(str,i);
		string topString=PopStr();//the stack Pop
		if(str[i]==topString[0])
		{
			if(str[i]=='#')
			{
				dispString+="acc";
				dispString+="\n";
			}
			else
			{
				dispString+=str[i];
				dispString+="匹配";
				dispString+="\n";	
			}
			i++;
			continue;
		}
		int pos=findLLTable(topString);
		if(pos==-1)//not find and return false;
			return false;
		int row=pos/7;//get the row
		string newStr="";
		newStr+=str[i];
		pos=findLLTable(newStr);//find the newStr
		if(pos==-1)//not find and return false;
			return false;
		int col=pos%7;//get the row
		
		startString=LLTable[row*7+col];
		if(startString==" ")//that means can't recognize
			return false;
		if(startString!="ε")
			PushStr(startString);	
		dispString+=topString+"->"+startString+"\n";
	}
	return true;
}
void Input()
{
	string str;
	cout<<"Please input the str: ";
	while(cin>>str)
	{
		string dispString="";
		top=0;
		if(IsRightStr(str,dispString))//default the return type
		{
			cout<<dispString;
		}
		else
		{
			cout<<"不能识别！"<<endl;
		}
		cout<<"Please input the str: ";
	}
}
void TestInput()
{
	Input();
}
int main()
{
	TestInput();
	return 0;
}
/*
Input:
i+i*i#

*/