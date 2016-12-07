#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char s1[100],s2[100],str[100];
	cout<<"请输入要读入的文件名：";
	cin>>s1;
	int k=0,i;
	for(i=0;i<strlen(s1);i++)
	{
		if(s1[i]=='\\')
		{
			str[k]='\\';
			k++;
		}
		str[k]=s1[i];
		k++;
	}
	str[k]='\0';
	cout<<str<<endl;
	ifstream infile(str,ios::in);
	if(!infile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	k=0;
	cout<<"请输入要写入的文件名：";
	cin>>s2;
	for(i=0;i<strlen(s2);i++)
	{
		if(s2[i]=='\\')
		{
			str[k]='\\';
			k++;
		}
		str[k]=s2[i];
		k++;
	}
	str[k]='\0';
	cout<<str<<endl;
	ofstream outfile(str,ios::out|ios::trunc);
	if(!outfile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	char a;
	while(infile.get(a))
	{
		cout<<a;
		outfile<<(a*100);
	}
	return 0;
}