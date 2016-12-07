#include <iostream>
#include <iomanip>
using namespace std;
/*
	16进制的加减法，利用C++的iomanip库进行运算即可。 
*/
int main()
{
    long long a, b, c;
    while(cin>> hex >> a >> b) {
       	c = a + b;
       	if(c < 0) {
          	c = -c;
          	//在以科学计数法输出E与十六进制输出X以大写输出，否则小写。
          	cout<<'-'<<setiosflags(ios::uppercase)<<hex<<c<<endl;
		}
		else {
			//
			cout<<setiosflags(ios::uppercase)<<hex<<c<<endl;
       	}
    }
    return 0;
}
/*
Sample Input
+A -A
+1A 12
1A -9
-1A -12
1A -AA

Sample Output
0
2C
11
-2C
-90

*/