#include<iostream>
#include<string>
using namespace std;
char pan[4]={'C','D','E','F'}; 
bool checkURL(string url)
{
	int i;
	if((url[0]!='C'&&url[0]!='c')&&(url[0]!='D'&&url[0]!='d')&&(url[0]!='E'&&url[0]!='e')&&(url[0]!='F'&&url[0]!='f'))
		return false;
	if(url[1]!=':'||url[2]!='\\')
		return false;
	int len=url.size()-3;
	int end;
	string s=url.substr(3,len);
	while((end=s.find("\\"))!=-1)
	{
		for(i=0;i<end;i++)
			if(s[i]=='>'||s[i]=='<')
				return false;
		s.erase(0,end+1);//delete the elem
	}
	if(s.find(".")==-1)
		return false;
	return true;
}
int main()
{
	string s;
	cout<<"Please input string :";
	while(cin>>s)
	{
		if(!checkURL(s))
			cout<<"-1"<<endl;
		else
			cout<<s<<" is suitable!\n";
		cout<<"Please input string :";
	}
	return 0;
}
/*
C:\sasad\asd.txt
D:\asa.asd\asdasd
B:\asdas.txt
*/