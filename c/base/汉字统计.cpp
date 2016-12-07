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
			//字符值小于0 
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
WaHaHa! WaHaHa! 今年过节不说话要说只说普通话WaHaHa! WaHaHa!
马上就要期末考试了Are you ready?
*/