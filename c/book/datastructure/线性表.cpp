#include<iostream>
using namespace std;
typedef char ElemType;
class SqList
{
private:
	ElemType data[1000];
	int length;
public:
	void InitList(SqList &l);
	int ListEmpty(SqList l);
	int ListLength(SqList l);
	void DispList(SqList l);
	int GetElem(SqList l,int i,ElemType &e);
	int LocateElem(SqList l,ElemType e);
	int ListInsert(SqList &l,int i,ElemType e);
	int ListDelete(SqList &l,int i,ElemType e);
};
void SqList::InitList(SqList &l)//��ʼ����
{
	l.length=0;//����
}
int SqList::ListEmpty(SqList l)//�ж�˳����Ƿ�Ϊ��
{
	return(l.length==0);
}
int SqList::ListLength(SqList l)//��˳���ĳ���
{
	return l.length;
}
void SqList::DispList(SqList l)//���˳���
{
	if(l.length==0)//�ж�˳����Ƿ�Ϊ��
		return;
	for(int i=0;i<l.length;i++)
		cout<<l.data[i]<<" ";
	cout<<endl;
}
int SqList::GetElem(SqList l,int i,ElemType &e)//��ȡ˳����е�i��Ԫ��
{
	if(i<1||i>l.length)//iֵ�Ƿ�
		return 0;
	e=l.data[i-1];
	return 1;
}
int SqList::LocateElem(SqList l,ElemType e)//���ҵ�һ��Ԫ��e
{
	int i=0;
	while(i<l.length&&l.data[i]!=e)//δ�ҵ�
		i++;
	if(i>=l.length)//δ�ҵ�
		return 0;
	else
		return i+1;
}
int SqList::ListInsert(SqList &l,int i,ElemType e)//�ڵ�i��λ�ò���Ԫ��e
{
	if(i<1||i>l.length+1)//iֵ�Ƿ�
		return 0;
	i--;
	for(int j=l.length;j>i;j--)
		l.data[j]=l.data[j-1];//Ԫ�غ���
	l.data[i]=e;//����ɹ�
	l.length++;//˳����ȼ�1
	return 1;
}
int SqList::ListDelete(SqList &l,int i,ElemType e)//ɾ����i��Ԫ��
{
	if(i<1||i>l.length)//iֵ�Ƿ�
		return 0;
	i--;
	for(int j=i;j<l.length;j++)
		l.data[j]=l.data[j+1];//Ԫ��ǰ��
	l.length--;//���ȼ�1
	return 1;
}

int main()
{
	SqList l;
	ElemType e;
	l.InitList(l);
	l.ListInsert(l,1,'a');
	l.ListInsert(l,2,'b');
	l.ListInsert(l,3,'c');
	l.ListInsert(l,4,'d');
	l.ListInsert(l,5,'e');
	cout<<"˳���Ϊ:";
	l.DispList(l);
	cout<<"��:"<<l.ListLength(l)<<endl;
	l.GetElem(l,3,e);
	cout<<"���е�3��Ԫ����:"<<e<<endl;
	cout<<"Ԫ��a��λ���ǣ�"<<l.LocateElem(l,'a')<<endl;
	l.ListInsert(l,4,'f');
	cout<<"�ڵ��ĸ�Ԫ��λ���ϲ���f"<<endl<<"˳�����:";
	l.DispList(l);
	l.ListDelete(l,3,e);
	cout<<"ɾ��������Ԫ��"<<endl<<"˳�����:";
	l.DispList(l);
	cout<<"�ͷ�˳���"<<endl;
   	return 0;
}