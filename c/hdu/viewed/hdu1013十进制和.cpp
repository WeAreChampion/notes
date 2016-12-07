#include<iostream>
#include<string>
using namespace std;
/*
	���ǰ�����ÿ��λ����ӣ����Ƿ�С��10���Ǿ���������������
	һ������n��������k = (sum - 1) % 9 + 1;
*/
int getSum(int n)
{
	int sum = 0;
	while(n != 0) {
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}
int main()
{
	int sum, i;
	string s;
	while(cin>>s)
	{
		if(s.size() == 1 && s[0] == '0') {
			break;
		}
		sum = 0;
		for(i = 0; i < s.size(); i++) {
			s[i] -= '0';
			sum += s[i];
		}
		while(sum >= 10) {
			sum = getSum(sum);
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
Input:
24
39
0
Output:
6
3
*/