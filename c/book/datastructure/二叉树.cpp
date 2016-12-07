#include<iostream>
using namespace std;
int const MaxSize = 100;
typedef struct node
{
	struct node *lChild;//the node's left child
	struct node *rChild;//the node's right child
	char data;//to save data
}BTNode;
void Create(BTNode *&t)//create the tree
{
	char ch;
	cin >> ch;
	if(ch == '\n')
		return ;
	if(ch == '#')
		t = NULL;
	else {
		t = (BTNode*) new BTNode();
		t->data = ch;
		Create(t->lChild);
		Create(t->rChild);
	}	 
}
int Destroy(BTNode *&t)
{
	if(t == NULL)
		return 0;
	if(t->lChild == NULL && t->rChild == NULL)
		delete t;
	else {
		Destroy(t->lChild);
		Destroy(t->rChild);
	}
	return 1;
}
int leafNodes(BTNode *b)//求叶子节点的个数
{
	int lleafNode,rleafNode;
	if(b == NULL)
		return 0;
	else if(b->lChild == NULL && b->rChild == NULL)
		return 1;
	else {
		lleafNode = leafNodes(b->lChild);
		rleafNode = leafNodes(b->rChild);
		return lleafNode + rleafNode;
	}
}
int PreOrder(BTNode *b)//前序遍历递归
{
	if(b == NULL)
		return 0;
	else {
		cout << b->data << " ";
		PreOrder(b->lChild);
		PreOrder(b->rChild);
	}
	return 1;
}
int InOrder(BTNode *b)//中序遍历递归
{
	if(b == NULL)
		return 0;
	else {
		InOrder(b->lChild );
		cout<<b->data <<" ";
		InOrder(b->rChild );
	}
	return 1;
}
int PostOrder(BTNode *b)//后序遍历递归
{
	if(b==NULL)
		return 0;
	else
	{
		PostOrder(b->lChild );
		PostOrder(b->rChild );
		cout<<b->data<<" ";
	}
	return 1;
}
int preOrder(BTNode *t)
{
	if(t==NULL)
		return 0;
	BTNode *Stack[MaxSize],*p;
	int top=-1;
	top++;
	Stack[top]=t;p=Stack[top];
	cout<<p->data<<" ";//output the Stack top message 
	while(top>-1)
	{
		while(p->lChild!=NULL)
		{
			top++;
			Stack[top]=p->lChild;
			p=Stack[top];
			cout<<p->data<<" ";
		}
		/*
		if(p->rChild!=NULL)//the right push Stack
		{
			Stack[top]=Stack[top]->rChild;//更改栈顶为当前栈顶的右孩子 
			cout<<Stack[top]->data<<" ";
			p=Stack[top];
		}
		else
		{
			top--;
			if(top==-1) 
				break;
		//	p=Stack[top]->rChild;
	//		cout<<p->data<<" ";
			cout<<Stack[top]->rChild->data<<" ";
			Stack[top]=Stack[top]->rChild;		//更改栈顶为当前栈顶的右孩子 
			p=Stack[top];	
		}
		*/
		if(p->rChild==NULL)
		{
			top--;
			if(top==-1) break;
		}
		Stack[top]=Stack[top]->rChild;//更改栈顶为当前栈顶的右孩子 
		cout<<Stack[top]->data<<" ";
		p=Stack[top];
	}
	cout<<endl;
	return 1;
}
int inOrder(BTNode *t)
{
	if(t==NULL) return 0;
	BTNode *Stack[MaxSize],*p;
	int top=-1;
	top++;
	Stack[top]=t;
	p=Stack[top];//p->the Stack top
	while(top>-1)
	{
		while(p->lChild!=NULL)
		{
			top++;
			Stack[top]=p->lChild;//p->lchild push Stack 
			p=Stack[top];//p->the Stack top
		}
		if(p->rChild!=NULL)
		{
			cout<<p->data<<" ";//is root output info
			Stack[top]=p->rChild;//the p->rChild push Stack
			p=Stack[top]; 
		}
		else
		{
			cout<<p->data<<" "; //or Stack[top]
			top--;
			if(top==-1)
				break;
			cout<<Stack[top]->data<<" ";
			Stack[top]=Stack[top]->rChild;
			p=Stack[top]; 
		}
	}
	cout<<endl;
	return 1;
}
int postOrder(BTNode *t)
{
	if(t==NULL) return 0;
	BTNode *Stack[MaxSize],*p,*q;
	int top=-1;top++;
	Stack[top]=t;p=Stack[top];
	while(top>-1)
	{
		while(p->lChild!=NULL)//p->the Stack top
		{
			top++;
			Stack[top]=p->lChild;
			p=Stack[top];
		}
		if(p->rChild==NULL)
		{
			cout<<Stack[top]->data<<" ";
			top--;
			if(top==-1)
				break;
		}
		if(p!=Stack[top]->rChild)
		{
			p=Stack[top];
			top++;
			Stack[top]=p->rChild;
			p=Stack[top];
		}
		else
		{
			cout<<Stack[top]->data<<" " ;
			top--;
		}
	}
	cout<<endl;
	return 1;
}
int main()
{
	BTNode *b,*p,*lp,*rp;
	cout<<"请输入要构造的二叉树相应的顶点信息!"<<endl; 
	Create(b);
	cout<<"二叉树叶子节点个数:"<<leafNodes(b)<<endl;
	cout<<"前序遍历 :";PreOrder(b);cout<<endl;
	cout<<"前序遍历1:";preOrder(b);
	cout<<"中序遍历 :";InOrder(b);cout<<endl;
	cout<<"中序遍历1:";inOrder(b);
	cout<<"后序遍历 :";PostOrder(b);cout<<endl;
	cout<<"后序遍历1:";postOrder(b);
	Destroy(b);
	return 0;
}
/*
//测试用例 

ABD##EF##G##C##

*/
