#include<iostream>
using namespace std;
#define  SIZE  16    //�궨�����̵Ĵ�С
int   board[SIZE][SIZE]  ;   //ȫ�ֱ���
int chessboard(int tr,int tc, int dr, int dc, int size);
void main()
{
    int tr = 0,tc = 0;
	int dr,dc;
	cout<<"�������ӵ��кţ�dr = ";
    cin>>dr;
	cout<<"�������ӵ��кţ�dc = ";
	cin>>dc;
	chessboard(tr,tc,dr,dc,SIZE);
	for(int i = 0;i < SIZE; ++ i)
	{
	    for(int j = 0;j < SIZE;++ j)
		{
		    //cout<<board[i][j]<<"  ";
			printf("%-2d ",board[i][j]);   //�����ַ������ʽ
		}
		cout<<endl;
	}
}

int chessboard(int tr,int tc, int dr, int dc, int size)
{
	if(size == 1) return 0;
    int s,t;
	static int tile = 0;     //��tile����Ϊ��̬�������Ա㴢��tile��ʱ�ı��ֵ
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
        //�������Ͻ�
	if(dr < tr+ s && dc >= tc +s)
	{
	   chessboard(tr,tc + s,dr,dc,s);
	}
	else
	{
	    board[tr + s - 1][tc + s] = t;
		chessboard(tr,tc + s,tr + s -1,tc + s,s);
	}
    //�����������Ͻ�
	if(dr >= tr+ s && dc < tc +s)
	{
	   chessboard(tr + s,tc,dr,dc,s);
	}
	else
	{
	    board[tr + s][tc + s - 1] = t;
		chessboard(tr + s,tc,tr + s,tc + s - 1,s);
	}
                //�����������½�
	if(dr >= tr+ s && dc >= tc +s)
	{
	   chessboard(tr + s,tc + s,dr,dc,s);
	}
	else
	{
	    board[tr + s][tc + s] = t;
		chessboard(tr + s,tc + s,tr + s,tc + s,s);
	}
	//�����������½�
	return  1;
}
