#include<iostream>
using namespace std;
int main()
{
	char ch;
	while((ch = getchar()) != EOF) {
		if(ch != '\n') {
			if(ch == 'b') { 
				cout<<" ";
			} 
			else if(ch == 'q') { 
				cout<<",";
			} 
			else if(ch == 't') { 
				cout<<"!";
			} 
			else if(ch == 'm') { 
				cout<<"l";
			} 
			else if(ch == 'i') { 
				cout<<"e";
			} 
			else if(ch == 'c') { 
				cout<<"a";
			} 
			else if(ch == 'a') { 
				cout<<"c";
			} 
			else if(ch == 'e') { 
				cout<<"i";
			} 
			else if(ch == 'l') { 
				cout<<"m";
			} 
			else { 
				cout<<ch;
			} 
		} else {
			cout<<endl;
		}
	}
	return 0;
}
/*
Sample Input
pmicsibforgevibliqbscrct
ebmovibyout

Sample Output
please forgive me, sara!
i love you!

*/