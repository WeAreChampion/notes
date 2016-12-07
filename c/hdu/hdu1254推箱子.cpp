#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
/*
Input
�������ݵĵ�һ����һ������T(1<=T<=20),����������ݵ�����.
Ȼ����T���������,ÿ��������ݵĵ�һ��������������M,N(2<=M,N<=7),
������Ĵ�С,Ȼ����һ��M��N�еľ���,������Ĳ���,����
0����յĵذ�,1����ǽ,2�������ӵ���ʼλ��,3��������Ҫ����
ȥ��λ��,4������˹�����ʼλ��.
 
Output
����ÿ���������,������˹�������Ҫ�ƶ����Ӷ��ٸ���ܰ���
���Ƶ�ָ��λ��,��������Ƶ�ָ��λ�������-1
������Ҫ���Ƶ����㣺
1.����ǰ��û���ϰ��
2.���Ӻ�û���ϰ��
3.���ܵ������Ӻ��档
����һ��Ҫע�⣬���������߹��ĵط�����ʱ���Եģ���Ϊ��Щʱ��
������Ҫ�Ȱ����������ƣ��˲����ƶ������Ӻ��棬��������ǰ�ƣ�
���������Ǿ�Ҫ�з����ˣ�֮ǰ����ûע�⣬һֱWA�������ŷ��֡�
*/
int xx[8] = {-1, 0, 1, 0, -1, 0, 1, 0};
int yy[8] = {0, -1, 0, 1, 0, -1, 0, 1};
//map[][][]��ά���飬��¼����(x,y)����ͷ���
bool map[10][10][5];    
int a[10][10], b[10][10], c[10][10];
int x1, y1, x2, y2, tx, ty, px, py, ax, ay;
int N, M;
bool flag;
struct node
{
	//�ֱ𱣴����ӵ�����(x,y)���˵�����(px,py)������step 
    int x, y, px, py, step; 
}n, m;
//���ѣ��ж����Ƿ��ܹ��������ӵĺ���
bool dfs(int x, int y)  
{
    if(x == tx && y == ty) {
    	return true;     //�������Ӻ���
    }	
    if(x < 0 || x >= N || y < 0 || y >= M){
    	return false;    //Խ��ķ���false
    } 
    if(x == ax && y == ay){
		return false;    //�õ������ӵ�ס·��
    }
    if(b[x][y] == 1){
    	return false;          //�õ���ǽ�ڵ�ס·��
    } 
    b[x][y] = 1;    //�߹��ı�ǲ�������
    return (dfs(x+1,y) || dfs(x-1,y) || dfs(x,y+1) || dfs(x,y-1));  //��������
}

void set_bc()   //��ʼ������ʱ�õ�������b[][]
{
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            b[i][j] = c[i][j];
}

int main()
{
    int i, j, k, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &N, &M);
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                cin>>a[i][j];
                c[i][j] = b[i][j] = a[i][j];
                if(a[i][j] == 2)
                    x1 = i, y1 = j;     //���ӵ�����
                if(a[i][j] == 3)
                    x2 = i, y2 = j;     //Ŀ�������
                if(a[i][j] == 4)
                    px = i, py = j;     //�˵�����
				for(k = 0; k < 4; k++)
					map[i][j][k] = false;   //��ʼ��map[][][]
            }
        }
        flag = false;
        n.x = x1; n.y = y1; n.step = 0; //���µ�һ��push��ȥ�ĵ�
        n.px = px; n.py = py;
        queue<node> Q;
        Q.push(n);
        while(!Q.empty())
        {
            m = Q.front();
            Q.pop();
            if(m.x == x2 && m.y == y2)  //���ӵ���Ŀ��
            {
                flag = true;
                break;
            }
            for(i = 0; i < 4; i++)
            {
                n.x = m.x + xx[i];	//�������ӵ�λ��
                n.y = m.y + yy[i];
                //i+2 �պ������ӵķ�����λ��
				tx = m.x + xx[i+2];	//�����˵�λ��
                ty = m.y + yy[i+2];
				ax = m.x;		//ԭ�����ӵ�λ��
				ay = m.y;
				n.px = m.px;    //ԭ���˵�λ��
				n.py = m.py;
				n.step = m.step + 1;
                if(n.x>=0 && n.x<N && n.y>=0 && n.y<M && !map[n.x][n.y][i] && a[n.x][n.y]!=1)   //����ǰ��û����
                {
                    set_bc();   //��ʼ��b[][]����
                    if(tx>=0 && tx<N && ty>=0 && ty<M && a[tx][ty]!=1 && dfs(n.px, n.py))   //���ܵ������ӵĺ�
                    {
                        //���������Ƶ��õ�(n.px,n.py)
                        n.px = tx; n.py = ty;
                        map[n.x][n.y][i] = true;    //��Ǹõ���������i����
                        Q.push(n);
                    }
                }
            }
        }
        if(flag) printf("%d\n", m.step);
        else printf("-1\n");
    }

    return 0;
}
/*
Sample Input
1
5 5
0 3 0 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0
Sample Output
4
*/