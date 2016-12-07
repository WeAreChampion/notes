#include<iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int flag[100], s[100], f[5];
long target;//Ŀ��ֵ 
/*
	ö�ٷ�:
	Ѱ����Ӧ���ַ���������Ӧ���ʽ��ֵ 
*/
#define res(v, w, x, y, z) v - w * w + x * x * x - y * y * y * y + z * z * z * z * z
int dfs(int step, int len, int n)
{
	//�ݹ����Or���ڣ��ҵ�5������ֱ�ӷ��� 
	if(step == 5) {
		//������ʽ��ֵ���򷵻�1�����򷵻�0 
		if(res(f[0], f[1], f[2], f[3], f[4]) == n) {
			return 1;
		}  
  		return 0;
    }
    for(int i = len; i >= 0; i--) {
    	//has selected
		if(flag[i]) {
           	continue;
  		}
  		//To mark the element has selected
	    flag[i] = 1;
	    //save into the result array
	    f[step] = s[i];
	    //�ݹ�����������һ�������򷵻�1�����򷵻�0 
	    if(dfs(step + 1, len, n)) { 
	    	return 1;
	    } 
	    //recall���� 
	    flag[i] = 0;
    }
    return 0;
}
int main()
{
	char str[50];
    while(scanf("%d%s", &target, str) != EOF) {
		if(target == 0 && strcmp(str, "END") == 0) {
			break;
		}
		int len = 0;
		while(str[len]) {
			//To change the char to number
			s[len] = str[len] - 'A' + 1;
			//reset mark by 0
			flag[len] = 0;
			len++;
		}
		//sort
		sort(s, s + len);
		if(dfs(0, len - 1, target)) {
			//To change the number to char
			for(int i = 0 ; i < 5; i++) {
				printf("%c",f[i] + 'A' -1);
			}
			cout<<endl;
		}
		else { 
         	puts("no solution");
	 	}      
    }
    return 0;
}
/*
Sample Input:
1 ABCDEFGHIJKL
11700519 ZAYEXIWOVU
3072997 SOUGHT
1234567 THEQUICKFROG
0 END

Sample Output:
LKEBA
YOXUZ
GHOST
no solution

*/