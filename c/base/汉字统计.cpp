#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--) {
		char ch;
		int count = 0;
		getchar();
		while((ch = getchar()) != '\n') {
			//�ַ�ֵС��0 
			if(ch < 0) { 
				count++;
			} 
		}
		cout<<(count + 1) / 2<<endl;
	}
	return 0;
}
/*
2
WaHaHa! WaHaHa! ������ڲ�˵��Ҫ˵ֻ˵��ͨ��WaHaHa! WaHaHa!
���Ͼ�Ҫ��ĩ������Are you ready?
*/