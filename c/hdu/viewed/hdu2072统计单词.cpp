#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
//set string collection, elements are different
set<string> temp;
int main()
{
    string row, input;
	//To get line and end with string "#"
	while(getline(cin, row) && row != "#") {  
		temp.clear();
		//new stringstream by string row
        stringstream str(row);
		
		// To get words by string input,words split by space(char ' ')
        while(str >> input) {
            temp.insert(input);
        }
		//
        cout<<temp.size()<<endl;
    }
    return 0;
}
/*
µ¥´Ê¼ÆÊý:
Sample Input
you are my friend
#
Sample Output
4
*/ 