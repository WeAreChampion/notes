//BFS+���ȶ��У���ӡ·����
/*
������ҵ�·��, Ҫ������ʱ���ڵ�·����Ϣ.
Ϊ�˷������·��, ���յ㿪ʼBFS, ������̵�·��,
ÿ��λ��Ԫ����, ��¼ǰһ��λ�õ���Ϣ, ���������
���(0, 0) �� (�յ�)�����·��.
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
const int ROW = 101;
const int COL = 101;
const int DIRS = 4;
struct priNode {
   int x, y, time;
   friend bool operator < (priNode a, priNode b) {
      return a.time > b.time;
   }
};

struct path { //�洢·��
   int x, y, time;
}path[ROW][COL];
char map[ROW][COL];
int dir[DIRS][2] = {-1,0,0,1,1,0,0,-1};
bool inMap(int pi, int pj, int row, int col);
bool bfs(int pi, int pj, int row, int col, int *times);
void printPath(int times, int pi, int pj);

int main() 
{
   int n, m;
   int i, j, k;
   while (scanf("%d%d", &n, &m) != EOF) {
      for (i=0; i<n; ++i) {
         scanf("%s", map[i]);
      }
      int times = 0;
      if (bfs(0, 0, n, m, &times)) {
         printf("It takes %d seconds to reach the target position, let me show you the way.\n", times);
         printPath(times, n-1, m-1);
      }else {
         printf("God please help our poor hero.\n");
      }
      printf("FINISH\n");
   }

   return 0;
}
bool inMap(int pi, int pj, int row, int col) {
   return (pi>=0 && pi<row && pj>=0 && pj<col);//true or false
}
bool bfs(int pi, int pj, int row, int col, int *times) {
   int i;
   priNode now, next;
   priority_queue<priNode> Q;
   now.x = pi;
   now.y = pj;
   now.time = 0;
   Q.push(now);
   path[0][0].x = -1;  //��ʼ����ǰ���ڵ�
   path[0][0].y = -1;
   path[0][0].time = 0;  
   while (!Q.empty()) {
      now = Q.top();
      Q.pop();
      if (now.x == row-1 && now.y == col-1) {  //����Ŀ�ĵ�
         *times = now.time;
         return true;
      }         
      for (i=0; i<DIRS; ++i) {//use the direction array (ditr[])
         next.x = now.x + dir[i][0];//change the direction
         next.y = now.y + dir[i][1];
         if (inMap(next.x, next.y, row, col)) {	//in the map
            if (map[next.x][next.y] == '.') {	//can go
               next.time = now.time + 1; 		//time++;
               Q.push(next);					//push
               path[next.x][next.y].x = now.x;  //��¼·��,ǰ���ڵ�
               path[next.x][next.y].y = now.y;
               path[next.x][next.y].time = 0;
               map[next.x][next.y] = 'X';		//change the way
            }else if (map[next.x][next.y] != 'X') {
               next.time = now.time + (map[next.x][next.y] - '0') + 1; //���ʱ�䣫����ʱ��
               Q.push(next);
               path[next.x][next.y].x = now.x;  //��¼·��,ǰ���ڵ�
               path[next.x][next.y].y = now.y;
               path[next.x][next.y].time = map[next.x][next.y] - '0';
               map[next.x][next.y] = 'X';
            }
         }
      }
   }
   return false;
}
void printPath(int times, int px, int py) {  //�ݹ��ӡ·��
   if (times > 0) {
      if (path[px][py].time-- != 0) {    //���
         printPath(times-1, px, py);
         printf("%ds:FIGHT AT (%d,%d)\n", times--, px, py);
      }else {
         printPath(times-1, path[px][py].x, path[px][py].y);
         printf("%ds:(%d,%d)->(%d,%d)\n", times--, path[px][py].x, path[px][py].y, px, py);
      }
   }
}
/*
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX.
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX1
5 6
.XX...
..XX1.
2...X.
...XX.
XXXXX.
*/