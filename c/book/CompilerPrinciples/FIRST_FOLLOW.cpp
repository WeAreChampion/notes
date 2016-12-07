#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAXS 50
int NONE[MAXS]={0};
string strings,noend,End;//终结符集和非终结符集 
string first[MAXS];// 用于存放每个终结符的first集
string First[MAXS];// 用于存放每个非终结符的first集
string Follow[MAXS]; // 用于存放每个非终结符的follow集
int N;			//the count
struct STR
{
    string left; 	//产生式左部 
    string right; 	//产生式右部
}; 
//求VN和VT
void VNVT(STR *p)//产生式数值 
{
    int i,j;
    for(i=0;i<N;i++) 
	{ 
       	for(j=0;j<(int)p[i].left.length();j++) 
      	{
      		//is Upper word like A,B..Z
          	if((p[i].left[j]>='A'&&p[i].left[j]<='Z'))//非终结符 
         	{
             	if(noend.find(p[i].left[j])>100)//not find
              		noend+=p[i].left[j]; 
         	}   
         	else //终结符
        	{
             	if(End.find(p[i].left[j])>100)//not find
                	End+=p[i].left[j];
         	}
       	}
       	for(j=0;j<(int)p[i].right.length();j++) 
      	{
           	if(!(p[i].right[j]>='A'&&p[i].right[j]<='Z'))//终结符 
          	{
               	if(End.find(p[i].right[j])>100)//not find  
                	End+=p[i].right[j];
          	}
          	else 
         	{
              	if(noend.find(p[i].right[j])>100)//非终结符
                	noend+=p[i].right[j];//not find
         	}
       	}
	}
}
//给出的串分离出左部和右部 
void getlr(STR *p,int i) 
{
	int j;
	for(j=0;j<strings.length();j++)
 	{
    	if(strings[j]=='-'&&strings[j+1]=='>')
      	{
        	p[i].left=strings.substr(0,j);//取子串 
        	p[i].right=strings.substr(j+2,strings.length()-j);//取剩余子串 
      	}
 	}
}
//对每个文法符号求first集
string Letter_First(STR *p,char ch)
{
	if(!(End.find(ch)>100))//has find in end 
	{
		first[End.find(ch)]="ch";
		return first[End.find(ch)-1];
	}
	if(!(noend.find(ch)>100))//has find in noend 非终结符 
	{
		for(int i=0;i<N;i++)//对n个产生式遍历 
	    {
		   	if(p[i].left[0]==ch) 
		   	{
			  	if(!(End.find(p[i].right[0])>100))//终结符打头 
			  	{
				  	if(First[noend.find(ch)].find(p[i].right[0])>100)
				  	{
					  	First[noend.find(ch)]+=p[i].right[0];
				  	}
			  	}
			  	if(p[i].right[0]=='@')//is @ 为空 
			  	{
				  	if(First[noend.find(ch)].find('@')>100)
				  	{
					  	First[noend.find(ch)]+='@';//加入FIRST集合 
				  	}
			  	}
			  	if(!(noend.find(p[i].right[0])>100))
			  	{
				  	if(p[i].right.length()==1)
				  	{
					  	string ff;
					  	ff=Letter_First(p,p[i].right[0]);
					  	for(int i_i=0;i_i<ff.length();i_i++)//查找非终结符的FIRST 
					  	{
						  	if( First[noend.find(ch)].find(ff[i_i])>100)
						  	{
					           	First[noend.find(ch)]+=ff[i_i];
						  	}
					  	}
				  	}
				  	else
				  	{
					  	for(int j=0;j<p[i].right.length();j++)
					  	{
						  	string TT;
				          	TT=Letter_First(p,p[i].right[j]);
						  	if(!(TT.find('@')>100)&&(j+1)<p[i].right.length())
				          	{
					          	sort(TT.begin(),TT.end());
					          	string tt;
					          	for(int t=1;t<TT.length();t++)
					          	{
						          	tt+=TT[t];
					          	}
					          	TT=tt;
							  	tt="";
							  	for(int t=0;t<TT.length();t++)
							  	{
								  	if( First[noend.find(ch)].find(TT[t])>100)
								  	{
					                   	First[noend.find(ch)]+=TT[t];
								  	}
							  	}
				          	}
						  	else
						  	{
							  	for(int t=0;t<TT.length();t++)
							  	{
								  	if( First[noend.find(ch)].find(TT[t])>100)
								  	{
					                   	First[noend.find(ch)]+=TT[t];
								  	}
							  	}
							  	break;
						  	}
					  	}
				  	} 
			  	}
		   	} 
     	}
		return  First[noend.find(ch)];//返回FIRST集合 
	}	
}
// 求每个非终结符的Follow集
string Letter_Follow(STR *p,char ch)
{
	NONE[noend.find(ch)]++;//添加节点 
	if(NONE[noend.find(ch)]==2)
	{
		NONE[noend.find(ch)]=0;
		return Follow[noend.find(ch)];
	}
	for(int i=0;i<N;i++)//遍历产生式 
	{
		for(int j=0;j<p[i].right.length();j++)
		{
			if(p[i].right[j]==ch)
			{
				if(j+1==p[i].right.length())
				{
					string gg;
					gg=Letter_Follow(p,p[i].left[0]);//递归调用求FOLLOW 
					NONE[noend.find(p[i].left[0])]=0;
					for(int k=0;k<gg.length();k++)//对新的FOLLOW遍历 
					{
						if(Follow[noend.find(ch)].find(gg[k])>100)
						{
							Follow[noend.find(ch)]+=gg[k];//添加到FOLLOW集合 
						}
					}
				}
				else
				{
					  string FF;
					  for(int jj=j+1;jj<p[i].right.length();jj++)
					  {
						  string TT;
				          TT=Letter_First(p,p[i].right[jj]);
						  if(!(TT.find('@')>100)&&(jj+1)<p[i].right.length())
				          {
					          sort(TT.begin(),TT.end());
					          string tt;
					          for(int t=1;t<TT.length();t++)
					          {
						          tt+=TT[t];
					          }
					          TT=tt;
							  tt="";
							  for(int t=0;t<TT.length();t++)
							  {
								  if( FF.find(TT[t])>100&&TT[t]!='@')
								  {
					                   FF+=TT[t];
								  }
							  }
				          }
						  else
						  {
							  for(int t=0;t<TT.length();t++)
							  {
								  if( FF.find(TT[t])>100)
								  {
					                   FF+=TT[t];
								  }
							  }
							  break;
						  }
					  }

					  if(FF.find('@')>100)//未找到@ 
					  {
						  for(int k=0;k<FF.length();k++)
						  {
							  if(Follow[noend.find(ch)].find(FF[k])>100)
						      {
							      Follow[noend.find(ch)]+=FF[k];//添加到FOLLOW集合 
						      }
						  }
					  }
					  else
					  {
						  for(int k=0;k<FF.length();k++)
						  {
							  if((Follow[noend.find(ch)].find(FF[k])>100)&&FF[k]!='@')
						      {
							      Follow[noend.find(ch)]+=FF[k];
						      }
						  }
						  string dd;
						  dd=Letter_Follow(p,p[i].left[0]);
						  NONE[noend.find(p[i].left[0])]=0;
						  for(int k=0;k<dd.length();k++)
						  {
							  if(Follow[noend.find(ch)].find(dd[k])>100)
						      {
							      Follow[noend.find(ch)]+=dd[k];
						      }
						  }
					  }
				}
			}
		}
	}
	return Follow[noend.find(ch)];
}
//主函数
int main()
{
    cout<<"请输入产生式总数及各产生式：@代表空\n"<<endl;
    cin>>N;		//产生式数目 
    STR *p=new STR[MAXS]; 
    for(int i=0;i<N;i++)   //输入产生式 
    {
        cin>>strings; 
        getlr(p,i); 
    }
	VNVT(p);
	cout<<"\n各非终结符的FIRST集为：\n"<<endl;
	for(int i=0;i<noend.length();i++)//对非终结符进行遍历 
	{
		cout<<"\tFIRST("<<noend[i]<<")"<<": {";
		string pp;
		pp=Letter_First(p,noend[i]);//得到FIRST集合 
		for(int j=0;j+1<pp.length();j++)//输出 
		{
			cout<<pp[j]<<",";
		}
		cout<<pp[pp.length()-1]<<"}"<<endl;
	}
	cout<<"\n各非终结符的FOLLOW集为：\n"<<endl;
	Follow[0]+='#';//开始符号包括# 
	for(int i=0;i<noend.length();i++)
	{
		cout<<"\tFOLLOW("<<noend[i]<<")"<<": {";
		string pp;
		pp=Letter_Follow(p,noend[i]);//得到FOLLOW集合 
		for(int j=0;j+1<pp.length();j++)//输出FOLLOW集 
		{
			cout<<pp[j]<<",";
		}
		cout<<pp[pp.length()-1]<<"}"<<endl;
	}
	return 0;
}
/*
10
S->AB
S->bC
A->@
A->b
B->@
B->aD
C->AD
C->b
D->aS
D->c
8
E->TS
S->+TS
s->@
T->FR
R->*FR
R->@
F->(E)
F->i
*/ 