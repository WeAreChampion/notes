#include<iostream>
using namespace std;
int getAllSum(string s)//get 数字和 
{
	int sum = 0;
	int length = s.size();
	for(int i = 0; i < length; i++) {
		sum += s[i] - '0';
	}
	return sum;
}
int getOddSum(string s)//get 奇数和 
{
	int sum = 0;
	int length = s.size();
	for(int i = 0; i < length; i++) {
		if(i % 2 == 0) { 
			sum += s[i] - '0';
		} 
	}
	return sum;
}
int getEvenSum(string s)//get 偶数和 
{
	int sum = 0;
	int length = s.size();
	for(int i = 0; i < length; i++)  {
		if(i % 2 == 1) { 
			sum += s[i] - '0';
		} 
	}
	return sum;
}
//To get the sum from start to end in string s.
int getSum(string s, int start, int end)
{
	int sum = 0;
	int length = s.size();
	int _start = start > 0 ? start : 0;
	int _end = end > length ? length : end;
	for(int i = _start; i < _end; i++) {
		sum += s[i] - '0';
	}
	return sum;
}
//To get the sum from start to the string's end.
int getSum(string s, int start)
{
	int sum = 0;
	int length = s.size();
	int _start = start > 0 ? start : 0;
	for(int i = _start; i < length; i++) {
		sum += s[i] - '0';
	}
	return sum;
}
void testStringSum()
{
	string s = "123456789";
	cout<<"All Sum is : "<<getAllSum(s)<<endl;
	cout<<"Odd Sum is : "<<getOddSum(s)<<endl;
	cout<<"Even Sum is : "<<getEvenSum(s)<<endl;
	cout<<"string s[2,3] sum is : "<<getSum(s, 2, 4)<<endl;
	cout<<"string s sum from 2 is : "<<getSum(s, 2)<<endl;
} 
int main()
{
	testStringSum();
	return 0;
}