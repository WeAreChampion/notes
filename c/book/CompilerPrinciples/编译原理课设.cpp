#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//the Grammar content
string StartChar;
struct Grammar
{
	string left;
	string right;
}grammar;
vector<Grammar> VGrammar;//save the 文法产生式
struct Union_FIRST
{
	string left;
	vector<char>FIRST;		//save the FIRST
}union_first; 
struct Union_FOLLOW
{
	string left;
	vector<char>FOLLOW;		//save the FOLLOW
}union_follow; 
vector<Union_FIRST> VUnion_FIRST;
vector<Union_FOLLOW> VUnion_FOLLOW;
void Init()
{
	VGrammar.clear();
	VUnion_FIRST.clear();
	VUnion_FOLLOW.clear();
}
//根据产生式，分离出左部右部 
void InitGrammar(string s)
{
	int pos=s.find("->");
	grammar.left=s.substr(0,pos);
	grammar.right=s.substr(pos+2,s.length()-pos-2);
	VGrammar.push_back(grammar);//add into the VGrammar vector
} 
//Display the Grammar产生式 
void DispVGrammar()
{
	cout<<"All the Grammar:"<<endl;
	for(int i=0;i<VGrammar.size();i++)
	{
		cout<<VGrammar[i].left<<"->"<<VGrammar[i].right<<endl;
	}
}
//delete the char ' '
string DeleteSpace(string s)
{
	string newString="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=' ')
			newString+=s[i]; 
	}
	return newString;
}
//default the char whether is Upper 
bool isUpper(char ch)
{
	if(ch>='A'&&ch<='Z')
	{
		return true;
	}
	return false;
}
//Display the FIRST
void DispFirst()
{
	for(int i=0;i<VUnion_FIRST.size();i++)
	{
		cout<<VUnion_FIRST[i].left<<"的FIRST集是: "; 
		cout<<"{"<<VUnion_FIRST[i].FIRST[0];
		for(int j=1;j<VUnion_FIRST[i].FIRST.size();j++)
		{
			cout<<","<<VUnion_FIRST[i].FIRST[j];
		}
		cout<<"}"<<endl;
	}
}
//Display the FOLLOW
void DispFollow()
{
	for(int i=0;i<VUnion_FOLLOW.size();i++)
	{
		cout<<VUnion_FOLLOW[i].left<<"的FOLLOW集是: "; 
		cout<<"{"<<VUnion_FOLLOW[i].FOLLOW[0];
		for(int j=1;j<VUnion_FOLLOW[i].FOLLOW.size();j++)
		{
			cout<<","<<VUnion_FOLLOW[i].FOLLOW[j];
		}
		cout<<"}"<<endl;
	}
}
//Display the FOLLOW
void DispFollow_2()
{
	for(int i=0;i<VUnion_FOLLOW.size();i++)
	{
		cout<<VUnion_FOLLOW[i].left<<"的FOLLOW集是: "; 
		cout<<VUnion_FOLLOW[i].FOLLOW[0];
		for(int j=1;j<VUnion_FOLLOW[i].FOLLOW.size();j++)
		{
			cout<<" "<<VUnion_FOLLOW[i].FOLLOW[j];
		}
		cout<<endl;
	}
}
//在FIRST集找相同左部 
int FindLeft(string s)
{
	for(int i=0;i<VUnion_FIRST.size();i++)
	{
		if(VUnion_FIRST[i].left==s)
		{
			return i;
		}
	}
	return -1;
}
//查找FIRST集是否存在ε即@ 
bool isEmpty(int VPos)
{
	for(int i=0;i<VUnion_FIRST[VPos].FIRST.size();i++)
	{
		if(VUnion_FIRST[VPos].FIRST[i]=='@')
		{
			return true;
		}
	}
	return false;
}
//calculate the First
void getFirst()
{
	for(int i=VGrammar.size()-1;i>=0;i--)//从后面开始计算 
	{
		union_first.FIRST.clear();
		grammar = VGrammar[i];//get the VGrammar[i]
		string newString=grammar.right;
		union_first.left=grammar.left;//save the left in struct _union
		int pos;
		do{
			pos=newString.find("|");//find the | position
			string s;//save the 产生式右部 
			if(pos<newString.size()){//has find the |
				//get the Substr
				s=newString.substr(0,pos);

				//change the newString
				newString=newString.substr(pos+1,newString.size()-pos-1);
			}
			else//is -1
			{
				//s is from pos to end
				s=newString;
			}
			if(!isUpper(s[0]))//是终结符打头
			{
				union_first.FIRST.push_back(s[0]);//add into the _union.FIRST 
			}
			else
			{
				for(int i=0;i<s.size();)
				{
					string newS="";
					newS+=s[i];//不考虑' 
					/*
					if(s[i+1]=='\'')
					{
						i++;
						newS+=s[i];
					} */
					int VPos=FindLeft(newS);
					bool flag=isEmpty(VPos); 
					for(int j=0;j<VUnion_FIRST[VPos].FIRST.size();j++)//add FIRST-@
					{
						if(VUnion_FIRST[VPos].FIRST[j]!='@')//不为@ 
							union_first.FIRST.push_back(VUnion_FIRST[VPos].FIRST[j]);
					}
					if(flag) //循环 
					{
						i++;
					}
					else
						break;
				}
			}
		}while(pos!=-1);
		VUnion_FIRST.push_back(union_first);
	}
}
//判断FOLLOW集是否存在FOLLOW里面 
bool isExit(char ch)
{
	for(int i=0;i<union_follow.FOLLOW.size();i++)
	{
		if(union_follow.FOLLOW[i]==ch)
		{
			return true;
		}
	}
	return false;
}
//判断产生式左部newS能否推出@ 
bool canToEmpty(string newS)
{
	for(int i=0;i<VGrammar.size();i++)
	{
		if(VGrammar[i].left==newS)
		{
			string s=VGrammar[i].right;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]=='@')
					return true;
			}
			break;
		}
	}
	return false;
}
//查找产生式左部FOLLOW集下标 
int FindFollowLeft(string left)
{
	for(int i=0;i<VUnion_FOLLOW.size();i++)
	{
		if(VUnion_FOLLOW[i].left==left)
		{
			return i;
		}
	}
	return -1;
}
//查找产生式左部FIRST集下标 
int FindFIRSTLeft(string left)
{
	for(int i=0;i<VUnion_FIRST.size();i++)
	{
		if(VUnion_FIRST[i].left==left)
		{
			return i;
		}
	}
	return -1;
}
void FindGrammar(string s)
{
	for(int i=0;i<VGrammar.size();i++)
	{
		//if(VGrammar[i].right)
	}
}
//calculate the Follow
void getFollow()
{
	bool flag=true;
	for(int i=0;i<VGrammar.size();i++)
	{
		union_follow.FOLLOW.clear();
		union_follow.left=VGrammar[i].left;//保存相应的产生式左部 
		if(flag&&VGrammar[i].left==StartChar)//is start Char
		{
			union_follow.FOLLOW.push_back('#');//add '#'
			flag=false;
		}
		//寻找含VGrammar.left的产生式右部 
		for(int j=0;j<VGrammar.size();j++)
		{
			int pos;
			string newString=VGrammar[j].right;
			if(newString.find(union_follow.left)>=newString.size())//not find
			{
				continue;
			}
			int DivPos=newString.find("|");//find char | save into DivPos
			string s="";//存储分离出的产生式右部 
			do{
				if(DivPos<newString.size())//has find
				{
					s=newString.substr(0,DivPos);//get Substr into s
					newString=newString.substr(DivPos+1,newString.size()-DivPos-1);//get the remaining 
				} 
				else//not find
				{
					s=newString;
				}
				//has find 在产生式右部查找左部 
				if((pos=s.find(union_follow.left))<s.size())//has find
				{
					//为B->aA句型
					//查找该产生式左部FOLLOW集位置 
					int FOLLOW_Pos=FindFollowLeft(VGrammar[j].left);
					if(FOLLOW_Pos!=-1&&pos+1>=s.size())//add FOLLOW(B)
					{
						for(int k=0;k<VUnion_FOLLOW[FOLLOW_Pos].FOLLOW.size();k++)//add FOLLOW
						{
							if(!isExit(VUnion_FOLLOW[FOLLOW_Pos].FOLLOW[k])) 
								union_follow.FOLLOW.push_back(VUnion_FOLLOW[FOLLOW_Pos].FOLLOW[k]);
						} 
					}
					//后面跟的是终结符,add into FOLLOW 
					else if(!isUpper(s[pos+1]))
					{
						if(!isExit(s[pos+1]))
							union_follow.FOLLOW.push_back(s[pos+1]);
					}
					else
					{
						string newS="";//存储后面跟的非终结符组成的串 
						pos++; 
						newS+=s[pos];
						/*
						if(s[pos+1]=='\'')//考虑'号 
						{
							pos++;
							newS+=s[pos];
						}*/
						int FIRST_Pos=FindFIRSTLeft(newS); 
						if(FIRST_Pos!=-1&&canToEmpty(newS))//判断右部是否能够推出@ 
						{
							for(int k=0;k<VUnion_FIRST[FIRST_Pos].FIRST.size();k++)//add FIRST-'@'
							{
								if(!isExit(VUnion_FOLLOW[FOLLOW_Pos].FOLLOW[k])&&VUnion_FIRST[FIRST_Pos].FIRST[k]!='@')
									union_follow.FOLLOW.push_back(VUnion_FIRST[FIRST_Pos].FIRST[k]);
							} 
						}
						//add FOLLOW(B)
						if(FOLLOW_Pos!=-1)
							for(int k=0;k<VUnion_FOLLOW[FOLLOW_Pos].FOLLOW.size();k++)
							{
								if(!isExit(VUnion_FOLLOW[FOLLOW_Pos].FOLLOW[k]))
									union_follow.FOLLOW.push_back(VUnion_FOLLOW[FOLLOW_Pos].FOLLOW[k]);
							}
					}
				}
			}while(DivPos<s.size()); 
		}
		VUnion_FOLLOW.push_back(union_follow);
	}
}
//input the data
void Input()
{
	int n;
	cout<<"The number of Grammer: ";
	while(cin>>n)
	{
		Init();
		string s;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			InitGrammar(s);	
		}
		StartChar=VGrammar[0].left;
		cout<<"StartChar="<<StartChar<<endl;
		DispVGrammar();
		getFirst();
		DispFirst();
		cout<<endl;
		getFollow();
		DispFollow_2();
	}
}
//test the First,Follow
void Test()
{
	Input();
}
int main()
{
	Test();
	return 0;
}
/*
ε用@代替 
5
E->TE'
E'->+TE'|@
T->FT'
T'->*FT'|@
F->(E)|i

8
E->TE'
E'->+TE'
E'->@
T->FT'
T'->*FT'
T'->@
F->(E)
F->i

5
E->TS
S->+TS|@
T->FR
R->*FR|@
F->(E)|i 
2
S->aA|d
A->bAS|@ 
*/
