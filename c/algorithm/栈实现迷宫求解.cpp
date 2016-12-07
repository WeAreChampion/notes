/**
 * ����������ٷ������Թ�
 * ���Թ��Ĺ��򣺵�ǰ������(i,j)��һ���������ĸ��������ߣ���������
 *
 *    ���Թ����� 0��ʶ�����ߣ�1��ʶ������ 2 ��ʶ�Ѿ��߹� 3��ʶ���˵�·
 *
 *
 *
 * ��ٷ��߳��Թ������ַ�����
 *     1 ջ
 *     2 �ݹ�
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
 * ��ջ
 */
plink push(plink s,int x, int y)
{
    plink new_node;
    new_node = (plink)malloc(sizeof(stack));
    if(!new_node){
        printf("�ڴ�����");
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
 * ��ջ
 */
plink pop(plink s,int *x,int *y)
{
    plink top;

    //���в�Ϊ��
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
 * ��ջ�Ļ��ݿ���ʵ���Թ�
 *
 *    ���û�е�����,̽�������ĸ���λ
 *        (x-1,y)�� x,y>0
 *        (x+1,y)�� x,y>0
 *        (x,y-1)�� x,y>0
 *        (x,y+1)�� x,y>0
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
    //�ѳ����趨Ϊ(1,1)
    while(x > 1 || y > 1){//ѭ�������� 
        a[x][y] = 2;
        //����·����
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
            a[x][y] = 3;//�����У���ջ������·��Ϊ3 
            s = pop(s,&x,&y);
        }
    }
    //������һ�㣬������� 
    a[x][y] = 2;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}
//main����
int main()
{
    int i,j;
    //���ڻ��ݵ�ջ
    plink s;
    //�����Թ�������Χ1Ϊǽ ���0Ϊ����·�� 1Ϊ�ϰ�
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
