#include<iostream>
using namespace std;
typedef struct linknode
{
	char data;
	struct linknode *next;
}LiStack;
void InitStack(LiStack *&s)
{
	s=(LiStack *)new(LiStack);
	s->next=NULL;
}
void ClearStack(LiStack *&s)
{
	LiStack *p=s;
	while(p->next!=NULL)
	{
		p=s->next;
		delete s;
		s=p;
	}
	delete p;
}
int StackLength(LiStack *s)
{
	LiStack *p=s->next;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
void Push(LiStack *&s,char e)
{
	LiStack *p;
	p=(LiStack *)new(LiStack);
	p->data=e;
	p->next=s->next;
	s->next=p;
}
int Pop(LiStack *&s,char &e)
{
	LiStack *p;
	if(s->next==NULL)
		return 0;
	p=s->next;
	e=p->data;
	s->next=p->next;
	delete p;
	return 1;
}
void DispStack(LiStack *s)
{
	LiStack *p=s->next;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;
}
int GetTop(LiStack *s,char &e)
{
	if(s->next==NULL)
		return 0;
	e=s->next->data;
	return 1;
}
int StackEmpty(LiStack *s)
{
	return(s->next==NULL);
}
int main()
{
	char e;
	LiStack *s;
	InitStack(s);
	cout<<"ջΪ"<<(StackEmpty(s)?"��":"�ǿ�")<<endl;
	cout<<"��������a,b,c,d,e"<<endl;
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	cout<<"ջΪ"<<(StackEmpty(s)?"��":"�ǿ�")<<endl;
	cout<<"ջԪ�ظ���:"<<StackLength(s)<<endl;
	cout<<"��ջ����ջ��Ԫ��:";
	DispStack(s);
	if(GetTop(s,e)==1)
	{
		cout<<"ջ��Ԫ����:"<<e<<endl;
	}
	cout<<"��ջ����:";
	while(!StackEmpty(s))
	{
		Pop(s,e);
		cout<<e;
	}
	cout<<endl<<"ջΪ"<<(StackEmpty(s)?"��":"�ǿ�")<<endl;
	ClearStack(s);
	return 0;
}