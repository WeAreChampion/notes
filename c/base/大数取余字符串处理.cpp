#include<iostream>
#include<string>
using namespace std;
int convertStringToInt(string s)//将字符串转化为整数
{
	int sum = 0, k = 1;
	for(int i = s.length() - 1; i >= 0; i--) {
		sum += (s[i] - '0') * k;
		k = k * 10;
	}
	return sum;
}
void convertIntToString(int a, string &s)//将整数转化为字符串 
{
	s = "";
	while(a != 0) {
		s += a % 10 + '0';
		a = a/10;
	}
}
void re(string &s)//字符串的倒置 
{
	int t = s.length();
	for(int i = 0; i <= t / 2; i++) {
		char ch = s[i];
		s[i] = s[t - i - 1];
		s[t - i - 1] = ch;
	}
}
int main()
{
	string s = "";
	int a;
	while(cin>>s>>a)
	{
		string str = "";
		for(int i = 0; i < s.length(); i++) {
			str += s[i];
			int t = convertStringToInt(str);
		//	cout<<"t="<<t<<endl;
			if(t < a) {
				continue;
			} else {
				int temp = t % a;
				str = "";
				if(temp != 0) {
					convertIntToString(temp, str);
					re(str); 
				}
			}
		}
		if(str != "") { 
			cout<<str<<endl;
		} 
		else { 
			cout<<0<<endl;
		} 
	}
	return 0;
}
/*
12345 5
*//*
	cout<<convertStringToInt("1213213")<<endl;
	string ss="";
	int a=122;
	convertIntToString(a,ss);
	cout<<a<<" "<<ss<<endl;
	*/