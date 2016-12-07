#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int convertStringToInt(string s, int i, int j)
{
	int sum=s[j - 1] - '0', n = 1;
	for(int k = j - 2; j >= i; j--)
	{
		sum += (int)pow((double)(s[k] - '0'),(double)n);
		n++;
	}
	return sum;
}
int convert(string s)//将字串转化为整数 
{
	int sum = 0, k = 1;
	for(int i = s.length() - 1;i >= 0; i--)
	{
		sum += (s[i] - '0') * k;
		k = k * 10;
	}
	return sum;
}
void f(int a, int b[8])//将整数转化为二进制 
{
	int i = 0;
	while(a != 0) {
		b[i] = a % 2;
		a = a / 2;
		i++;
	}
}
int main()
{
	string s = "";
	while(cin>>s)
	{
		int i=0,count;
		//0 and 1 string and convert to the Int
		if(s.length() == 32)
		{
			cout<<convertStringToInt(s, 0, 8);
			for(i = 8; i < 32; i = i + 8)
			{
				cout<<"."<<convertStringToInt(s,i,i+7);
			}
			cout<<endl;
		} else {//convert to 0 and 1 string according to the int
			string str = "", st = "";
			for(i = 0; i < s.length(); i++) {
				//is number and add into str
				if(s[i] >= '0' && s[i] <= '9') {
					str += s[i];
				}
				if(s[i] == '.') {
					int a[8] = {0};
					//convert the str to 0 and 1
					f(convert(str), a);
					for(int j = 0; j < 8; j++) {
						cout<<a[j];
					}
					str = "";
				}
			}
			int a[8] = {0};
			f(convert(str), a);
			for(int j = 0; j < 8; j++) {
				cout<<a[j];
			}
			cout<<endl;
		}
		s = "";
	}
	return 0;
}