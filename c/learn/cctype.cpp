#include<iostream>
using namespace std;
#include<cctype>
void testIsalnum()
{
	/*
		isalnum(int ch);
		If is a char word or number then return value != 0,
		else return the value = 0.
		����ԪΪ��ĸ������ʱ���������ط�0ֵ�����򷵻�0. 
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
		����ԪΪ��ĸ���е���ĸʱ���������ط�0ֵ�����򷵻�0.
		�������Ե���ĸ������ͬ������Ӣ����˵��
		��ĸ���ɴ�д��Сд����ĸA-Z��ɡ� 
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
		����Ԫ�ǿ����ַ�ʱ���������ط�0�����򷵻�0. 
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
		����Ԫ��ʮ��������ʱ���������ط�0ֵ�����򷵻�0. 
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
		�����ԪΪ���ո�֮����κοɴ�ӡ�ַ���
		�������ط�0�����򷵻�0. 
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
	����Ԫ��Сд��ĸ���������ط�0ֵ�����򷵻�0.
	
	isprint(int ch); 
	����Ԫ�ǳ��ո���ĸ��������Ŀɴ�ӡ�ַ����������ط�0��
	���򷵻�0. 
	
	isspace(int ch);
 	����ԪΪ�հ��ַ��������ո񡢻�ҳ�������з���ˮƽ�Ʊ����
    ��ֱ�Ʊ����ʱ���������ط�0�����򷵻�0. 
    
    isupper(int ch);
	�����ԪΪ��д��ĸ���������ط�0�����򷵻�0.
	
	isxdigit(int ch);
 	����ԪΪʮ����������ʱ���������ط�0�����򷵻�0��
  	
  	int tolower(int ch); 
  	��chΪ��д��ĸʱ���������Ӧ��Сд��ĸ�����򷵻�ch��
	
	int toupper(int ch);
	��chΪСд��ĸʱ���������Ӧ�Ĵ�д��ĸ�����򷵻�ch��
	
  	
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