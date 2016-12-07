#include<iostream>
using namespace std;
#define  SIZE  16    //宏定义棋盘的大小
int   board[SIZE][SIZE]  ;   //全局变量
int chessboard(int tr,int tc, int dr, int dc, int size);
void main()
{
    int tr = 0,tc = 0;
	int dr,dc;
	cout<<"特殊棋子的列号：dr = ";
    cin>>dr;
	cout<<"特殊棋子的行号：dc = ";
	cin>>dc;
	chessboard(tr,tc,dr,dc,SIZE);
	for(int i = 0;i < SIZE; ++ i)
	{
	    for(int j = 0;j < SIZE;++ j)
		{
		    //cout<<board[i][j]<<"  ";
			printf("%-2d ",board[i][j]);   //控制字符输出格式
		}
		cout<<endl;
	}
}

int chessboard(int tr,int tc, int dr, int dc, int size)
{
	if(size == 1) return 0;
    int s,t;
	static int tile = 0;     //将tile申请为静态变量，以便储存tile随时改变的值
	t = tile ++;
	s = size / 2;
	if(dr < tr+ s && dc < tc +s)
	{
	   chessboard(tr,tc,dr,dc,s);
	}
	else
	{
	    board[tr + s - 1][tc + s - 1] = t;
		chessboard(tr,tc,tr + s -1,tc + s - 1,s);
	}
        //覆盖左上角
	if(dr < tr+ s && dc >= tc +s)
	{
	   chessboard(tr,tc + s,dr,dc,s);
	}
	else
	{
	    board[tr + s - 1][tc + s] = t;
		chessboard(tr,tc + s,tr + s -1,tc + s,s);
	}
    //覆盖棋盘右上角
	if(dr >= tr+ s && dc < tc +s)
	{
	   chessboard(tr + s,tc,dr,dc,s);
	}
	else
	{
	    board[tr + s][tc + s - 1] = t;
		chessboard(tr + s,tc,tr + s,tc + s - 1,s);
	}
                //覆盖棋盘左下角
	if(dr >= tr+ s && dc >= tc +s)
	{
	   chessboard(tr + s,tc + s,dr,dc,s);
	}
	else
	{
	    board[tr + s][tc + s] = t;
		chessboard(tr + s,tc + s,tr + s,tc + s,s);
	}
	//覆盖棋盘右下角
	return  1;
}
