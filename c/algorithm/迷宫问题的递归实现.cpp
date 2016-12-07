/**
 * ����������ٷ������Թ�
 * ���Թ��Ĺ��򣺵�ǰ������(i,j)��һ���������ĸ��������ߣ���������
 *��(i,j)->(i-1,j)
 *��(i,j)->(i+1,j)
 *��(i,j)->(i,j-1)
 *��(i,j)->(i,j+1)
 * ���Թ����� 0��ʶ�����ߣ�1��ʶ������ 2 ��ʶ�Ѿ��߹� 3��ʶ���˵�·
 *
 * ��ٷ��߳��Թ������ַ�����
 *     1 ջ
 *     2 �ݹ�
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
//�õݹ�ʵ���Թ�����
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
//main����
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


