#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

int xx[4] = {1, 0, -1, 0};
int yy[4] = {0, 1, 0, -1};

int step[25][25][1025];
char map[25][25];
int n, m, t;
int bx, by;

int pow(char ch)    //Կ��״̬��ֵ
{
    int i, n, ans = 1;
    if(ch >= 'a' && ch <= 'j') 
		n = ch - 'a';
    else 
		n = ch - 'A';
    for(i = 1; i <= n; i++)
    {
        ans *= 2;
    }
    return ans;
}

void init()     //��ʼ��
{
    int i, j, k;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            for(k = 0; k < 1025; k++)
                step[i][j][k] = 99999999;
}

struct node
{
    int x, y, step;
    int status;
}tp, tq;

int bfs()   //BFS����
{
    int i;
    char ch;
    queue<node> Q;
    tq.x = bx;
    tq.y = by;
    tq.step = tq.status = 0;
    step[tq.x][tq.y][tq.status] = 0;
    Q.push(tq);
    while(!Q.empty())
    {
        tp = Q.front();
        Q.pop();
        if(map[tp.x][tp.y] == '^')
        {
            return tp.step;
        }
        for(i = 0; i < 4; i++)
        {
            tq.x = tp.x + xx[i];
            tq.y = tp.y + yy[i];
            tq.step = tp.step + 1;
            tq.status = tp.status;
            if(tq.step >= t)//�����涨ʱ�� 
				continue;  
            if(tq.x >= 0 && tq.x < n && tq.y >= 0 && tq.y < m)
            {
                //��ǰ״̬�����Ѿ�����֮ǰ�Ĳ���
                if(tq.step >= step[tq.x][tq.y][tq.status]) 
					continue;
                step[tq.x][tq.y][tq.status] = tq.step;  //���µ�ǰ״̬�Ĳ���
                ch = map[tq.x][tq.y];
                if(ch == '*') continue;     //����ǽ��
                else if(ch >= 'a' && ch <= 'j')
                {
                    //�ҵ�Կ�׾Ͳ����ټ�״̬
                    if((tq.status & pow(ch)) == 0) tq.status += pow(ch);
                    Q.push(tq);
                }
                else if(ch >= 'A' && ch <= 'J')
                {
                     //���û����Ӧ��Կ�ף��Ͳ��ܼ�����
                    if((tq.status & pow(ch)) == 0) continue;
                    Q.push(tq);
                }
                else
                {
                    Q.push(tq);
                }
            }
        }
    }
    return -1;
}

int main()
{
    int i, j, res;
    while(scanf("%d %d %d", &n, &m, &t) != EOF)
    {
        init();
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == '@')
                {
                    bx = i;
                    by = j;
                }
            }
        }
        res = bfs();
        printf("%d\n", res);
    }

    return 0;
}
