#include<iostream>
#include<string>
using namespace std;
class Score
{
private:
	int math;
	int chinese;
	int english;
	int computer;
public:
	Score();
	Score(int math,int chinese,int english,int computer);
	~Score(){}
	void Disp();
	void setMath(int ma);
	int getMath();
	void setChinese(int ch);
	int getChinese();
	void setEnglish(int en);
	int getEnglish();
	void setComputer(int co);
	int getComputer();
	int getAverage();
};
void Score::Disp()
{
	cout<<"the math score is: "<<math<<endl;
	cout<<"the chinese score is: "<<chinese<<endl;
	cout<<"the english score is: "<<english<<endl;
	cout<<"the computer score is: "<<computer<<endl;
}
Score::Score()
{
	math=chinese=english=computer=0;
}
Score::Score(int math,int chinese,int english,int computer)
{
	this->math=math;
	this->chinese=chinese;
	this->english=english;
	this->computer=computer;
}
void Score::setMath(int ma)
{
	math=ma;
}
int Score::getMath()
{
	return math;
}
void Score::setChinese(int ch)
{
	chinese=ch;
}
int Score::getChinese()
{
	return chinese; 
}
void Score::setEnglish(int en)
{
	english=en;
}
int Score::getEnglish()
{
	return english;
}
void Score::setComputer(int co)
{
	computer=co;
}
int Score::getComputer()
{
	return computer;
}
int Score::getAverage()
{
	return (math+chinese+english+computer)/4;
}
int main()
{
	Score s(70,65,90,80);
	s.Disp();
	cout<<"the average is: "<<s.getAverage()<<endl;
	return 0;
} 