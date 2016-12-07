#include<iostream>
using namespace std;
#include<string>
#include<fstream>
/**
	To read the file's info by file's name or path
*/
bool ReadFromFile(char *url)
{
	ifstream infile(url, ios::in);
	if(!infile) {
		cerr << "open error! "<< endl;
		return false;
	}
	string s;
	cout << "The file's information is:\n";
	// �ж��룬ֱ����������Ϊֹ
	while(getline(infile,s)) {
		cout << s << endl;
	}
	
	// �ر��ļ���
	infile.close();
	return true;
}

/**
	To write info into file by file's name or path
*/
bool WriteToFile(char *url)
{
	ofstream outfile(url, ios::out);
	if(!outfile) {
		cerr << "open error!" << endl;
		return false;
	}
	char ch;
	cout << "Please input the string:\n";
	
	// ������#�Ž���
	while((ch=getchar()) != '#') {
		cout << ch;
	}
	outfile.close();
	return true;
}/*
char* getFile(string s)
{
	char url[100];
	int k=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='\\')
		{
			url[k++]='\\';
			url[k++]='\\';
		}
		else
			url[k++]=s[i];
	}
	return url;
}
bool CompareUrl(char *url)
{
	for(int i=0;i<strlen(url);i++)
	{
		if(url[i]=='\\'&&url[i+1]!='\\')
		{
			return false;
		}
	}
	return true;
}*/
int main()
{
	//char url[]="E:\\����ĵ�д��\\User.txt";
	char url[100];
	cout << "Please input the File url: ";
	while(scanf("%s", url) != EOF) {
		//printf("%s\n", url);
		if(!ReadFromFile(url)) {
			exit(1);
		}
		cout << "Please input the File url: ";
		scanf("%s", url);
		if(!WriteToFile(url)) {
			exit(1);
		}
		system("pause");
		system("cls");
		cout << "Please input the File url: ";
	}
	return 0;
}
/*
E:\\����ĵ�д��\\User.txt
ahsadsd.txt
asdasd
asfdasa
#
*/