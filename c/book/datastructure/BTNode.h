#include<iostream>
using namespace std;
int const MaxSize=100;
typedef struct node
{
	struct node *lChild;//the node left child
	struct node *rChild;//the node right child
	char data;//to save data
}BTNode;
void creatBTNode(BTNode *&b,char *str)//�������鹹�������
{
	int top = -1, k, j = 0;
	BTNode *Stack[MaxSize], *p = NULL;
	char ch;
	b = NULL;
	ch = str[j];
	while(ch != '\0')//ѭ��������ĩβ
	{
		switch(ch)
		{
		case '(':
			top++;
			Stack[top] = p;
			k = 1;
			break;//Ϊ��ڵ�
		case',': k = 2;
			break;//Ϊ��ڵ�
		case ')':
			top--;
			break;
		default:
			p = (BTNode*) new (BTNode);
			p->data = ch;
			p->lChild = p->rChild = NULL;
			if(b == NULL) {
				b = p;//bָ����������ڵ�
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
		j++;//ʵ��ѭ��
		ch = str[j];
	}
}
BTNode *lChildNode(BTNode *p)//����p�ڵ�����ָ��
{
	return p->lChild ;
}
BTNode *rChildNode(BTNode *p)//����p�ڵ��Һ���ָ��
{
	return p->rChild ;
}
BTNode *findNode(BTNode *b, char e)//ͨ��Ԫ�ز��ҽڵ�
{
	BTNode *p;
	if(b == NULL)
		return 0;
	if(b->data == e)
		return b;
	else {
		p = findNode(b->lChild, e);//���������ݹ����
		if(p != NULL) {//�ҵ�
			return p;//����ָ��
		}
		else//���������ݹ����
			return findNode(b->rChild, e);
	}
}
int BTNodeDepth(BTNode *b)//������������
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
int BTNodeWidth(BTNode *b)//��������Ŀ��
{
	struct {
		int lno;//��εı��
		BTNode *p;//�ڵ�ָ��
	}Qu[MaxSize];
	int front, rear;//���׶�βָ��
	int lnum, max, i, n;
	front = rear = 0;//�ö���Ϊ��
	if(b != NULL) {
		rear++;
		Qu[rear].p = b;//���ڵ�ָ�����
		Qu[rear].lno = 1;//���ڵ���Ϊ1
		while(rear != front)//������ÿ���ڵ�Ĳ��
		{
			front ++;
			b = Qu[front].p;//��ͷ����
			lnum = Qu[front].lno;
			if(b->lChild != NULL)//�������
			{
				rear++;
				Qu[rear].p = b->lChild ;
				Qu[rear].lno = lnum + 1;
			}
			if(b->rChild != NULL)//�к������
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
				n++;//�ۼ�lnum��Ľڵ����
				i++;
			}
			lnum = Qu[i].lno;//ȡ�½ڵ�Ĳ��
			if(n > max) {
				max = n;//������θ�ֵ��max
			}
		}
		return max;
	} else {
		return 0;
	}
}
int DispLeafNodes(BTNode *b)//���Ҷ�ӽڵ�
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
int dispBTNode(BTNode *b)//����������,��������ʽ���
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
int countNodes(BTNode *b)//��ڵ�ĸ���
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
int leafNodes(BTNode *b)//��Ҷ�ӽڵ�ĸ���
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
int PreOrder(BTNode *b)//ǰ������ݹ�
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
int PreOrder1(BTNode *b)//ǰ������ǵݹ�
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
			if(p->rChild != NULL)//�Һ�������ջ��
			{//��Ϊջ�����������Һ������룬�����
				top++;
				Stack[top] = p->rChild ;
			}
			if(p->lChild != NULL)//������ջ
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
int InOrder(BTNode *b)//��������ݹ�
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
int InOrder1(BTNode *b)//��������ǵݹ�
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
int PostOrder(BTNode *b)//��������ݹ�
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
int PostOrder1(BTNode *b)//��������ǵݹ�
{
	BTNode *Stack[MaxSize],*p;
	int top=-1,flag;
	if(b!=NULL)
	{
		do
		{
			while(b!=NULL)//����������ջ
			{
				top++;
				Stack[top]=b;
				b=b->lChild ;
			}
			p=NULL;//pָ��ǰ����ǰһ���ѷ��ʵĽ��
			flag=1;//����b�ķ��ʱ���ѷ��ʹ�
			while(top!=-1&&flag)
			{
				b=Stack[top];//ȡ��ǰջ��Ԫ��
				if(b->rChild ==p)//�����������ڻ��ѱ�����
				{
					cout<<b->data <<" ";
					top--;
					p=b;//pָ��ոձ����ʵĽ��
				}
				else
				{
					b=b->rChild ;//ָ��������
					flag=0;//����δ�����ʵı�־
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
void TraveLevel(BTNode *b)//��α���
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
