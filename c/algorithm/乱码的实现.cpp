/*
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>
void  menu();
void  fjiami();
void  fjiemi();
void  sjiami();
void  sjiemi();
int  main()
{
    menu();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	  if(n==-1)
		  break;
      switch(n)
	  {
	   case 1:fjiami();
		      break;
	   case 2:fjiemi();
			  break;
	   case 3:sjiami();
			  break;
	   case 4:sjiemi();
			  break;
	   case 5:printf("goodbye!\n");
			  exit(0);
       default :printf("the number is wrong");
			  break;
	  }
	}
	return 0;
}

void menu()
{
	printf("                         # 菜单 #    \n");
    printf("                   # # # # # # # # #  \n");
  	printf("                   #  1.方法一加密 #\n");
  	printf("                   #  2.方法一解密 #\n");
  	printf("                   #  3.方法二加密 #\n");
  	printf("                   #  4.方法二解密 #\n");
  	printf("                   #  5.退出程序   #\n");
    printf("                   # # # # # # # # #  \n");

}
//第一种方法加密
void  fjiami()
{
	FILE *fp1,*fp2;
	char  str[99],ch;
	int i;
	fp1=fopen("D://a.txt","r");
	  if(fp1==NULL)
	  {
		  printf("the file not found");
	            exit(0);
	  }
	fp2=fopen("D://b.txt","w");
	  if(fp2==NULL)
	  {
		  printf("the file not found");
	          exit(0);
	  }
	  while((fgets(str,99,fp1))!=NULL)
	  {
		  for(i=0;(ch=str[i])!='\0';i++)
		  {
			  {
				  if((ch>='a')&&(ch<='z'))
				      ch=219-ch;
			      if((ch>='A')&&(ch<='Z'))
					  ch=155-ch;

			  }

			  fputc(ch,fp2);
		  }
	  }

	  fclose(fp1);
	  fclose(fp2);
	  printf("方法一加密完成\n");
}
//第一种方法解密
void fjiemi()
{
	FILE *fp2,*fp3;
	char  str[99],ch;
	int  i;
    fp2=fopen("D://b.txt","r");
	  if(fp2==NULL)
	  {
		 printf("the file not found");
		   exit(0);
	  }
    fp3=fopen("D://c.txt","w");
	  if(fp3==NULL)
	 {
		 printf("the file not found");
		   exit(0);
	 }
	while((fgets(str,99,fp2))!=NULL)
	 {
		   for(i=0;(ch=str[i])!='\0';i++)
		   {
			   {
			      if((ch>='a')&&(ch<='z'))
				   ch=219-ch;
			      if((ch>='A')&&(ch<='Z'))
				   ch=155-ch;
			   }
		       fputc(ch,fp3);
		   }
	}
	 fclose(fp3);
	 fclose(fp2);
	 printf("方法一解密完成\n");

}
//第二种方法加密
void  sjiami()
{
	FILE *fp1,*fp2;
	char  str[99],ch;
	int i,num,a,b,c,t=0,M;
	fp1=fopen("D://a.txt","r");
	  if(fp1==NULL)
	  {
		  printf("the file not found");
		    exit(0);
	  }
	fp2=fopen("D://b.txt","w");
	  if(fp2==NULL)
	  {
		  printf("the file not found");
		    exit(0);
	  }
	 do{
		  printf("^-^请输入密钥:\n");
		  scanf("%d",&num);
		  while(1)
		  {
			  if(b==0)
				  break;
			  a=num%10;
			  b=num/10;
			  c=b%10;
			  num=b/10;
			  t=a+c+t;
		  }
		      M=t%26;
	  }
	  while(M==0);
	  while((fgets(str,99,fp1))!=NULL)
		{
		    for(i=0;(ch=str[i])!='\0';i++)
			  {
				  if((ch>='a')&&(ch<='z'))
				  {
					  if(ch+M>122)
						  ch=M-26+ch;
					  else
						  ch=ch+M;
				  }
				  if((ch>='A')&&(ch<='Z'))
				  {
					  if(ch+M>90)
						  ch=M+ch-26;
					  else
						  ch=ch+M;
				  }
				  fputc(ch,fp2);
			  }
		  }
			  fclose(fp1);
			  fclose(fp2);
			  printf("方法二加密完成\n");
}
//第二种方法解密
void sjiemi()
{
	FILE *fp2,*fp3;
	char str[99],ch;
	int i,num,a,b,c,t=0,M;
	fp2=fopen("D://b.txt","r");
	  if(fp2==NULL)
	  {
		  printf("the file not found");
		     exit(0);
	  }
	fp3=fopen("D://c.txt","w");
	  if(fp3==NULL)
	  {
		  printf("the file not found");
		      exit(0);
	  }

	  do
	  {
		  printf("^-^请输入密钥:\n");
		  scanf("%d",&num);
		  while(1)
		  {
			  if(b==0)
				  break;
			  a=num%10;
			  b=num/10;
			  c=b%10;
			  num=b/10;
			  t=a+c+t;
		  }
		  M=t%26;
	  }
	  while(M==0);
	  while((fgets(str,99,fp2))!=NULL)
	  {

		  for(i=0;(ch=str[i])!='\0';i++)
		  {
			  if((ch>='a')&&(ch<='z'))
			  {
				  if(ch-M<97)
					  ch=26-M+ch;
				  else
					  ch=ch-M;
			  }
			  if((ch>='A')&&(ch<='Z'))
			  {
				  if(ch-M<65)
					  ch=26-M+ch;
				  else
					  ch=ch-M;
			  }
			  fputc(ch,fp3);
		  }
	  }
	  fclose(fp2);
	  fclose(fp3);
	  printf("方法二解密完成");
 }
*/

#include <iostream>
#include<fstream>
#include<string>
using namespace std;
void menu()
{
	printf("                         # 菜单 #    \n");
	printf("                   # # # # # # # # #  \n");
	printf("                   #  1.方法一加密 #\n");
	printf("                   #  2.方法一解密 #\n");
	printf("                   #  3.方法二加密 #\n");
	printf("                   #  4.方法二解密 #\n");
	printf("                   #  5.退出程序   #\n");
	printf("                   # # # # # # # # #  \n");

}
//文件解密
void file_encryption(string str)
{
	//string s;
	char ch;
	int i=0;
	ifstream infile("str",ios::in);
	ofstream outfile("str",ios::out);
	if(!infile) {
		cerr<<"open error! The fifle isn't exist!"<<endl;
		exit(1);
	}
	//infile>>s[i];
	//infile>>ch;
	//outfile<<endl;
	while(infile>>ch&&ch!='\n') {
		if(ch='a'&& ch<='z') {
			ch=219-ch;
		}
		if(ch>='A' && ch<='Z') {
			ch=155-ch;
		}

		outfile.put(ch);
		//infile>>ch;
	}
	/*
	for(i=0;i<s.length();i++)
	{
		if(s[i]>='a'&& s[i]<='z')
		{
			s[i]=219-s[i];
		}
		if(s[i]>='A' && s[i]<='Z')
		{
			s[i]=155-s[i];
		}
		outfile<<s[i];
		i++;
		infile>>s[i];
	}
	*/
	infile.close();
	outfile.close();
	cout<<"加密完成"<<endl;
}
int testPassword(string password1,string password2)
{
	if(password1==password2) {
		return 1;
	} else {
		return 0;
	}
}
//文件解密
void file_decryption(string str)
{
	string s;
	int i;
	ifstream infile("str",ios::in);
	if(!infile) {
		cerr<<"open error! The fifle isn't exist!"<<endl;
		exit(1);
	}
	infile>>s;
	for(i=0; i<s.length(); i++) {
		if(s[i]>='a'&& s[i]<='z') {
			s[i]=219-s[i];
		}
		if(s[i]>='A' && s[i]<='Z') {
			s[i]=155-s[i];
		}
	}
	infile.close();
	ofstream outfile("str",ios::out);
	if(!outfile) {
		cerr<<"open error! The fifle isn't exist!"<<endl;
		exit(1);
	}
	outfile<<s<<endl;
	outfile.close();
	cout<<"解密完成"<<endl;
}
int main()
{
	//string str1,str2,password1,password2;
	string str1,str2;
	char password1[20],password2[20];
	int n,i;
	while(cout<<"请输入要执行的步骤: "&&cin>>n) {
		menu();
		i=0;
		if(n==-1)
			break;
		switch(n) {
		case 1:
			cout<<"请输入需要加密的文件名:  ";
			cin>>str1;
			cout<<"请输入加密的密码: ";
			cin>>password1;
			file_encryption(str1);
			cout<<str1;
			break;

		case 2:
			cout<<"请输入解密的密码: ";
			cin>>password2;
			while(testPassword(password1,password2)==0) {
				cout<<"输入解密密码错误，请重新输入解密的密码: ";
				cin>>password2;
			}
			cout<<"请输入需要解密的文件名: ";
			cin>>str2;
			file_decryption(str2);
			break;

			//case 3:
			//	sjiami();break;
			//case 4:
			//	sjiemi();break;
		case 5:
			cout<<"goodbye!"<<endl;
			exit(0);

		default :
			cout<<"the number is wrong"<<endl;
			break;
		}
		system("cls");
	}
	return 0;
}

/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	cout<<s<<endl;
	return 0;
}
*/