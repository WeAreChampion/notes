#include<iostream>
using namespace std;
#include<cctype>
void testIsalnum()
{
	/*
		isalnum(int ch);
		If is a char word or number then return value != 0,
		else return the value = 0.
		当变元为字母或数字时，函数返回非0值，否则返回0. 
	*/
	cout<<isalnum('a')<<endl;
	cout<<isalnum(1)<<endl;
	cout<<isalnum('$')<<endl;
	cout<<isalnum('1')<<endl;
	/*
		result: 
		2
		0
		0
		4
	*/
}
void testIsalpha()
{
	/*
		isalpha(int ch);
		If is a char word then return value != 0,
		else return the value = 0.
		当变元为字母表中的字母时，函数返回非0值，否则返回0.
		各种语言的字母表互不相同，对于英语来说，
		字母表由大写和小写的字母A-Z组成。 
	*/
	cout<<isalpha('a')<<endl;
	cout<<isalpha('A')<<endl;
	cout<<isalpha('$')<<endl;
	cout<<isalpha('1')<<endl;
	/*
		result: 
		2
		1
		0
		0
	*/
}
void testIscntrl()
{
	/*
		iscntrl(int ch);
		If is a control char word like '\n' then return value != 0,
		else return the value = 0.
		当变元是控制字符时，函数返回非0，否则返回0. 
	*/
	cout<<iscntrl('a')<<endl;
	cout<<iscntrl('A')<<endl;
	cout<<iscntrl('1')<<endl;
	cout<<iscntrl('\n')<<endl;
	/*
		result: 
		0
		0
		0
		32
	*/
}
void testIsdigit()
{
	/*
		isdigit(int ch);
		If is a char number then return value != 0,
		else return the value = 0.
		当变元是十进制数字时，函数返回非0值，否则返回0. 
	*/
	cout<<isdigit('a')<<endl;
	cout<<isdigit('A')<<endl;
	cout<<isdigit('1')<<endl;
	cout<<isdigit(1)<<endl;
	cout<<isdigit(11)<<endl;
	cout<<isdigit(2)<<endl;
	/*
		result: 
		0
		0
		4
		0
		0
		0
	*/
}
void testIsgraph()
{
	/*
		isgraph(int ch);
		如果变元为除空格之外的任何可打印字符，
		则函数返回非0，否则返回0. 
	*/
	cout<<isgraph('a')<<endl;
	cout<<isgraph('A')<<endl;
	cout<<isgraph(' ')<<endl;
	cout<<isgraph(1)<<endl;
	cout<<isgraph('\0')<<endl;
	/*
		result: 
		2
		1
		0
		0
		0
	*/
}
/*
	islower(int ch);
	当变元是小写字母，函数返回非0值，否则返回0.
	
	isprint(int ch); 
	当变元是除空格、字母和数字外的可打印字符，则函数返回非0，
	否则返回0. 
	
	isspace(int ch);
 	当变元为空白字符（包括空格、换页符、换行符、水平制表符和
    垂直制表符）时，函数返回非0，否则返回0. 
    
    isupper(int ch);
	如果变元为大写字母，函数返回非0，否则返回0.
	
	isxdigit(int ch);
 	当变元为十六进制数字时，函数返回非0，否则返回0。
  	
  	int tolower(int ch); 
  	当ch为大写字母时，返回其对应的小写字母，否则返回ch。
	
	int toupper(int ch);
	当ch为小写字母时，返回其对应的大写字母，否则返回ch。
	
  	
*/ 
int main()
{
//	testIsalnum();
//	testIsalpha();
//	testIscntrl();
//	testIsdigit();
	testIsgraph();
	return 0;
} 