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
void SqList::InitList(SqList &l)//初始化表
{
	l.length=0;//表长度
}
int SqList::ListEmpty(SqList l)//判断顺序表是否为空
{
	return(l.length==0);
}
int SqList::ListLength(SqList l)//求顺序表的长度
{
	return l.length;
}
void SqList::DispList(SqList l)//输出顺序表
{
	if(l.length==0)//判断顺序表是否为空
		return;
	for(int i=0;i<l.length;i++)
		cout<<l.data[i]<<" ";
	cout<<endl;
}
int SqList::GetElem(SqList l,int i,ElemType &e)//获取顺序表中第i个元素
{
	if(i<1||i>l.length)//i值非法
		return 0;
	e=l.data[i-1];
	return 1;
}
int SqList::LocateElem(SqList l,ElemType e)//查找第一个元素e
{
	int i=0;
	while(i<l.length&&l.data[i]!=e)//未找到
		i++;
	if(i>=l.length)//未找到
		return 0;
	else
		return i+1;
}
int SqList::ListInsert(SqList &l,int i,ElemType e)//在第i个位置插入元素e
{
	if(i<1||i>l.length+1)//i值非法
		return 0;
	i--;
	for(int j=l.length;j>i;j--)
		l.data[j]=l.data[j-1];//元素后移
	l.data[i]=e;//插入成功
	l.length++;//顺序表长度加1
	return 1;
}
int SqList::ListDelete(SqList &l,int i,ElemType e)//删除第i个元素
{
	if(i<1||i>l.length)//i值非法
		return 0;
	i--;
	for(int j=i;j<l.length;j++)
		l.data[j]=l.data[j+1];//元素前移
	l.length--;//表长度减1
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
	cout<<"顺序表为:";
	l.DispList(l);
	cout<<"表长:"<<l.ListLength(l)<<endl;
	l.GetElem(l,3,e);
	cout<<"表中第3个元素是:"<<e<<endl;
	cout<<"元素a的位置是："<<l.LocateElem(l,'a')<<endl;
	l.ListInsert(l,4,'f');
	cout<<"在第四个元素位置上插入f"<<endl<<"顺序表是:";
	l.DispList(l);
	l.ListDelete(l,3,e);
	cout<<"删除第三个元素"<<endl<<"顺序表是:";
	l.DispList(l);
	cout<<"释放顺序表"<<endl;
   	return 0;
}