#include <iostream>
#include <iomanip>
using namespace std;
/*
	16���ƵļӼ���������C++��iomanip��������㼴�ɡ� 
*/
int main()
{
    long long a, b, c;
    while(cin>> hex >> a >> b) {
       	c = a + b;
       	if(c < 0) {
          	c = -c;
          	//���Կ�ѧ���������E��ʮ���������X�Դ�д���������Сд��
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