#include <vector> 
#include <queue> 
using namespace std; 
#ifndef SNAKE_H 
#define SNAKE_H 
class Cmp 
{
    private:
		friend class Csnake; //������Ա��
		int rSign; //������ 
		int lSign; //������ 
	public: 
	    //friend bool isDead(const Cmp& cmp); 
	    Cmp(int r,int l)//�в������캯��
		{
			setPoint(r,l);
		} 
		Cmp(){} //�޲������캯��
		void setPoint(int r,int l)//��������
		{
			rSign=r;
			lSign=l;
		} 
		Cmp operator-(const Cmp &m)const //����-�����
		{ 
			return Cmp(rSign - m.rSign,lSign - m.lSign);//���ص�ǰ���� 
		} 
		Cmp operator+(const Cmp &m)const //����+�����
		{ 
			return Cmp(rSign + m.rSign,lSign + m.lSign); 
		} 
}; 

const int maxSize = 5; //��ʼ������ 

class Csnake 
{
    private:
		Cmp firstSign; //��ͷ���� 
		Cmp secondSign;//�߾����� 
		Cmp lastSign; //��β���� 
		Cmp nextSign; //Ԥ����ͷ 
		int row; //���� 
		int line; //���� 
		int count; //������ 

		vector<vector<char> > snakeMap;//������Ϸ���� 
		queue<Cmp> snakeBody; //���� 
	public: 
		int GetDirections()const; //�԰��������Ҽ���Ϊ����ֵ
		char getSymbol(const Cmp& c)const            //��ȡָ��������ϵ��ַ� 
		{ 
			return snakeMap[c.lSign][c.rSign]; 
		} 
		Csnake(int n)                             //��ʼ����Ϸ�����С 
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
		void InitInstance();                //��ʼ����Ϸ���� 
		bool UpdataGame();    //������Ϸ���� 
		void ShowGame();     //��ʾ��Ϸ���� 
}; 
#endif 
// SNAKE_H 


/* ��� ʵ�� �� Ӧ��*/
#include <windows.h> 
#include <ctime> 
#include <iostream> 
using namespace std; 

//���Գɹ� 
void Csnake::InitInstance() //��ʼ����Ϸ���涨��
{ 
	snakeMap.resize(line); // snakeMap[������][������] 
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
	//��ʼ���� 
		snakeMap[line/2][m]='c'; 
	//����������ѹ����� 
		snakeBody.push(Cmp(m,(line/2))); 
	//snakeBody[������][������] 
	}

	//����ͷβ 
	firstSign=snakeBody.back(); 
	secondSign.setPoint(maxSize-1,line/2); 
} 

//���Գɹ� 
int Csnake::GetDirections()const 
{ 
	if(GetKeyState(VK_UP)<0) return 1; //1��ʾ�����ϼ� 
	if(GetKeyState(VK_DOWN)<0) return 2; //2��ʾ�����¼� 
	if(GetKeyState(VK_LEFT)<0) return 3; //3��ʾ������� 
	if(GetKeyState(VK_RIGHT)<0)return 4; //4��ʾ�����Ҽ� 
	return 0; 
} 

bool Csnake::UpdataGame() 
{ 
//��ʼ���÷�0 
	static int score=0; 
//��ȡ�û�������Ϣ 
	int choice; 
	choice=GetDirections(); 
	cout<<"Total score: "<<score<<endl; 
//�������ʳ���������� 
	int r,l; 
//��ʼ��ʼ�Ѿ���ʳ������һ��ʳ�� 
	static bool eatFood=true; 
//�������һ�������ٳ��ֵ�2��ʳ�� 
	if(eatFood) 
	{ 
		do 
		{ 
//���귶Χ�����ڣ�1��1������line-2,row-2���Ե����֮�� 
			srand(time(0));

			r=(rand()%(row-2))+1; //������ 
			l=(rand()%(line-2))+1;//������ 
//���������������겻����������� 
//�������²������� 
			if(snakeMap[l][r]!='c') 
			{	
				snakeMap[l][r]='*';
			} 
		}while (snakeMap[l][r]=='c'); 
}

switch (choice) 
{ 
	case 1://���� 
//�����ͷ���羱�ĺ����겻��ͬ��ִ��������� 
	if(firstSign.rSign!=secondSign.rSign)
		nextSign.setPoint(firstSign.rSign,firstSign.lSign-1); 
//����������ԭ�������ϼ����ƶ� 
	else 
		nextSign=firstSign+(firstSign-secondSign); break; 
	
	case 2://���� 
	if(firstSign.rSign!=secondSign.rSign)
		nextSign.setPoint(firstSign.rSign,firstSign.lSign+1); 
	else 
		nextSign=firstSign+(firstSign-secondSign); break; 

	case 3://���� 
	if(firstSign.lSign!=secondSign.lSign)
		nextSign.setPoint(firstSign.rSign-1,firstSign.lSign); 
	else 
		nextSign=firstSign+(firstSign-secondSign); 
	break; 

	case 4://���� 
	if(firstSign.lSign!=secondSign.lSign)
		nextSign.setPoint(firstSign.rSign+1,firstSign.lSign); 
	else 
		nextSign=firstSign+(firstSign-secondSign); 
	break; 

	default: 
	nextSign=firstSign+(firstSign-secondSign); 
}

//---------------------------------------------------------- 
	if(getSymbol(nextSign)!='*' && !isDead(nextSign))    //���û������ʳ��(��û�������������)��ɾ����β��ѹ���µ���ͷ 
	{ 
//ɾ����β 
		lastSign=snakeBody.front(); 
		snakeMap[lastSign.lSign][lastSign.rSign]=' '; 
		snakeBody.pop(); 
//������ͷ 
		secondSign=firstSign; 
//ѹ����ͷ 
		snakeBody.push(nextSign); 
		firstSign=snakeBody.back(); 
		snakeMap[firstSign.lSign][firstSign.rSign]='c'; 
//û�г�ʳ 
		eatFood=false; 
		return true; 
	}

//-----��ʳ----- 
	else if(getSymbol(nextSign)=='*' && !isDead(nextSign)) 
	{ 
		secondSign=firstSign; 
		snakeMap[nextSign.lSign][nextSign.rSign]='c'; 
//ֻѹ����ͷ 
		snakeBody.push(nextSign); 
		firstSign=snakeBody.back(); 
		eatFood=true; 
//�ӷ� 
		score+=20; 
		return true; 
	}

//-----����----- 
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

/*���������� */
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
