#include<iostream>
using namespace std;
typedef char Type;
class List
{
	private:
	Type data[1000];
	int length;
	public:
	void InitList();
	int ListEmpty();
	int ListLength();
	void DispList();
	int GetElem(int i,Type &e);
	int LocateElem(Type e);
	int ListInsert(int i,Type e);
	int ListDelete(int i,Type e);
};
void List::InitList()//��ʼ����
{
	this->length=0;
}
int List::ListEmpty()//�ж�˳����Ƿ�Ϊ��
{
	return this->length==0;
}
int List::ListLength()//��˳���ĳ���
{
	return this->length;
}
void List::DispList()//���˳���
{
	if(this->length==0)//�ж�˳����Ƿ�Ϊ��
		return;
	for(int i=0;i<this->length;i++)
		cout<<this->data[i]<<" ";
	cout<<endl;
}
int List::GetElem(int i,Type &e)//��ȡ˳����е�i��Ԫ��
{
	if(i<1||i>this->length)//iֵ�Ƿ�
		return 0;
	e=this->data[i-1];
	return 1;
}
int List::LocateElem(Type e)//���ҵ�һ��Ԫ��e
{
	int i=0;
	while(i<this->length&&this->data[i]!=e)//δ�ҵ�
		i++;
	if(i>=this->length)//δ�ҵ�
		return 0;
	else
		return i+1;
}
int List::ListInsert(int i,Type e)//�ڵ�i��λ�ò���Ԫ��e
{
	if(i<1||i>this->length+1)//iֵ�Ƿ�
		return 0;
	i--;
	for(int j=this->length;j>i;j--)
		this->data[j]=this->data[j-1];//Ԫ�غ���
	this->data[i]=e;//����ɹ�
	this->length++;//˳����ȼ�1
	return 1;
}
int List::ListDelete(int i,Type e)//ɾ����i��Ԫ��
{
	if(i<1||i>this->length)//iֵ�Ƿ�
		return 0;
	i--;
	for(int j=i;j<this->length;j++)
		this->data[j]=this->data[j+1];//Ԫ��ǰ��
	this->length--;//���ȼ�1
	return 1;
}
int main()
{
	List list;
	char e;
	list.InitList();
	list.ListInsert(1,'a');
	list.ListInsert(2,'b');
	list.ListInsert(3,'c');
	list.ListInsert(4,'d');
	list.ListInsert(5,'e');
	cout<<"˳���Ϊ:";
	list.DispList();
	cout<<"��:"<<list.ListLength()<<endl;
	list.GetElem(3,e);
	cout<<"���е�3��Ԫ����:"<<e<<endl;
	cout<<"Ԫ��a��λ���ǣ�"<<list.LocateElem('a')<<endl;
	list.ListInsert(4,'f');
	cout<<"�ڵ��ĸ�Ԫ��λ���ϲ���f"<<endl<<"˳�����:";
	list.DispList();
	list.ListDelete(3,e);
	cout<<"ɾ��������Ԫ��"<<endl<<"˳�����:";
	list.DispList();
	cout<<"�ͷ�˳���"<<endl;
	return 0;
}