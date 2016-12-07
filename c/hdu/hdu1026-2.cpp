#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	/*
		The pos contains x and y.
	*/
	int x, y;
	/*
		The step you have walked.
	*/
	int step;
	friend bool operator<(node n1,node n2)
	{
		return n2.step < n1.step;
	}
};
/*
	The direction about the walker to walk including UP, RIGNT, DOWN, LEFT.
*/
int dir[4][2]={0,1, 1,0, 0,-1, -1,0};
int map[111][111];
int flag[111][111];
int blood[111][111];
int n, m;

int judge(int x, int y)
{
	/*
		The boundary about the map.
		If you arrive the boundary then return 1, that means the pos can't go through.
	*/
	if(x < 0 || x >= n || y < 0 || y >= m)
		return 1;
	/*
		If the pos has marked can't go through then return 1.
	*/
	if(map[x][y] == -1)
		return 1;
	
	/*
		The pos can go through and return 0.
	*/
	return 0;
}
int BFS()
{
	priority_queue<node> q;
	node cur, next;
	int i;
	/*
		To init the start pos where x = 0 and y = 0.
	*/
	cur.x = 0;
	cur.y = 0;
	/*
		The step you have walked and when you start the step's value is 0. 
	*/
	cur.step = 0;
	
	/*
		To init the start pos's value is equal to 1 where x = 0 and y = 0. 
		That means the start pos is entrance but isn't a exit.
	*/
	map[0][0] = -1;
	
	/*
		To push the current node cur into the queue. 
	*/
	q.push(cur);
	/*
		while the queue is not empty that means there are ways not try.
	*/
	while(!q.empty())
	{
		/*
			To change the current pos by the queue's top node.
		*/
		cur = q.top();
		/*
			To pop the queue.
		*/
		q.pop();
		/*
			If the current node is the target pos then return the counts of step.
		*/
		if(cur.x == n - 1 && cur.y == m - 1)
			return cur.step;
		/*
			To try the four direction 
		*/
		for(i = 0; i < 4; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			/*
				If the pos can't go through then try other directions.
			*/
			if(judge(next.x,next.y))	
				continue;
			/*
				Else change the step.
			*/
			next.step = cur.step + 1 + map[next.x][next.y];
			/*
				save the direction.
			*/ 
			flag[next.x][next.y] = i + 1;
			/*
				To mark the pos has try and it can't go through.
			*/
			map[next.x][next.y] = -1;
			/*
				To push the next node into the queue
			*/ 
			q.push(next);
		}
	}
	/*
		That means don't have the exit.
	*/
	return -1;
}
int temp;
void P(int x, int y)
{
	int next_x, next_y;
	if(flag[x][y] == 0)
		return ;
	next_x = x - dir[flag[x][y] - 1][0];
	next_y = y - dir[flag[x][y] - 1][1];
	P(next_x, next_y);
	/*
		To output 
	*/
	printf("%ds:(%d,%d)->(%d,%d)\n", temp++, next_x, next_y, x, y);

	while(blood[x][y]--)
		printf("%ds:FIGHT AT (%d,%d)\n", temp++, x, y);
}

int main()
{
	char str[111];
	int i, l;
	int ans;

	while(scanf("%d%d", &n, &m) != -1)
	{
		/*
			Quick to set the array value = 0.
		*/
		memset(map, 0, sizeof(map));
		memset(flag, 0, sizeof(flag));
		memset(blood, 0, sizeof(blood));
		for(i = 0; i < n; i++)
		{
			scanf("%s", str);
			for(l = 0; str[l] ; l++)
			{
				/*
					To init the map.
				*/
				if(str[l] == '.')	
					map[i][l] = 0; // can go through
				else if(str[l] == 'X')
					map[i][l] = -1; // can't go through
				else
					map[i][l] = blood[i][l] = str[l] - '0';// save the second
			}
		}
		/*
			BFS and save the return value into ans.
		*/
		ans = BFS();
		/*
			Don't have the exit.
		*/
		if(ans == -1)	
			printf("God please help our poor hero.\n");
		else
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
			temp = 1;
			/*
				Output the path you have walked.
			*/
			P(n - 1, m - 1);
		}
		printf("FINISH\n");
	}
	return 0;
}