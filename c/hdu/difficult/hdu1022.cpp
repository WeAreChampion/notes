#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
const int Stacksize = 100;
const int INCREMENT = 50;
typedef struct
{
    char *top; //存储字符值指针 
    char *base;//数组
    int stacksize;//栈长 
}Stack;
int main()
{
    int a[1000];
    int i, k, count;
    Stack S;
    int n;
    string s1, s2;
    while(cin>>n>>s1>>s2)//输入n和字串 
    {
        memset(a, 0, sizeof(a));//快速设置数组的值 
        S.base = (char*) malloc(Stacksize * sizeof(char));//开辟空间 
        //分配不成功 
		if(!S.base) {
        	return 0;
		}
        S.top = S.base;//存储基值 
        S.stacksize = Stacksize;//赋值 
        i = k = count = 0;
        while(k < n) {
            if(S.top - S.base >= S.stacksize) {//存储空间不够，继续分配 
                S.base = (char *) malloc((S.stacksize + INCREMENT) * sizeof(char)); 
                if(!S.base) { 
                	return 0;
                }
                S.top = S.base + S.stacksize;//改变相应的值 
                S.stacksize += INCREMENT;
            }
            if(S.base == S.top) {//如栈为空，进栈
                *S.top = s1[i];
                a[count++] = 1;	//标记 
                i++;			//指针下移 
                S.top++;		//更改栈顶 
            } else {
                if(*(S.top - 1) == s2[k]) {//出栈
                    S.top--;
                    k++;		//k下指 
                    count++;	//计数 
                } else {
                    if(i == n) {//如果i已经等于n了表示结束
                    	break;
                    }
                    *S.top = s1[i];	//else继续进栈
                    S.top++;
                    i++;
                    a[count++] = 1;
                }
            }
        }
        if(S.top == S.base) {//栈空 
            cout<<"Yes.\n";
            for(i = 0; i < count; i++) {
                if(a[i]) {
                	cout<<"in\n";
                }
                else {
                	cout<<"out\n";
                }
            }
            cout<<"FINISH\n";
        }
        else {
        	cout<<"No.\nFINISH\n";
        }
        free(S.base);//释放空间 
    }
    return 0;
}
/*
3 123 321
3 123 312
Sample Output
Yes.
in
in
in
out
out
out
FINISH
No.
FINISH
*/