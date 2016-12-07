/**
 * 下面是用穷举法来走迷宫
 * 走迷宫的规则：当前坐标是(i,j)下一步可以往四个方向行走，上下左右
 *上(i,j)->(i-1,j)
 *下(i,j)->(i+1,j)
 *左(i,j)->(i,j-1)
 *右(i,j)->(i,j+1)
 * 在迷宫数组 0标识可以走，1标识不能走 2 标识已经走过 3标识回退的路
 *
 * 穷举法走出迷宫有两种方法：
 *     1 栈
 *     2 递归
 *
 */

#include <stdio.h>

int maze[10][10] =
    {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1,1,1},
        {1,0,1,1,1,1,1,0,0,1},
        {1,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,1,0,1,1,1,1},
        {1,1,1,1,0,0,1,1,1,1},
        {1,0,0,0,0,1,1,1,1,1},
        {1,0,1,1,0,0,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
//用递归实现迷宫问题
int recuirsion_maze(int x,int y)
{
    if(x == 1 && y == 1)//arrive the start
    {
        maze[x][y] = 2;//change the value of array
        return 1; //return the type and review can't return
    }else if(maze[x][y] == 0)//the value of array is 0 can go
    {
		maze[x][y] = 2;//change the value of array
        if( (recuirsion_maze(x-1,y)+
             recuirsion_maze(x+1,y)+
             recuirsion_maze(x,y-1)+
             recuirsion_maze(x,y+1)) > 0)//default the point not can go
            return 1;
        else//the sum is 0,that means the point can go 
        {
            maze[x][y] = 0;//the value of array can go
            return 0;
        }
    }else//else can go
        return 0;
}
//main方法
int main()
{
    int i,j;
	recuirsion_maze(8,8);
	for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++){
            printf("%d",maze[i][j]);
        }
        printf("\n");
    }
	return 0;
}


