#include<stdio.h>
#include<math.h>
/*
	小虎发明了一个计划生育方案：每对夫妇最多生M个孩子，超生的要罚款，但是
在这M个孩子里，如果生了男孩，就不能再生了，否则超生的也要罚款。罚款的数额和超生
个数有关，超生一个罚款10000元，超生第二个20000元，超生第三个40000元，每次都是
上一个的2倍。现在给你一对父母生的孩子个数N和最多生孩子个数M，以及N个孩子的性别。
求：她们要交多少钱的罚款。
思路：先求M个孩子里有木有男孩，有的话，从下一个孩子开始算超生的罚款，没有的话，就
从第M+1个孩子开始计算罚款。计算罚款的时候先按1、2、4元计算，输出的时候，在输出字
符串"0000"，这样避免了数据溢出，注意答案为0的时候，不必再输出字符串。
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[33];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N,M;
        cin >> M >> N;
        for(int i = 0; i < N; ++i)
            cin >> a[i];
        int ans = 0,pos = -1,Num;
        for(int i = 0; i < M; ++i)
            if(a[i] == 1)
            {
				//mark the value 1 index that means the boy children first
                pos = i;
                break;
            }
		
		// have find the boy children
        if(pos != -1)
        {
            Num = 1;
            for(int i = pos + 1; i < N; ++i)
            {
                ans += Num;
                Num *= 2;
            }
        }
        else
        {
            Num = 1;
            for(int i = M; i < N; ++i)
            {
                ans += Num;
                Num *= 2;
            }
        }
		//输出控制，避免溢出
        if(ans != 0)
            cout << ans << "0000 RMB" << endl;
        else
            cout << "0 RMB" << endl;
    }

    return 0;
}
/*
Sample Input
2
2 5
0 0 1 1 1
2 2
0 0
 

Sample Output
70000 RMB
0 RMB
*/