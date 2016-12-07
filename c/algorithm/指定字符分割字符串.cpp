#include<iostream>
#include<string>
#include<vector>
using namespace std;
/**
	ÀûÓÃch·Ö¸î×Ö·û´®
	save in vector<string> v
*/
void DivideString(string str, char ch, vector<string> &v)
{
	string s = "";
	int len = str.size();
	for(int i = 0; i < len; i++) {
		if(str[i] != ch) {
			s += str[i];
		} else { //is ch
			v.push_back(s);
			s = "";
		}
	}
	if(s != "") {
		v.push_back(s);
	}
	return ;
}
template<class Type>
void Disp(vector<Type> v)
{
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
int main()
{
	string s = "aaa|bbb|ccc|asdads";
	vector<string> v;
	v.clear();
	DivideString(s, '|', v);
	Disp(v);
	return 0;
}