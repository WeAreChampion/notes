int main()
{
	BTNode *b,*p,*lp,*rp;
	creatBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	cout<<"������Ϊ:";
	dispBTNode(b);
	cout<<endl;
	cout<<"Ҷ�ӽڵ���:";
	DispLeafNodes(b);
	cout<<endl;
	p=findNode(b,'H');
	cout<<"H�ڵ�:";
	if(p!=NULL)
	{
		lp=lChildNode(p);
		if(lp!=NULL)
		{
			cout<<"������"<<lp->data<<" ";
		}
		else
		{
			cout<<"������ ";
		}
		rp=rChildNode(p);
		if(rp!=NULL)
		{
			cout<<"�Һ�����"<<rp->data<<endl;
		}
		else
		{
			cout<<"���Һ���"<<endl;
		}
	}
	cout<<"������b��depth:"<<BTNodeDepth(b)<<endl;
	cout<<"������b��width:"<<BTNodeWidth(b)<<endl;
	cout<<"�������ڵ����:"<<countNodes(b)<<endl;
	cout<<"������Ҷ�ӽڵ����:"<<leafNodes(b)<<endl;
	cout<<"ǰ����� :";PreOrder(b);cout<<endl;
	cout<<"ǰ�����1:";PreOrder1(b);
	cout<<"������� :";InOrder(b);cout<<endl;
	cout<<"�������1:";InOrder1(b);
	cout<<"������� :";PostOrder(b);cout<<endl;
	cout<<"�������1:";PostOrder1(b);
	cout<<"��α��� :";TraveLevel(b);
	return 0;
}