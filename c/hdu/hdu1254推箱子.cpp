#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
/*
Input
输入数据的第一行是一个整数T(1<=T<=20),代表测试数据的数量.
然后是T组测试数据,每组测试数据的第一行是两个正整数M,N(2<=M,N<=7),
代表房间的大小,然后是一个M行N列的矩阵,代表房间的布局,其中
0代表空的地板,1代表墙,2代表箱子的起始位置,3代表箱子要被推
去的位置,4代表搬运工的起始位置.
 
Output
对于每组测试数据,输出搬运工最少需要推动箱子多少格才能帮箱
子推到指定位置,如果不能推到指定位置则输出-1
推箱子要能推的三点：
1.箱子前方没有障碍物；
2.箱子后方没有障碍物；
3.人能到达箱子后面。
还有一点要注意，箱子曾经走过的地方再走时可以的，因为有些时候
推箱子要先把箱子往后推，人才能移动到箱子后面，让箱子向前推，
所以这个标记就要有方向了，之前这里没注意，一直WA，后来才发现。
*/
int xx[8] = {-1, 0, 1, 0, -1, 0, 1, 0};
int yy[8] = {0, -1, 0, 1, 0, -1, 0, 1};
//map[][][]三维数组，记录箱子(x,y)坐标和方向
bool map[10][10][5];    
int a[10][10], b[10][10], c[10][10];
int x1, y1, x2, y2, tx, ty, px, py, ax, ay;
int N, M;
bool flag;
struct node
{
	//分别保存箱子的坐标(x,y)、人的坐标(px,py)、步数step 
    int x, y, px, py, step; 
}n, m;
//深搜：判断人是否能够到达箱子的后面
bool dfs(int x, int y)  
{
    if(x == tx && y == ty) {
    	return true;     //到达箱子后面
    }	
    if(x < 0 || x >= N || y < 0 || y >= M){
    	return false;    //越界的返回false
    } 
    if(x == ax && y == ay){
		return false;    //该点是箱子挡住路了
    }
    if(b[x][y] == 1){
    	return false;          //该点是墙壁挡住路了
    } 
    b[x][y] = 1;    //走过的标记不能再走
    return (dfs(x+1,y) || dfs(x-1,y) || dfs(x,y+1) || dfs(x,y-1));  //往内深搜
}

void set_bc()   //初始化深搜时用到的数组b[][]
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
                    x1 = i, y1 = j;     //箱子的坐标
                if(a[i][j] == 3)
                    x2 = i, y2 = j;     //目标的坐标
                if(a[i][j] == 4)
                    px = i, py = j;     //人的坐标
				for(k = 0; k < 4; k++)
					map[i][j][k] = false;   //初始化map[][][]
            }
        }
        flag = false;
        n.x = x1; n.y = y1; n.step = 0; //更新第一个push进去的点
        n.px = px; n.py = py;
        queue<node> Q;
        Q.push(n);
        while(!Q.empty())
        {
            m = Q.front();
            Q.pop();
            if(m.x == x2 && m.y == y2)  //箱子到达目标
            {
                flag = true;
                break;
            }
            for(i = 0; i < 4; i++)
            {
                n.x = m.x + xx[i];	//后来箱子的位置
                n.y = m.y + yy[i];
                //i+2 刚好是箱子的反方向位置
				tx = m.x + xx[i+2];	//后来人的位置
                ty = m.y + yy[i+2];
				ax = m.x;		//原来箱子的位置
				ay = m.y;
				n.px = m.px;    //原来人的位置
				n.py = m.py;
				n.step = m.step + 1;
                if(n.x>=0 && n.x<N && n.y>=0 && n.y<M && !map[n.x][n.y][i] && a[n.x][n.y]!=1)   //箱子前方没问题
                {
                    set_bc();   //初始化b[][]数组
                    if(tx>=0 && tx<N && ty>=0 && ty<M && a[tx][ty]!=1 && dfs(n.px, n.py))   //人能到达箱子的后方
                    {
                        //则箱子能推倒该点(n.px,n.py)
                        n.px = tx; n.py = ty;
                        map[n.x][n.y][i] = true;    //标记该点和来的这个i方向
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