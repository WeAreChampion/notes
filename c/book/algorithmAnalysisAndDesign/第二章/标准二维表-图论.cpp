#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM 128

/* 定义图的类型 */
typedef struct {
	/* 图中的顶点*/
	int vex[NUM];
	/* 图中的边     */
	int arcs[NUM][NUM];
	/* 顶点数，边数 */
	int vexnum,arcnum;
} MGraph;

/*
	把图定义为全局变量
*/
MGraph G;

/**
	标志数组
*/
int   x[NUM] = {0};
int m_number;
int sum = 0;

/* 造图函数*/
void CreateUDN(int v,int a);

/* 哈密尔顿图的遍历 */
void   HaMiTonian(int);

void   NextValue(int);

/* 显示遍历结果       */
void   display();

/* 判断所构建的二维表是否满足条件 */
int Check_Array( int m_array[] );

void main()
{
	system("color fc");

	printf("输入一个正整数：");
	int tmp;
	scanf("%d", &tmp);
	m_number = 2 * tmp;

	CreateUDN(m_number, m_number);
	x[1] = 1;
	HaMiTonian(0);

	printf("/n/n%d的二维表的个数有：%d/n", tmp, sum);
	system("pause");
}
/* 造图函数 */
void CreateUDN( int v, int a )
{
	int i, j;

	/* 初始化图的顶点数和边数  */
	G.vexnum = v;
	G.arcnum = a;

	/* 初始化每一个顶点的编号  */
	for( i=0; i < G.vexnum; i++ ) {
		G.vex[i] = i + 1;
	}

	/* 设置为全连通图          */
	for( i=0; i < G.vexnum; i++ ) {
		for( j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = 1;
		}
	}
}
/* 哈密尔顿图的遍历 */
void HaMiTonian( int m )
{
	if( m > m_number - 1 ) {
		return;
	}

L:
	NextValue( m );
	if( 0 == x[m] ) {
		return;
	}
	if( (m == m_number - 1) && (0 != G.arcs[0][x[m_number-1] - 1]) ) {
		display();
	} else {
		HaMiTonian( m + 1 );
	}
	goto L;
}

void NextValue(int k)
{
	int j;
l:
	x[k] = (x[k] + 1) % (m_number + 1);
	if( 0 == x[k] ) {
		return;
	}
	if( 0 != G.arcs[x[k-1] -1 ][x[k] - 1] ) {
		for( j = 0; j < k; j++ ) {
			if( x[j] == x[k] ) {
				goto l;
			}
		}
		return;
	} else {
		goto l;
	}
}

void display()
{
	int i = 0;
	int m_array[NUM];

	for( i = 0; i < m_number; i++ ) {
		m_array[i] = G.vex[x[i] - 1];
	}

	if( Check_Array( m_array ) ) {
		for( i = 0; i < m_number; i++ ) {
			printf( "%d ", m_array[i] );
		}
		sum++;
		printf("/n");
	}
}

/* 判断所构建的二维表是否满足条件 */
int Check_Array(int m_array[])
{
	int half = m_number / 2;

	for(int i = 0; i < half - 1; i++) {
		if( m_array[i] > m_array[i + 1] ) {
			return 0;
		}

	}
	for(int i = half; i < m_number - 1; i++) {
		if( m_array[i] > m_array[i + 1] ) {
			return 0;
		}
	}
	for(int i = 0; i < half; i++) {
		if( m_array[i] > m_array[half + i] ) {
			return  0;
		}
	}
	return 1;
}