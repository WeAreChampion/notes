#include<iostream>
using namespace std;
int const MaxSize=100;
typedef struct node
{
	struct node *lChild;//the node left child
	struct node *rChild;//the node right child
	char data;//to save data
}BTNode;
void creatBTNode(BTNode *&b,char *str)//运用数组构造二叉树
{
	int top = -1, k, j = 0;
	BTNode *Stack[MaxSize], *p = NULL;
	char ch;
	b = NULL;
	ch = str[j];
	while(ch != '\0')//循环到数组末尾
	{
		switch(ch)
		{
		case '(':
			top++;
			Stack[top] = p;
			k = 1;
			break;//为左节点
		case',': k = 2;
			break;//为左节点
		case ')':
			top--;
			break;
		default:
			p = (BTNode*) new (BTNode);
			p->data = ch;
			p->lChild = p->rChild = NULL;
			if(b == NULL) {
				b = p;//b指向二叉树根节点
			} else {
				switch(k) {
					case 1:
						Stack[top]->lChild = p;
						break;
					case 2:
						Stack[top]->rChild = p;
						break;
				}
			}
		}
		j++;//实现循环
		ch = str[j];
	}
}
BTNode *lChildNode(BTNode *p)//返回p节点左孩子指针
{
	return p->lChild ;
}
BTNode *rChildNode(BTNode *p)//返回p节点右孩子指针
{
	return p->rChild ;
}
BTNode *findNode(BTNode *b, char e)//通过元素查找节点
{
	BTNode *p;
	if(b == NULL)
		return 0;
	if(b->data == e)
		return b;
	else {
		p = findNode(b->lChild, e);//在左子树递归查找
		if(p != NULL) {//找到
			return p;//返回指针
		}
		else//在右子树递归查找
			return findNode(b->rChild, e);
	}
}
int BTNodeDepth(BTNode *b)//求二叉树的深度
{
	int lChildDepth, rChildDepth;
	if(b == NULL) {
		return 0;
	} else {
		lChildDepth = BTNodeDepth(b->lChild);
		rChildDepth = BTNodeDepth(b->rChild);
		return (lChildDepth > rChildDepth ? lChildDepth + 1 : rChildDepth + 1);
	}
}
int BTNodeWidth(BTNode *b)//求二叉树的宽度
{
	struct {
		int lno;//层次的编号
		BTNode *p;//节点指针
	}Qu[MaxSize];
	int front, rear;//队首队尾指针
	int lnum, max, i, n;
	front = rear = 0;//置队列为空
	if(b != NULL) {
		rear++;
		Qu[rear].p = b;//根节点指针入队
		Qu[rear].lno = 1;//根节点编号为1
		while(rear != front)//遍历求每个节点的层次
		{
			front ++;
			b = Qu[front].p;//队头出队
			lnum = Qu[front].lno;
			if(b->lChild != NULL)//左孩子入队
			{
				rear++;
				Qu[rear].p = b->lChild ;
				Qu[rear].lno = lnum + 1;
			}
			if(b->rChild != NULL)//有孩子入队
			{
				rear++;
				Qu[rear].p = b->rChild ;
				Qu[rear].lno = lnum + 1;
			}
		}
		max = 0, lnum = 1, i = 1;
		while(i <= rear) {
			n = 0;
			while(i <= rear && Qu[i].lno == lnum) {
				n++;//累计lnum层的节点个数
				i++;
			}
			lnum = Qu[i].lno;//取新节点的层次
			if(n > max) {
				max = n;//将最大层次赋值给max
			}
		}
		return max;
	} else {
		return 0;
	}
}
int DispLeafNodes(BTNode *b)//输出叶子节点
{
	if(b==NULL) {
		return 0;
	} else {
		if(b->lChild == NULL && b->rChild == NULL) {
			cout << b->data << " ";
		}
		DispLeafNodes(b->lChild);
		DispLeafNodes(b->rChild);
	}
	return 1;
}
int dispBTNode(BTNode *b)//遍历二叉树,按括号形式输出
{
	if(b==NULL) {
		return 0;
	} else {
		cout << b->data;
		if(b->lChild != NULL || b->rChild != NULL) {
			cout<<"(";
			dispBTNode(b->lChild );
			if(b->rChild != NULL) {
				cout << ",";
				dispBTNode(b->rChild );
				cout << ")";
			}
		}
	}
	return 1;
}
int countNodes(BTNode *b)//求节点的个数
{
	int lChildCount,rChildCount;
	if(b == NULL) {
		return 0;
	} else if(b->lChild == NULL && b->rChild == NULL) {
		return 1;
	} else {
		lChildCount = countNodes(b->lChild);
		rChildCount = countNodes(b->rChild);
		return (lChildCount+rChildCount + 1);
	}
}
int leafNodes(BTNode *b)//求叶子节点的个数
{
	int lleafNode,rleafNode;
	if(b == NULL) {
		return 0;
	}
	else if(b->lChild == NULL && b->rChild == NULL) {
		return 1;
	} else {
		lleafNode = leafNodes(b->lChild);
		rleafNode = leafNodes(b->rChild);
		return (lleafNode + rleafNode);
	}
}
int PreOrder(BTNode *b)//前序遍历递归
{
	if(!b)
		return 0;
	else {
		cout << b->data << " ";
		PreOrder(b->lChild );
		PreOrder(b->rChild );
	}
	return 1;
}
int PreOrder1(BTNode *b)//前序遍历非递归
{
	BTNode *Stack[MaxSize], *p;
	int top = -1;
	if(b != NULL) {
		top++;
		Stack[top] = b;
		while(top != -1) {
			p = Stack[top];
			top--;
			cout << p->data << " ";
			if(p->rChild != NULL)//右孩子先入栈；
			{//因为栈是先入后出，右孩子先入，后访问
				top++;
				Stack[top] = p->rChild ;
			}
			if(p->lChild != NULL)//左孩子入栈
			{
				top++;
				Stack[top] = p->lChild ;
			}
		}
		cout << endl;
		return 1;
	}
	return 0;
}
int InOrder(BTNode *b)//中序遍历递归
{
	if(b == NULL)
	{
		return 0;
	}
	else
	{
		InOrder(b->lChild );
		cout<<b->data <<" ";
		InOrder(b->rChild );
	}
	return 1;
}
int InOrder1(BTNode *b)//中序遍历非递归
{
	BTNode *Stack[MaxSize],*p;
	int top=-1;
	if(b!=NULL)
	{
		p=b;
		while(top!=-1||p!=NULL)
		{
			while(p!=NULL)
			{
				top++;
				Stack[top]=p;
				p=p->lChild;
			}
			if(top!=-1)
			{
				p=Stack[top];
				top--;
				cout<<p->data<<" " ;
				p=p->rChild ;
			}
		}
		cout<<endl;
		return 1;
	}
	else
	{
		return 0;
	}
}
int PostOrder(BTNode *b)//后序遍历递归
{
	if(b==NULL)
	{
		return 0;
	}
	else
	{
		PostOrder(b->lChild );
		PostOrder(b->rChild );
		cout<<b->data <<" ";
	}
	return 1;
}
int PostOrder1(BTNode *b)//后序遍历非递归
{
	BTNode *Stack[MaxSize],*p;
	int top=-1,flag;
	if(b!=NULL)
	{
		do
		{
			while(b!=NULL)//所有左结点入栈
			{
				top++;
				Stack[top]=b;
				b=b->lChild ;
			}
			p=NULL;//p指向当前结点的前一个已访问的结点
			flag=1;//设置b的访问标记已访问过
			while(top!=-1&&flag)
			{
				b=Stack[top];//取当前栈顶元素
				if(b->rChild ==p)//右子树不存在或已被访问
				{
					cout<<b->data <<" ";
					top--;
					p=b;//p指向刚刚被访问的结点
				}
				else
				{
					b=b->rChild ;//指向右子树
					flag=0;//设置未被访问的标志
				}
			}
		}while(top!=-1);
		cout<<endl;
		return 1;
	}
	else
	{
		return 0;
	}
}
void TraveLevel(BTNode *b)//层次遍历
{
	BTNode *Qu[MaxSize];
	int front,rear;
	front=rear=0;
	if(b!=NULL)
	{
		cout<<b->data<<" " ;
	}
	rear++;
	Qu[rear]=b;
	while(rear!=front)
	{
		front=(front+1)%MaxSize;
		b=Qu[front];
		if(b->lChild !=NULL)
		{
			cout<<b->lChild ->data<<" " ;
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->lChild ;
		}
		if(b->rChild !=NULL)
		{
			cout<<b->rChild ->data<<" " ;
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->rChild ;
		}
	}
	cout<<endl;
}
