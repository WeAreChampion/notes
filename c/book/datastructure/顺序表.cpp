#include"SqList.h"
int main()
{
	SqList*l;
	ElemType e;
	InitList(l);
	ListInsert(l, 1, 'a');
	ListInsert(l, 2, 'b');
	ListInsert(l, 3, 'c');
	ListInsert(l, 4, 'd');
	ListInsert(l, 5, 'e');
	cout << "顺序表为:";
	DispList(l);
	cout << "表长:" << ListLength(l) << endl;
	GetElem(l, 3, e);
	cout << "表中第3个元素是:" << e << endl;
	cout << "元素a的位置是：" << LocateElem(l, 'a') << endl;
	ListInsert(l, 4, 'f');
	cout << "在第四个元素位置上插入f" << endl << "顺序表是:";
	DispList(l);
	ListDelete(l, 3, e);
	cout << "删除第三个元素" << endl << "顺序表是:";
	DispList(l);
	cout << "释放顺序表" << endl;
    DestroyList(l);
	return 0;
}