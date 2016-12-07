#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
bool r( int x ) {
    return x >= 0 && x <= 255 ? 1 : 0;
}

int main()
{
    char ip[105];
    while(gets( ip )) {
        int a, b, c, d, len = strlen( ip ), flag = 0;
		//if have + or length beyond 15(3*4+3)
        if(strchr( ip, '+' ) || strlen( ip ) > 15) {
            puts( "NO" );
            continue;
        }
        char tail;
		// deal with the ip divided by char '.'
        if(sscanf(ip, "%d.%d.%d.%d%c", &a, &b, &c, &d, &tail) == 4 ) {
            if(r(a) && r(b) && r(c) && r(d)) 
                puts( "YES" ); 
            else
                puts( "NO" ); 
        }
        else
            puts( "NO" );
    }
    return 0;
}
/*
Sample Input
192.168.100.16
 

Sample Output
YES
*/