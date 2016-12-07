#include<iostream>
#include<string>
using namespace std;
string getsub(string s,int it1,int it2)
{
	string str="";
	for(int i=it1;i<it2;i++)
	{
		if(s[i]!=' ')
			str+=s[i];
	}
	return str;
}
int main()
{
	//while(true)
//	{
		char ch;
		string s="",str1="",str2="";
		while((ch=getchar())!='#')
		{
			if(ch!=' ')
				s+=ch;
		}
		getchar();
		int flag=1;
		while((ch=getchar())!='#')
		{
			if(flag)
			{
				if(ch=='_')
					flag=0;
				else if(ch!=' ')
					str1+=ch;
			}
			else
			{
				if(ch!=' ')
					str2+=ch;
			}
		}
		getchar();
		//cout<<s<<"#"<<str1<<"#"<<str2<<"#"<<endl;
		int it1=s.find(str1),it2=s.find(str2);
		cout<<getsub(s,it1+str1.length(),it2)<<endl;
	//}
	return 0;
} 
/*
where is hero from #
where is _ from #
where is hero from #
where is _ from #

*/