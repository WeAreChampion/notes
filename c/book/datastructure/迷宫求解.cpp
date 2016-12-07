#include<iostream>
using namespace std;
#define N 4
#define M 4
#define MaxSize 100
int mg[M+2][N+2]={
	{1,1,1,1,1,1},
	{1,0,0,0,1,1},
	{1,0,1,0,0,1},
	{1,0,0,0,1,1},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1}};
struct {
	int i;
	int j;
	int di;
}Stack[MaxSize],Path[MaxSize];
int top = -1 ;  //the top of indicator
int count = 1 ; //the lengthe of path
int minlen = MaxSize;//init the milen
void mgpath()   //find the shortest path and length
{
	int i,j,di,find,k;
	top++;
	Stack[top].i = 1;
	Stack[top].j = 1;
	Stack[top].di = -1;	//the first push Stack
	mg[1][1] = -1;		//indicate that the rode has been query

	while(top>-1)//while the Stack isn't empty 
	{
		i=Stack[top].i;
		j=Stack[top].j;
		di=Stack[top].di;//save the current location
		if(i==M&&j==N)//has found the exit,judge whether the road is exit
		{
			printf("%4d:   ",count++);//output the number of paths
			for(k=0;k<=top;k++)		 //output the coordinate
			{
				printf("(%d,%d)   ",Stack[k].i,Stack[k].j);
				if((k+1)%5==0)
					printf("\n\t");//output a line
			}
			cout<<endl;
			if(top+1 < minlen)
			{
					//compare with the minlenth to find the shortest path
				for(k=0;k<=top;k++)
					Path[k]=Stack[k];//save the shortest path
				minlen=top+1;//save the length
			}
			mg[Stack[top].i][Stack[top].j] = 0;//change the rode to can pass
			top--;//pop the Stack , return the former
			i=Stack[top].i;
			j=Stack[top].j;
			di=Stack[top].di;
		}
		find= 0;
		while(di<4 && find==0)
		{
			di++;
			switch(di)
			{
			case 0: i=Stack[top].i-1;j=Stack[top].j;  break;//upward
			case 1: i=Stack[top].i;  j=Stack[top].j+1;break;//turn right
			case 2: i=Stack[top].i+1;j=Stack[top].j;  break;//downward
			case 3: i=Stack[top].i;  j=Stack[top].j-1;break;//turn left
			}
			if(mg[i][j] == 0)//the road can pass
				find=1;		//mark can pass
		}
		if(find == 1 )//have found the road
		{
			Stack[top].di = di;//change the top elem of Stack 
			top++;				//the next road push Stack
			Stack[top].i = i;
			Stack[top].j = j;
			Stack[top].di= -1 ;//reset the number of di (direction)
			mg[i][j]= -1;//avoid passing the repeated road
		}
		else
		{
			mg[Stack[top].i][Stack[top].j] = 0;
												//let the road to pass by others
			top--;//pop the Satck
		}
	}
	cout<<"the shortest path is:"<<endl;
	cout<<"the length is    :"<<minlen<<endl;
	cout<<"the path is :   ";
	for(k=0;k<minlen;k++)
	{
		printf("(%d,%d)   ",Path[k].i,Path[k].j);
		if((k+1)%5==0)
			printf("\n\t");
	}
	cout<<endl;
}
int main()
{
	mgpath();
	return 0;
}