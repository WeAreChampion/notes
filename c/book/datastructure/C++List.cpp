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
void List::InitList()//初始化表
{
	this->length=0;
}
int List::ListEmpty()//判断顺序表是否为空
{
	return this->length==0;
}
int List::ListLength()//求顺序表的长度
{
	return this->length;
}
void List::DispList()//输出顺序表
{
	if(this->length==0)//判断顺序表是否为空
		return;
	for(int i=0;i<this->length;i++)
		cout<<this->data[i]<<" ";
	cout<<endl;
}
int List::GetElem(int i,Type &e)//获取顺序表中第i个元素
{
	if(i<1||i>this->length)//i值非法
		return 0;
	e=this->data[i-1];
	return 1;
}
int List::LocateElem(Type e)//查找第一个元素e
{
	int i=0;
	while(i<this->length&&this->data[i]!=e)//未找到
		i++;
	if(i>=this->length)//未找到
		return 0;
	else
		return i+1;
}
int List::ListInsert(int i,Type e)//在第i个位置插入元素e
{
	if(i<1||i>this->length+1)//i值非法
		return 0;
	i--;
	for(int j=this->length;j>i;j--)
		this->data[j]=this->data[j-1];//元素后移
	this->data[i]=e;//插入成功
	this->length++;//顺序表长度加1
	return 1;
}
int List::ListDelete(int i,Type e)//删除第i个元素
{
	if(i<1||i>this->length)//i值非法
		return 0;
	i--;
	for(int j=i;j<this->length;j++)
		this->data[j]=this->data[j+1];//元素前移
	this->length--;//表长度减1
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
	cout<<"顺序表为:";
	list.DispList();
	cout<<"表长:"<<list.ListLength()<<endl;
	list.GetElem(3,e);
	cout<<"表中第3个元素是:"<<e<<endl;
	cout<<"元素a的位置是："<<list.LocateElem('a')<<endl;
	list.ListInsert(4,'f');
	cout<<"在第四个元素位置上插入f"<<endl<<"顺序表是:";
	list.DispList();
	list.ListDelete(3,e);
	cout<<"删除第三个元素"<<endl<<"顺序表是:";
	list.DispList();
	cout<<"释放顺序表"<<endl;
	return 0;
}