#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;
void StrAssign(SqString &str,char cstr[])//creat the SqString
{
	int i; 
	for(i=0;cstr[i]!='\0';i++)
	{
		str.data[i]=cstr[i];
	}
	str.length=i;
}
void StrCopy(SqString &s,SqString t)//copy the SqString 
{
	int i;
	for(i=0;i<t.length;i++)
	{
		s.data[i] = t.data[i] ;
	}
	s.length=t.length;
}
int StrEqual(SqString s,SqString t)//judge the SqString is equal
{
	if(s.length!=t.length)
		return 0;
	for(int i=0;i<t.length;i++)
	{
		if(s.data[i]!=t.data[i])
			return 0;
	}
	return 1;
}
int StrLength(SqString s)//get the SqString's length
{
	return s.length;
}
void Concat(SqString &s,SqString t)//connect the SqString
{
	for(int i=0;i<t.length;i++)
	{
		s.data[s.length+i]=t.data[i];
	}
	s.length=s.length+t.length;
}
SqString SubStr(SqString s,int i,int j)//get the SqString's substring
{
	SqString str;
	str.length=0;
	if(i>j)
	{
		int temp=i;
		i=j;
		j=temp;
	}
	for(int k=i;k<=j;k++)
	{
		str.data[k-i]=s.data[k];
	}
	str.length=j-i+1;
	return str;
}
SqString SubStr1(SqString s,int i,int j)//get substring
{
	SqString str;
	str.length=0;
	if(i<=0 || i>s.length || j<0 || i+j-1>s.length)
	{
		cout<<"input error!"<<endl;
		return str;
	}
	for(int k=i-1;k<i+j-1;k++)
	{
		str.data[k-i+1]=s.data[k];
	}
	str.length=j;
	return str;
}
SqString DelStr(SqString s,int i,int j)//删除从下标从i到j的字符，产生新串 
{
	SqString str;
	int k;
	str.length=0;
	if(i<0||j>=s.length)
	{
		cout<<"删除下标出错!"<<endl;
		return str; 
	}
	str.length = s.length-j+i-1;
	for(k=0;k<i;k++)
	{
		str.data[k]=s.data[k];
	}
	for(k=j+1;k<s.length;k++)
	{
		str.data[i++]=s.data[k];
	}
	return str;
}
SqString DeleteStr(SqString s,int i,int j)//删除s的第i个字符开始的第j个字符产生新串 
{
	int k;
	SqString str;
	str.length=0;
	if(i<=0||i>s.length||i+j>s.length+1)
	{
		cout<<"删除下标出错!"<<endl;
		return str; 
	}
	for(k=0;k<i-1;k++)
	{
		str.data[k]=s.data[k];
	}
	for(k=i+j-1;k<s.length;k++)
	{
		str.data[k-j]=s.data[k];
	}
	str.length=s.length-j;
	return str;
}
void DispStr(SqString s)//output the SqString
{
	if(s.length)
	{
		for(int i=0;i<s.length;i++)
		{
			cout<<s.data[i];
		}
		cout<<endl;
	}
}
SqString InsertStr(SqString s1,int i,SqString s2)//insert SqString
{
	SqString str;
	int k;
	for(k=0;k<i;k++)
	{
		str.data[k]=s1.data[k];
	}
	for(k=0;k<s2.length;k++)
	{
		str.data[i+k]=s2.data[k];
	}
	for(k=i;k<s1.length;k++)
	{
		str.data[i+s2.length-1+k]=s1.data[k];
	}
	str.length=s1.length+s2.length;
	return str;
}
SqString RepStr(SqString s,int i,int j,SqString t)//s的第i个字符开始的j个字符替换成t 
{
	int k;
	SqString str;
	str.length=0;
	if(i<=0||i>s.length||i+j-1>s.length)
	{
		cout<<"删除下标出错!"<<endl;
		return str; 
	}
	for(k=0;k<i-1;k++)
	{
		str.data[k]=s.data[k];
	}
	for(k=0;k<t.length;k++)
	{
		str.data[i+k-1]=t.data[k];
	}
	for(k=i+j-1;k<s.length;k++)
	{
		str.data[t.length+k-j]=s.data[k];
	}
	str.length=s.length-j+t.length;
	return str;
}
int Index(SqString s,SqString t)//简单的匹配算法 
{
	int i=0,j=0,k;//int n=0;
	while(i<s.length&&j<t.length)
	{
		if(data[i]==t.data[j])
		{
			j++;
			i++;
		}
		else
		{
			i=i-j+1;//n++;
			j=0;
		}
	}
	if(j>=t.length)
	{
		k=i-t.length;
	}
	else
	{
		k=-1;
	}
	return k;//return the posion(has found) or -1(not find)
}
void GetNext(SqString t,int next[])//由模式串t求出next值 
{
	int j=0,k=-1;
	next[0]=-1;
	while(j<t.length-1)
	{
		if(k==-1||t.data[j]==t.data[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else k=next[k];
	}
}
void DetNextval(SqString t,int nextval[])
{
	int j=0,k=-1;
	nextval[0]=-1;
	while(j<t.length)length
	{
		if(k==-1||t.data[j]==t.data[k])
		{
			j++;
			k++;
			if(t.data!=t.data[k])
				nextval[j]=k;
			else
				nextval[j]=nextval[k];
		}
		else k=nextval[k];
	}
}
int main()
{
	SqString s,s1,s2,s3,s4;
	StrAssign(s,"abcdefghijklmn");
	StrAssign(s1,"xyz");
	cout<<"the SqString s :   ";
	DispStr(s);
	s4=InsertStr(s,1,s1);
	cout<<"the SqString s4:   ";
	DispStr(s4);
	cout<<"the s4 SQString's length:   "<<StrLength(s4)<<endl;
	cout<<"the s SQString's length:   "<<StrLength(s)<<endl;
	cout<<"the s1 SQString's length:   "<<StrLength(s1)<<endl;
	Concat(s,s1);
	cout<<"the SqString s :   ";
	DispStr(s);
	cout<<"the concat SQString's length:   "<<StrLength(s)<<endl;
	s2=SubStr(s,4,8);
	cout<<"the SqString s2:   ";
	DispStr(s2);
	cout<<"the s2 SQString's length:   "<<StrLength(s2)<<endl;
	s3=SubStr(s,8,4);
	cout<<"the SqString s3:   ";
	DispStr(s3);
	cout<<"the s3 SQString's length:   "<<StrLength(s3)<<endl;
	SqString s5=DelStr(s3,1,3),s6=DelStr(s2,1,3);
	cout<<"the delete SqString s5:   ";
	DispStr(s5);
	cout<<"the delete SqString s6:   ";
	DispStr(s6);
	SqString s7=(s5,2,1,s6);
	cout<<"the replace SqString s7:   ";
	DispStr(s7);
	return 0;
}