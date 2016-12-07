#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define VERTEX_COUNT_MAX 10
#define ARC_COUNT_MAX 4
#define MAX_FINAL_COUNT 5
typedef char VElemType;
typedef char AElemType;
//the Vertex's data structure
struct Vertex
{
	VElemType data;
	int Vid;
}vertex[VERTEX_COUNT_MAX];

//the vertex count
int vertex_count=0;

//the arc's data structure
struct Arc
{
	AElemType data;
	int Aid;
}_arc[ARC_COUNT_MAX];
//the arc count
int arc_count=0;

//the DFA's count
int DFA_count;

//the DFA string 
vector<string> DFAstring;

//the DFA's start char
char startChar;

//the final word about the DFA
char arrayFinal[MAX_FINAL_COUNT];

//the final count
int final_count;

//the array about DFA
char arrayDFA[VERTEX_COUNT_MAX+1][ARC_COUNT_MAX+1];
//find the char in the array
bool findChar(char array[],int length,char ch)
{
	for(int i=0;i<length;i++)
	{
		if(array[i]==ch)
		{
			return true;
		}
	}
	return false;
}
//delete the ' '
string Trim(string str)
{
	string newStr="";
	for(int i=0;i<str.size();i++)
	{
		if(str[i]!=' ')
		{
			newStr+=str[i];
		}
	}
	return newStr;
} 
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
//input the DFA's information
void Input()
{
	cout<<"Please input the count of DFA: ";
	cin>>DFA_count;
	DFAstring.clear();
	for(int i=0;i<DFA_count;i++)
	{
		string str;
		cin>>str;
		//delete the ' ' from start and end
		str=Trim(str);
		DFAstring.push_back(str);
	}
	getchar();//get the "\n"
	cin>>startChar;
	cin>>final_count;
	getchar();//get the "\n"
	for(int i=0;i<final_count;i++)
	{
		cin>>arrayFinal[i];
	}
}
void TestInput()
{
	Input();
	for(int i=0;i<DFA_count;i++)
	{
		cout<<DFAstring[i]<<endl;
	}
	cout<<startChar<<endl;
	cout<<final_count<<endl;
	for(int i=0;i<final_count;i++)
	{
		cout<<arrayFinal[i]<<" ";
	}
	cout<<endl;
}
//find ch in Vertex's data
int findVertex(char ch)
{
	for(int i=1;i<=vertex_count;i++)
	{
		if(vertex[i].data==ch)
		{
			return i;
		}
	}
	return -1;
}
//find ch in Arc's data
int findArc(char ch)
{
	for(int i=1;i<=arc_count;i++)
	{
		if(_arc[i].data==ch)
		{
			return i;
		}
	}
	return -1;
}
void InitVertexAndArc(string str)
{
	int col,row;
	++vertex_count;
//	vertex[vertex_count].data=str[0];
//	vertex[vertex_count].Vid=vertex_count;
	//design the arrayDFA
	arrayDFA[vertex_count][0]=str[0];
	
	row=vertex_count;
	for(int i=1;i<str.size();i++)
	{
		if(isLower(str[i]))//is 'a' 'b'..'z'
		{
			if(findArc(str[i])==-1)//not find and add in arc array
			{
				++arc_count;
				_arc[arc_count].data=str[i];
				_arc[arc_count].Aid=arc_count;
				//design the arrayDFA
				arrayDFA[0][arc_count]=str[i];
				col=arc_count;
			}
			else{
				col=findArc(str[i]);
			}
			arrayDFA[row][col]=str[i+1];
		}
	}
}
//init the arrayDFA by the DFA's information
void InitArrayDFA()
{
	//init the count
	vertex_count=0;arc_count=0;
	for(int i=0;i<DFAstring.size();i++)
	{
		InitVertexAndArc(DFAstring[i]);
	}
}
void DispArrayDFA()
{
	cout<<"the DFA's array:"<<endl;
	for(int i=0;i<=vertex_count;i++)
	{
		for(int j=0;j<=arc_count;j++)
		{
			if(i!=0||j!=0)
			{
				cout<<arrayDFA[i][j]<<" ";
			}
			else
			{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
void TestArrayDFA()
{
	Input();
	InitArrayDFA();
	DispArrayDFA();
}
//find the final word from the arrayDFA
int findFinal(char ch)
{
	for(int i=1;i<=arc_count;i++)
	{
		if(arrayDFA[0][i]==ch)
		{
			return i;
		}
	}
	return -1;//not find
}
//find the unfinal word from the arrayDFA
int findNotFinal(char ch)
{
	for(int i=1;i<=vertex_count;i++)
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
	char start=startChar;//init the start
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
	//find the last char in the final array
	if(findChar(arrayFinal,final_count,start))
		return "yes";
	return "no";
}
void TestDFA()
{
	Input();
	InitArrayDFA();
	DispArrayDFA();
	string str;
	cout<<"请输入要验证的串:";
	while(cin>>str)
	{
		cout<<isRightStr(str)<<endl;
		//system("cls");
		cout<<"请输入要验证的串:";
	}
}
int main()
{
	TestDFA();
	return 0;
}
/*
产生式条数n 
--产生式1
--产生式2
--...
--产生式n
开始符号start 
终结符个数m
终结符1 终结符2 ...终结符m 
4
S→aU|bV
U→bV|aQ
V→aU|bQ
Q→aQ|bQ
S
1
Q
*/ 