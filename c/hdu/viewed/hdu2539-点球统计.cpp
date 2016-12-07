#include<stdio.h>
#include<string.h>
/*
因为可能会出现 数据类似这样的：aman no good  good
即一个人的名字可能是 aman no good.
但是不管是不是会有这样的数据 我们可以用一个很巧的方法:
就是从最后面去判断,即判断倒数第8个字符是不是空格
倒数第七个是不是n,第八个是不是o 第9个是不是空格
如果同时满足是 就可以断定一定是X了
*/
int main()
{
	int n, i, j, k, a[200], b[200];
    char s[211];
    while(scanf("%d", &n) != EOF && n) {
        int cnt;
        //点球场数 
        if(n % 2 == 0)	{
			cnt	= n / 2;
		} else {
			cnt = n / 2 + 1;
		}
		//快速设置数组的值为0
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
		getchar();
		int cnt1 = 0, cnt2 = 0, c1 = 0,c2 = 0;
        for(k = 0; k < n; k++) {
            int flag = 1;
			gets(s);
			int len = strlen(s);
			//is no good that means ball isn't in
			if(s[len - 8] == ' ' && s[len - 7] == 'n' && s[len - 6] == 'o' && s[len - 5] == ' ') {
				//为偶数方 
				if(k % 2 == 0) {
					a[cnt1++] = 1;
				} else {//为奇数方 
					b[cnt2++] = 1;	///1 代表no good
				}
				flag = 0;
			}
			//is good that means ball is in
			if(flag) {
				//为偶数方 
                if(k % 2 == 0) {
					c1++;
					a[cnt1++] = 0;
				} else {//为奇数方 
					c2++;
					b[cnt2++] = 0;
				}
			}
        }
        //output the ball counts and "score" in the first line
        for(i = 1; i <= cnt; i++) {
			printf("%d ", i);
		} 
        printf("Score\n");
        //out the result in the second line
        for(i = 0; i < cnt; i++) {
        	//that means the ball isn't in
            if(a[i] == 1) {
				printf("X ");
			} else {//that means the ball is in
				printf("O ");
			}
		} 
        printf("%d\n", c1);
        //out the result in the third line
        for(i = 0; i < cnt2; i++){
			if(b[i] == 1) {
				printf("X ");
			} 
            else {
				printf("O ");
			}
		} 
		if(n % 2 == 1) { 
         	printf("- ");
		} 
        printf("%d\n", c2);
    }
	return 0;
}
/*
Sample Input
6
Riise good
Ballack good
Gerrard no good
Lampard no good
Fernando Torres good
Malouda good
9
Christiano Ronaldo no good
Messi no good
Giggs good
Abidal no good
Carrick good
Ronaldinho good
Rooney good
Henry no good
Tevez good
0
 

Sample Output
1 2 3 Score
O X O 2
O X O 2
1 2 3 4 5 Score
X O O O O 4
X X O X - 1


*/