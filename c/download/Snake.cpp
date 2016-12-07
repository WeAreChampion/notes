#include <vector> 
#include <queue> 
using namespace std; 
#ifndef SNAKE_H 
#define SNAKE_H 
class Cmp 
{
    private:
		friend class Csnake; //声明友员类
		int rSign; //横坐标 
		int lSign; //竖坐标 
	public: 
	    //friend bool isDead(const Cmp& cmp); 
	    Cmp(int r,int l)//有参数构造函数
		{
			setPoint(r,l);
		} 
		Cmp(){} //无参数构造函数
		void setPoint(int r,int l)//设置坐标
		{
			rSign=r;
			lSign=l;
		} 
		Cmp operator-(const Cmp &m)const //重载-运算符
		{ 
			return Cmp(rSign - m.rSign,lSign - m.lSign);//返回当前坐标 
		} 
		Cmp operator+(const Cmp &m)const //重载+运算符
		{ 
			return Cmp(rSign + m.rSign,lSign + m.lSign); 
		} 
}; 

const int maxSize = 5; //初始蛇身长度 

class Csnake 
{
    private:
		Cmp firstSign; //蛇头坐标 
		Cmp secondSign;//蛇颈坐标 
		Cmp lastSign; //蛇尾坐标 
		Cmp nextSign; //预备蛇头 
		int row; //列数 
		int line; //行数 
		int count; //蛇身长度 

		vector<vector<char> > snakeMap;//整个游戏界面 
		queue<Cmp> snakeBody; //蛇身 
	public: 
		int GetDirections()const; //以按上下左右键作为返回值
		char getSymbol(const Cmp& c)const            //获取指定坐标点上的字符 
		{ 
			return snakeMap[c.lSign][c.rSign]; 
		} 
		Csnake(int n)                             //初始化游戏界面大小 
		{ 
			if(n<20)line=20+2; 
			else if(n>30)line = 30+2; 
			else line=n+2; 
			row=line*3+2; 
		} 
		bool isDead(const Cmp& cmp) 
		{ 
			return ( getSymbol(cmp)=='c' || cmp.rSign == row-1 || cmp.rSign== 0 || cmp.lSign == line-1 || cmp.lSign == 0 ); 
		} 
		void InitInstance();                //初始化游戏界面 
		bool UpdataGame();    //更新游戏界面 
		void ShowGame();     //显示游戏界面 
}; 
#endif 
// SNAKE_H 


/* 类的 实现 及 应用*/
#include <windows.h> 
#include <ctime> 
#include <iostream> 
using namespace std; 

//测试成功 
void Csnake::InitInstance() //初始化游戏界面定义
{ 
	snakeMap.resize(line); // snakeMap[竖坐标][横坐标] 
	for(int i=0;i<line;i++) 
	{ 
		snakeMap[i].resize(row); 
		for(int j=0;j<row;j++) 
		{ 
			snakeMap[i][j]=' '; 
		} 
	}

	for(int m=1;m<maxSize+1;m++) 
	{ 
	//初始蛇身 
		snakeMap[line/2][m]='c'; 
	//将蛇身坐标压入队列 
		snakeBody.push(Cmp(m,(line/2))); 
	//snakeBody[横坐标][竖坐标] 
	}

	//链表头尾 
	firstSign=snakeBody.back(); 
	secondSign.setPoint(maxSize-1,line/2); 
} 

//测试成功 
int Csnake::GetDirections()const 
{ 
	if(GetKeyState(VK_UP)<0) return 1; //1表示按下上键 
	if(GetKeyState(VK_DOWN)<0) return 2; //2表示按下下键 
	if(GetKeyState(VK_LEFT)<0) return 3; //3表示按下左键 
	if(GetKeyState(VK_RIGHT)<0)return 4; //4表示按下右键 
	return 0; 
} 

bool Csnake::UpdataGame() 
{ 
//初始化得分0 
	static int score=0; 
//获取用户按键信息 
	int choice; 
	choice=GetDirections(); 
	cout<<"Total score: "<<score<<endl; 
//随机产生食物所在坐标 
	int r,l; 
//开始初始已经吃食，产生一个食物 
	static bool eatFood=true; 
//如果吃了一个，才再出现第2个食物 
	if(eatFood) 
	{ 
		do 
		{ 
//坐标范围限制在（1，1）到（line-2,row-2）对点矩型之间 
			srand(time(0));

			r=(rand()%(row-2))+1; //横坐标 
			l=(rand()%(line-2))+1;//竖坐标 
//如果随机产生的坐标不是蛇身，则可行 
//否则重新产生坐标 
			if(snakeMap[l][r]!='c') 
			{	
				snakeMap[l][r]='*';
			} 
		}while (snakeMap[l][r]=='c'); 
}

switch (choice) 
{ 
	case 1://向上 
//如果蛇头和社颈的横坐标不相同，执行下面操作 
	if(firstSign.rSign!=secondSign.rSign)
		nextSign.setPoint(firstSign.rSign,firstSign.lSign-1); 
//否则，如下在原本方向上继续移动 
	else 
		nextSign=firstSign+(firstSign-secondSign); break; 
	
	case 2://向下 
	if(firstSign.rSign!=secondSign.rSign)
		nextSign.setPoint(firstSign.rSign,firstSign.lSign+1); 
	else 
		nextSign=firstSign+(firstSign-secondSign); break; 

	case 3://向左 
	if(firstSign.lSign!=secondSign.lSign)
		nextSign.setPoint(firstSign.rSign-1,firstSign.lSign); 
	else 
		nextSign=firstSign+(firstSign-secondSign); 
	break; 

	case 4://向右 
	if(firstSign.lSign!=secondSign.lSign)
		nextSign.setPoint(firstSign.rSign+1,firstSign.lSign); 
	else 
		nextSign=firstSign+(firstSign-secondSign); 
	break; 

	default: 
	nextSign=firstSign+(firstSign-secondSign); 
}

//---------------------------------------------------------- 
	if(getSymbol(nextSign)!='*' && !isDead(nextSign))    //如果没有碰到食物(且没有死亡的情况下)，删除蛇尾，压入新的蛇头 
	{ 
//删除蛇尾 
		lastSign=snakeBody.front(); 
		snakeMap[lastSign.lSign][lastSign.rSign]=' '; 
		snakeBody.pop(); 
//更新蛇头 
		secondSign=firstSign; 
//压入蛇头 
		snakeBody.push(nextSign); 
		firstSign=snakeBody.back(); 
		snakeMap[firstSign.lSign][firstSign.rSign]='c'; 
//没有吃食 
		eatFood=false; 
		return true; 
	}

//-----吃食----- 
	else if(getSymbol(nextSign)=='*' && !isDead(nextSign)) 
	{ 
		secondSign=firstSign; 
		snakeMap[nextSign.lSign][nextSign.rSign]='c'; 
//只压入蛇头 
		snakeBody.push(nextSign); 
		firstSign=snakeBody.back(); 
		eatFood=true; 
//加分 
		score+=20; 
		return true; 
	}

//-----死亡----- 
	else 
        {
                cout<<"Dead"<<endl;
				cout<<"Your last total score is "<<score<<endl;
                return false;
         } 
} 


void Csnake::ShowGame() 
{ 
	for(int i=0;i<line;i++) 
	{ 
		for(int j=0;j<row;j++) 
			cout<<snakeMap[i][j]; 
		cout<<endl; 
	}

	Sleep(1); 
	system("cls"); 
} 


//======================================================================

/*主函数部分 */
#include <iostream> 
//#include "snake.h" 
#include <windows.h> 
using namespace std; 
int main() 
{ 
	Csnake s(20); 
	s.InitInstance(); 
//s.ShowGame(); 
	int noDead; 
	do 
	{ 
		s.ShowGame(); 
		noDead=s.UpdataGame(); 
	}
       while (noDead);
	system("pause"); 
	return 0; 
}
