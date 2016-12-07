#include<iostream>
using namespace std;
int main()
{
	int n,i;
	double sum1,sum2,score,point,credit,gpa;
	while(cin>>n)
	{
		sum1=0,sum2=0;
		while(n--)
		{
			cin>>credit>>score;
			if(score!=-1)
			{
				if(score>=90&&score<=100)
					point=4;
				else if(score>=80&&score<90)
					point=3;
				else if(score>=70&&score<80)
					point=2;
				else if(score>=60&&score<90)
					point=1;
				else if(score>=0&&score<60)
					point=0;
				sum1+=credit;
				sum2+=credit*point;
			}
		}
		if(sum1==0)
			cout<<-1<<endl;
		else
		{
			gpa=sum2/sum1;	
			printf("%.2lf\n",gpa);
		}
	}
	return 0;
}