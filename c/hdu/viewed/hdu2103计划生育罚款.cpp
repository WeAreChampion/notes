#include<stdio.h>
#include<math.h>
/*
	С��������һ���ƻ�����������ÿ�Է������M�����ӣ�������Ҫ�������
����M���������������к����Ͳ��������ˣ���������ҲҪ������������ͳ���
�����йأ�����һ������10000Ԫ�������ڶ���20000Ԫ������������40000Ԫ��ÿ�ζ���
��һ����2�������ڸ���һ�Ը�ĸ���ĺ��Ӹ���N����������Ӹ���M���Լ�N�����ӵ��Ա�
������Ҫ������Ǯ�ķ��
˼·������M����������ľ���к����еĻ�������һ�����ӿ�ʼ�㳬���ķ��û�еĻ�����
�ӵ�M+1�����ӿ�ʼ���㷣����㷣���ʱ���Ȱ�1��2��4Ԫ���㣬�����ʱ���������
����"0000"���������������������ע���Ϊ0��ʱ�򣬲���������ַ�����
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
		//������ƣ��������
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