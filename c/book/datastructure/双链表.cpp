#include"DoubleLinkList.h"
int main()
{
	DLinkList *l;
	char e;
	InitList(l);
	cout << "������Ϊ:" << (ListEmpty(l) ? "��" : "�ǿ�") << endl;
	ListInsert(l, 1, 'a');
	ListInsert(l, 2, 'b');
	ListInsert(l, 3, 'c');
	ListInsert(l, 4, 'd');
	ListInsert(l, 5, 'e');
	cout << "������Ϊ:" << (ListEmpty(l) ? "��" : "�ǿ�") << endl;
	cout << "˳���Ϊ:";
	DispList(l);
	cout << "��:" << ListLength(l) << endl;
	GetElem(l, 3, e);
	cout << "���е�3��Ԫ����:" << e << endl;
	cout << "Ԫ��a��λ���ǣ�" << LocateElem(l, 'a') << endl;
	ListInsert(l, 4, 'f');
	cout << "�ڵ��ĸ�Ԫ��λ���ϲ���f" << endl << "˳�����:";
	DispList(l);
	ListDelete(l, 3, e);
	cout<<"ɾ��������Ԫ��" << endl <<"˳�����:";
	DispList(l);
	cout << "�ͷ�˳���" << endl;
    ClearList(l);
	return 0;
}