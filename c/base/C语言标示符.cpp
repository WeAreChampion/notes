#include<iostream>
using namespace std;
bool judgeWord(char ch)
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		return true;
	}
	return false;
}
bool judgeNumber(char ch)
{
	if(ch >= '0'&& ch <= '9') {
		return true;
	}
	return false;
}
bool judge(char *ch)
{
	for(int i = 1; i < strlen(ch); i++) {
		if(!(judgeWord(ch[i]) || judgeNumber(ch[i]) || ch[i] == '_')) {
			return false;
		}
	}
	return true;
}
int main()
{
	int ca;
	cin>>ca;
	getchar();
	while(ca--) {
		char ch[51];
		cin.getline(ch,51);
//		cout<<ch<<endl;
//		is word or _
		if(judgeWord(ch[0]) || ch[0] == '_') {
			if(judge(ch)) {
				cout<<"yes\n";
			} else {
				cout<<"no\n";
			}
		} else {
			cout<<"no\n";
		}
	}
	return 0;
}