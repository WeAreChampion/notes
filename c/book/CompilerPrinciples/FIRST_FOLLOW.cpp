#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAXS 50
int NONE[MAXS]={0};
string strings,noend,End;//�ս�����ͷ��ս���� 
string first[MAXS];// ���ڴ��ÿ���ս����first��
string First[MAXS];// ���ڴ��ÿ�����ս����first��
string Follow[MAXS]; // ���ڴ��ÿ�����ս����follow��
int N;			//the count
struct STR
{
    string left; 	//����ʽ�� 
    string right; 	//����ʽ�Ҳ�
}; 
//��VN��VT
void VNVT(STR *p)//����ʽ��ֵ 
{
    int i,j;
    for(i=0;i<N;i++) 
	{ 
       	for(j=0;j<(int)p[i].left.length();j++) 
      	{
      		//is Upper word like A,B..Z
          	if((p[i].left[j]>='A'&&p[i].left[j]<='Z'))//���ս�� 
         	{
             	if(noend.find(p[i].left[j])>100)//not find
              		noend+=p[i].left[j]; 
         	}   
         	else //�ս��
        	{
             	if(End.find(p[i].left[j])>100)//not find
                	End+=p[i].left[j];
         	}
       	}
       	for(j=0;j<(int)p[i].right.length();j++) 
      	{
           	if(!(p[i].right[j]>='A'&&p[i].right[j]<='Z'))//�ս�� 
          	{
               	if(End.find(p[i].right[j])>100)//not find  
                	End+=p[i].right[j];
          	}
          	else 
         	{
              	if(noend.find(p[i].right[j])>100)//���ս��
                	noend+=p[i].right[j];//not find
         	}
       	}
	}
}
//�����Ĵ�������󲿺��Ҳ� 
void getlr(STR *p,int i) 
{
	int j;
	for(j=0;j<strings.length();j++)
 	{
    	if(strings[j]=='-'&&strings[j+1]=='>')
      	{
        	p[i].left=strings.substr(0,j);//ȡ�Ӵ� 
        	p[i].right=strings.substr(j+2,strings.length()-j);//ȡʣ���Ӵ� 
      	}
 	}
}
//��ÿ���ķ�������first��
string Letter_First(STR *p,char ch)
{
	if(!(End.find(ch)>100))//has find in end 
	{
		first[End.find(ch)]="ch";
		return first[End.find(ch)-1];
	}
	if(!(noend.find(ch)>100))//has find in noend ���ս�� 
	{
		for(int i=0;i<N;i++)//��n������ʽ���� 
	    {
		   	if(p[i].left[0]==ch) 
		   	{
			  	if(!(End.find(p[i].right[0])>100))//�ս����ͷ 
			  	{
				  	if(First[noend.find(ch)].find(p[i].right[0])>100)
				  	{
					  	First[noend.find(ch)]+=p[i].right[0];
				  	}
			  	}
			  	if(p[i].right[0]=='@')//is @ Ϊ�� 
			  	{
				  	if(First[noend.find(ch)].find('@')>100)
				  	{
					  	First[noend.find(ch)]+='@';//����FIRST���� 
				  	}
			  	}
			  	if(!(noend.find(p[i].right[0])>100))
			  	{
				  	if(p[i].right.length()==1)
				  	{
					  	string ff;
					  	ff=Letter_First(p,p[i].right[0]);
					  	for(int i_i=0;i_i<ff.length();i_i++)//���ҷ��ս����FIRST 
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
		return  First[noend.find(ch)];//����FIRST���� 
	}	
}
// ��ÿ�����ս����Follow��
string Letter_Follow(STR *p,char ch)
{
	NONE[noend.find(ch)]++;//��ӽڵ� 
	if(NONE[noend.find(ch)]==2)
	{
		NONE[noend.find(ch)]=0;
		return Follow[noend.find(ch)];
	}
	for(int i=0;i<N;i++)//��������ʽ 
	{
		for(int j=0;j<p[i].right.length();j++)
		{
			if(p[i].right[j]==ch)
			{
				if(j+1==p[i].right.length())
				{
					string gg;
					gg=Letter_Follow(p,p[i].left[0]);//�ݹ������FOLLOW 
					NONE[noend.find(p[i].left[0])]=0;
					for(int k=0;k<gg.length();k++)//���µ�FOLLOW���� 
					{
						if(Follow[noend.find(ch)].find(gg[k])>100)
						{
							Follow[noend.find(ch)]+=gg[k];//��ӵ�FOLLOW���� 
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

					  if(FF.find('@')>100)//δ�ҵ�@ 
					  {
						  for(int k=0;k<FF.length();k++)
						  {
							  if(Follow[noend.find(ch)].find(FF[k])>100)
						      {
							      Follow[noend.find(ch)]+=FF[k];//��ӵ�FOLLOW���� 
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
//������
int main()
{
    cout<<"���������ʽ������������ʽ��@�����\n"<<endl;
    cin>>N;		//����ʽ��Ŀ 
    STR *p=new STR[MAXS]; 
    for(int i=0;i<N;i++)   //�������ʽ 
    {
        cin>>strings; 
        getlr(p,i); 
    }
	VNVT(p);
	cout<<"\n�����ս����FIRST��Ϊ��\n"<<endl;
	for(int i=0;i<noend.length();i++)//�Է��ս�����б��� 
	{
		cout<<"\tFIRST("<<noend[i]<<")"<<": {";
		string pp;
		pp=Letter_First(p,noend[i]);//�õ�FIRST���� 
		for(int j=0;j+1<pp.length();j++)//��� 
		{
			cout<<pp[j]<<",";
		}
		cout<<pp[pp.length()-1]<<"}"<<endl;
	}
	cout<<"\n�����ս����FOLLOW��Ϊ��\n"<<endl;
	Follow[0]+='#';//��ʼ���Ű���# 
	for(int i=0;i<noend.length();i++)
	{
		cout<<"\tFOLLOW("<<noend[i]<<")"<<": {";
		string pp;
		pp=Letter_Follow(p,noend[i]);//�õ�FOLLOW���� 
		for(int j=0;j+1<pp.length();j++)//���FOLLOW�� 
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