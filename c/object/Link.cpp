#include<iostream>
using namespace std;
template<class Type>
class Link
{
private:
	Link *next;
	Type data;
	Link *L;
public:
	bool InsertElem(Type elem,int i);
	bool DeleteElem(Type &elem,int i);
	bool IsEmpty();
	int getLength();
	Type getData(int i);
	Link<Type>* findElem(Type elem);
	void Display();
	void Destroy();
	Link();
	~Link();
	bool InitLink(); 
	Type getElem(Link *l);
};
template<class Type>
bool Link<Type>::InitLink()
{
	L=new Link();
	L->next=NULL;
}
template<class Type>
bool Link<Type>::InsertElem(Type elem,int i)
{
	int j=0;
	Link *p=L;
	while(p->next!=NULL&&j<i)
	{
		j++;
		p=p->next;
	}
	if(i<j)
		return false;
	Link *s=new Link();
	s->data=elem;
	s->next=p->next;
	p->next=s;
	return true;
}
template<class Type>
bool Link<Type>::DeleteElem(Type &elem,int i)
{
	int j=0;
	Link *p=L,*q;
	while(p->next!=NULL&&j<i)
	{
		j++;
		q=p;
		p=p->next; 
	}
	if(i>j)
		return false;
	elem=p->data;
	q->next=p->next;
	delete p;
	return true;
}
template<class Type>
bool Link<Type>::IsEmpty()
{
	return L->next==NULL;
}
template<class Type>
int Link<Type>::getLength()
{
	Link *p=L->next;
	int i=0;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}
template<class Type>
Type Link<Type>::getData(int i)
{
	int j=0;
	Link *p=L->next;
	while(p!=NULL)
	{
		j++;
		if(j==i)
			return p->data;
		p=p->next;
	}
}
template<class Type>
Link<Type>* Link<Type>::findElem(Type elem)
{
	Link *p=L->next;
	while(p!=NULL)
	{
		if(p->data==elem)
			return p;
		p=p->next;
	}
}
template<class Type>
void Link<Type>::Destroy()
{
	Link *p=L->next,*q=L;
	while(p!=NULL)
	{
		q->next=p->next;
		delete p;
		p=q->next; 
	}
	delete L;
	//cout<<"存储空间已经释放！\n";
	cout<<"The room is release!"<<endl;
}
template<class Type>
Link<Type>::Link()
{
	
}
template<class Type>
Link<Type>::~Link()
{
	
}
template<class Type>
void Link<Type>::Display()
{
	cout<<"The data is:\n";
	Link *p=L->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
template<class Type>
Type Link<Type>::getElem(Link *l)
{
	return l->data;
}
int main()
{
	Link<char> l;
	l.InitLink(); 
	l.InsertElem('a',1);
	l.InsertElem('b',2);
	l.InsertElem('c',3);
	l.InsertElem('d',4);
	l.InsertElem('e',5);
	l.InsertElem('f',6);
	l.Display();
	cout<<"The linklist length is:"<<l.getLength()<<endl;
	cout<<"The 3st elem is :"<<l.getData(3)<<endl;
	Link<char> *p=l.findElem('e');
	cout<<"the data(e) is: "<<l.getElem(p)<<endl;
	l.Destroy();
	return 0;
}