/*
����һ����target ��һ���ַ��� s�����ַ��� s 
�ҳ�һ����5���ַ���ɵ�����ַ���(max char is first)
ʹ��v - w^2 + x^3 - y^4 + z^5 = target ��
*/
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
bool visitIs[30] ,judge;
int ans[6] ,N[26] ,total;
long long target ,sum;
void set(char *a)
{
     int i ,len;
     for(i = 0 ;i < 30 ;i++)
        visitIs[i] = false;
     judge = false;
     len = strlen(a);
     sum = 0 ;
     total = -1;
     for(i = 0 ;i < len ;i++)
        N[++total] = (int)a[i] - 64;//convert char to number
     sort(N ,N + total);//quick sort
}
void solve(int n)
{
     int i ,j;
     long num;
     if(n == 6)//get five char
     {
          if(target == sum)
               judge = true;
          return ;
     }
     for(i = total ;i >= 0 ;i--)//�����ʼ 
     {
          if(visitIs[i] == false)//not visited
          {
                num = -1;
                for(j = 1 ;j <= n ;j++)//get the num^n
                    num = num * N[i] * (-1);
                sum = sum + num;
                visitIs[i] = true;//change to true
                ans[n] = N[i];//save the char
                solve(n + 1);//recursion���ݹ飩 
                if(judge == true) return ;//find the max soluion
                sum = sum - num;//go back
                visitIs[i] = false;//init flase
          }
     }
}
int main()
{
      char str[12];
      while(scanf("%lld %s",&target ,str))
      {
           string s = str;
           if(target == 0 && s == "END") break;
           else
           {
                set(str);
                solve(1);
                if(judge == true)
                     for(int i = 1 ;i <= 5 ;i++)
                         printf("%c",(char)(ans[i] + 64));
                else
                     printf("no solution");
                printf("\n");
           }
      }
}
/*
Input:
1 ABCDEFGHIJKL
11700519 ZAYEXIWOVU
3072997 SOUGHT
1234567 THEQUICKFROG
0 END
Output:
LKEBA
YOXUZ
GHOST
no solution
 */