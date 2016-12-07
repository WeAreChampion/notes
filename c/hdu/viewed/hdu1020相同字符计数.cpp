#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	//cin>>n;
	while(n--) {
		//string s;
		//s = "";
		char s[10001];
		scanf("%s", s);
		int i, count = 1;
		int length = strlen(s);
		for(i = 0; i < length; i++)
		{
			if(s[i] == s[i+1]) { 
				count++;
			} 
			else {
				if(count == 1) { 
					printf("%c", s[i]);
				} 
				else {
					printf("%d%c", count, s[i]);
					count = 1;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
