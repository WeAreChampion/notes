#include<iostream>
using namespace std;
#define MaxSize 100
typedef int KeyType;
typedef char InfoType;
typedef struct node
{
	KeyType key;
	InfoType data;
	struct node *lChild,rChild;
}BSTNode;
int path[MaxSize];
void DispBST(BSTNode *bt)
{
	if(bt!=NULL)
	{
		cout<<bt->key;
		if(bt->lChild!=NULL||bt->rChild!=NULL)
		{
			printf("(");
			DispBST(bt->lChild);
			if(bt->rChild!=NULL)
			{
				printf(",");
			}
			DispBST(bt->rChild);
			printf(")");
		}
	}
}
int insertBST(BSTNode *&p,KeyType key)
{
	if(p==NULL)//BST is empty
	{
		p=new BSTNode();//p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=key;
		p->lChild=p->rChild=NULL;
		return 1;
	}
	else if(key==p->key)
	{
		return 0;
	}
	else if(key<p->key)
	{
		return insertBST(p->lChild,key);
	}
	else
	{
		return insertBST(p->rChild,key);
	}
}
BSTNode *CreateBST(KeyType a[],int n)
{
	BSTNode *bt=NULL;
	for(int i=0;i<n;i++)
	{
		if(insertBST(bt,a[i]))
		{
			printf("µÚ%d²½£¬²åÈë%d£º",i+1,a[i]);
			DispBST(bt);
			cout<<endl;
		}
	}
}
int predt=-32767;
bool JudgeBST(BSTNode *bt)
{
	int b1,b2;
	if(bt==NULL)
	{
		return true;
	}
	b1=JudgeBST(bt->lChild);
	if(b1==0||predt>bt->key)
	{
		return false;
	}
	predt=bt->key;
	b2=JudgeBST(bt->rChild);
	return b2;
}
int main()
{
	return 0;
}