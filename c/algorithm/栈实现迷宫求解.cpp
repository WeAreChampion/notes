/**
 * 下面是用穷举法来走迷宫
 * 走迷宫的规则：当前坐标是(i,j)下一步可以往四个方向行走，上下左右
 *
 *    在迷宫数组 0标识可以走，1标识不能走 2 标识已经走过 3标识回退的路
 *
 *
 *
 * 穷举法走出迷宫有两种方法：
 *     1 栈
 *     2 递归
 *
 *
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int x;
    int y;
    struct stack *next;
}*plink;
/**
 * 入栈
 */
plink push(plink s,int x, int y)
{
    plink new_node;
    new_node = (plink)malloc(sizeof(stack));
    if(!new_node){
        printf("内存已满");
        exit(-1);
    }
    new_node->x = x;
    new_node->y = y;
    if(s!=NULL)
    {
	    s->next = new_node;
	    s = new_node;
    }
    else
    {
    	s=new_node;
    }
    return s;
}

/**
 * 出栈
 */
plink pop(plink s,int *x,int *y)
{
    plink top;

    //队列不为空
    if(s!= NULL){
        top = s;
        s = s->next;
        *x = s->x;
        *y = s->y;
        free(top);
    }else{
        *x = -1;
    }
    return s;
}
/**
 * 用栈的回溯控制实现迷宫
 *
 *    如果没有到出口,探索如下四个方位
 *        (x-1,y)且 x,y>0
 *        (x+1,y)且 x,y>0
 *        (x,y-1)且 x,y>0
 *        (x,y+1)且 x,y>0
 *
 *      {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1,1,1},
        {1,0,1,1,1,1,1,0,0,1},
        {1,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,1,0,1,1,1,1},
        {1,1,1,1,0,0,1,1,1,1},
        {1,0,0,0,0,1,1,1,1,1},
        {1,0,1,1,0,0,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
 *
 */
void stack_maze(int a[][10],plink s,int x,int y)
{
    int i,j;
    //把出口设定为(1,1)
    while(x > 1 || y > 1){//循环的条件 
        a[x][y] = 2;
        //这条路可行
        if(a[x-1][y] <= 0){
            x = x-1;
            s = push(s,x,y);
        }else if(a[x+1][y] <= 0){
            x = x+1;
            s = push(s,x,y);
        }else if(a[x][y-1] <= 0){
            y = y-1;
            s = push(s,x,y);
        }else if(a[x][y+1] <= 0){
            y = y+1;
            s = push(s,x,y);
        }else{
            a[x][y] = 3;//不可行，出栈，并置路标为3 
            s = pop(s,&x,&y);
        }
    }
    //标记最后一点，输出矩阵 
    a[x][y] = 2;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}
//main方法
int main()
{
    int i,j;
    //用于回溯的栈
    plink s;
    //设置迷宫，最外围1为墙 里边0为可走路径 1为障碍
    int migong[10][10] =
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
	
    printf("before walk on the maze:\n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++){
            printf("%d",migong[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("we start walk on the maze\n");
    stack_maze(migong,s,8,8);
	return 0;
}
