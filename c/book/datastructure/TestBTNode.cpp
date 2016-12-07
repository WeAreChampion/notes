int main()
{
	BTNode *b,*p,*lp,*rp;
	creatBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	cout<<"二叉树为:";
	dispBTNode(b);
	cout<<endl;
	cout<<"叶子节点是:";
	DispLeafNodes(b);
	cout<<endl;
	p=findNode(b,'H');
	cout<<"H节点:";
	if(p!=NULL)
	{
		lp=lChildNode(p);
		if(lp!=NULL)
		{
			cout<<"左孩子是"<<lp->data<<" ";
		}
		else
		{
			cout<<"无左孩子 ";
		}
		rp=rChildNode(p);
		if(rp!=NULL)
		{
			cout<<"右孩子是"<<rp->data<<endl;
		}
		else
		{
			cout<<"无右孩子"<<endl;
		}
	}
	cout<<"二叉树b的depth:"<<BTNodeDepth(b)<<endl;
	cout<<"二叉树b的width:"<<BTNodeWidth(b)<<endl;
	cout<<"二叉树节点个数:"<<countNodes(b)<<endl;
	cout<<"二叉树叶子节点个数:"<<leafNodes(b)<<endl;
	cout<<"前序遍历 :";PreOrder(b);cout<<endl;
	cout<<"前序遍历1:";PreOrder1(b);
	cout<<"中序遍历 :";InOrder(b);cout<<endl;
	cout<<"中序遍历1:";InOrder1(b);
	cout<<"后序遍历 :";PostOrder(b);cout<<endl;
	cout<<"后序遍历1:";PostOrder1(b);
	cout<<"层次遍历 :";TraveLevel(b);
	return 0;
}