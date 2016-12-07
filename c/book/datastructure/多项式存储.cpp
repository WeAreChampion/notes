#include<iostream>
using namespace std;
#define  MaxSize  100
int ma = 4,mb = 7;
float coe_a[4]={1,2,3,5},coe_b[7]={2,1,3,-3,4,7,-10};//the coe_a and coe_b array
int exp_a[]={0,2,3,5},exp_b[]={0,1,2,3,4,5,6};//the exp_a and exp_b array
int exp_d1[]={0,1,2},exp_d2[]={0,2,3};
float coe_d1[]={2,3,-2},coe_d2[]={1,-2,2};
typedef struct node
{
	float coef;			//系数
	int expn;			//指数
	struct node *next;
}polynomial;
void CreatPolyn(polynomial *&p,int m,float *coe,int *exp)//creat the polynomial
{
	p=(polynomial *)new polynomial();
	p->next =NULL;
	polynomial *pp=p;
	for(int i=0; i<m ; i++)//尾插法
	{
		polynomial *q=new polynomial();//new the new node
		q->coef =coe[i] ;//save the message of coef
		q->expn =exp[i] ;//save the message of expn
		q->next =pp->next ;//insert the node
		pp->next = q ;
		pp = q;			//pp指向尾结点
	}
}
int PolynEmpty(polynomial *p)//judge whether the polyn is empty
{
	return p->next == NULL;
}
int PolynLength(polynomial *p)//get polynomial length
{
	int i=0;
	p=p->next ;
	while(p != NULL)
	{
		i++;
		p=p->next ;
	}
	return i;
}
int GetElem(polynomial *p,int i,float &coe,int &exp)//get elem from the polynomial
{
	
	int j=0;
	while(p->next && j<i)
	{
		j++;
		p=p->next ;
	}
	if(j<i || i<1)
		return 0;
	coe = p->coef ;
	exp = p->expn ;
	return 1;
}
int InsertPolyn(polynomial *&p,int i,float coe,int exp)//insert the node
{
	int j=0;
	polynomial *pp=p ;
	while(pp->next && j<i-1)
	{
		pp=pp->next ;
		j++;
	}
	if( j<i-1 || i<1)
		return 0;
	polynomial *q=new polynomial ();
	q->coef =coe;
	q->expn =exp;
	q->next =pp->next ;
	pp->next =q;
	return 1;
}
int DeletePolyn(polynomial *&p,int i,float &coe,int &exp)//delete the node return the inormation
{
	int j=0;
	polynomial *pp=p ;
	while(pp->next && j<i-1)
	{
		pp=pp->next ;
		j++;
	}
	if( j<i-1 || i<1)//the value of i is illegal 
		return 0;
	polynomial *q=pp->next ;
	coe = q->coef;
	exp = q->expn ;
	pp->next = q->next ;
	delete q;
	return 1;
}
void DestroyPolyn(polynomial *&p)//destroy the polynomial
{
	polynomial *q=p->next ;
	while(q!=NULL)
	{
		p->next =q->next ;
		delete q;
		q = p->next ;
	}
	delete p;
}
void AddPolyn(polynomial *&pa,polynomial *pb)//add the polynomial，考虑了coef加起来为0的情况and doesn't delete the node
{
	polynomial *ppa=pa->next ,*p1=pa;//p1->ppa的前一节点
	pb=pb->next;
	while(ppa && pb)
	{
		if(ppa->expn ==pb->expn )
		{
			ppa->coef=ppa->coef +pb->coef ;
			if(ppa->coef==0)//delete the coef is zero
			{
				p1->next =ppa->next ;
				delete ppa;
				ppa=p1->next ;
			}
			else
			{
				p1=ppa;
				ppa = ppa->next ;//ppa 下指
			}
			pb = pb->next ;
		}
		else if(ppa->expn > pb->expn )//insert pb into pa
		{
			polynomial *q=new polynomial ();
			q->coef = pb->coef ;
			q->expn = pb->expn ;
			pb = pb->next ;
			q->next = ppa;//insert the node q
			p1->next = q;
			p1 = p1->next ;
		}
		else
		{
			p1 = ppa;
			ppa = ppa->next ;
		}
	}
	while(pb)//when is out ,ppa=NULL,so use the p1
	{
		polynomial *q=new polynomial ();
		q->coef = pb->coef ;
		q->expn = pb->expn ;
		pb=pb->next ;
		q->next = p1->next ;
		p1->next = q ;
		p1 = q ;
	}
	return;
}
void SubductionPolyn(polynomial *pa,polynomial *pb,polynomial *&pc)//subduct pa and pb to pc
{
	float coe;
	pc=new polynomial ();
	pc->next=NULL ;
	polynomial *ppa=pa->next,*ppb=pb->next,*ppc=pc;
	while(ppa && ppb )
	{
		if(ppa->expn==ppb->expn)
		{
			coe=ppa->coef - ppb->coef ;
			if(coe!=0)
			{
				polynomial *q=new polynomial();
				q->expn =ppa->expn ;
				q->coef =coe ;
				q->next = ppc->next ;
				ppc->next = q ;
				ppc = q ;
			}
			ppa = ppa->next ;
			ppb = ppb->next ; 
		}
		else if(ppa->expn > ppb->expn )//insert ppb's node
		{
			polynomial *q=new polynomial();
			q->coef = -ppb->coef ;
			q->expn = ppb->expn ;
			q->next = ppc->next ;
			ppc->next = q ;
			ppc = q ;
			ppb=ppb->next ;
		}
		else
		{
			polynomial *q=new polynomial();
			q->coef = ppa->coef ;
			q->expn = ppa->expn ;
			q->next = ppc->next ;
			ppc->next = q ;
			ppc = q ;
			ppa=ppa->next ;
		}
	}
	while(ppb)
	{
		polynomial *q=new polynomial();
		q->coef = -ppb->coef ;
		q->expn = ppb->expn ;
		q->next = ppc->next ;
		ppc->next = q ;
		ppc = q ;
		ppb=ppb->next ;
	}
	while(ppa)
	{
		polynomial *q=new polynomial();
		q->coef = ppa->coef ;
		q->expn = ppa->expn ;
		q->next = ppc->next ;
		ppc->next = q ;
		ppc = q ;
		ppa=ppa->next ;
	}
}
void MultiplyPolyn(polynomial *pa,polynomial *pb,polynomial *&pc)//MultiplyPolyn 
{
	float coe;
	int exp;
	pc=new polynomial();
	pc->next =NULL;
	polynomial *ppc=pc,*ppa=pa->next,*ppb,*pc1;
	while(ppa)
	{
		if(ppa==pa->next )//the first one multiply
		{
			ppb=pb->next ;
			while(ppb)
			{
				polynomial *q=new polynomial();
				q->coef =ppa->coef*ppb->coef ;
				q->expn =ppa->expn + ppb->expn ;
				ppb = ppb->next ;//ppb->next

				q->next = ppc->next ;//insert q
				ppc->next = q;
				ppc = q;//ppc->the last node
			}
		}
		else
		{
			ppb=pb->next ;
			ppc = pc->next ;
			pc1=ppc;//pc1->the former node ppc
			while(ppb)
			{
				int find=1;
				coe = ppa->coef * ppb->coef ;
				exp = ppa->expn + ppb->expn ;
				while(ppc)//find the node's expn is exp
				{
					if(exp == ppc->expn )
					{
						ppc->coef =ppc->coef + coe;
						find=0;//is find
						break;
					}
					else if(exp < ppc->expn )//add new node
					{
						polynomial *q=new polynomial();//new node
						q->coef = coe ;
						q->expn = exp ;
						q->next = pc1->next ;//insert q
						pc1->next = q;
						pc1=q; 
						find=0;//is find
						break;
					}
					pc1=ppc;
					ppc=ppc->next;
					find=1;//not find
				}
				if(find)//if not find ,add new node at last
				{
					polynomial *q=new polynomial();
					q->coef =coe ;
					q->expn =exp ;
					q->next = pc1->next ;//insert q
					pc1->next = q;
				}
				ppc=pc->next;
				ppb = ppb->next ;
			}
		}
		ppa=ppa->next ;
	}
}
void DispPolyn(polynomial *p)//output the polynomial
{
	polynomial *q=p->next ;//p->the first node
	while(q)
	{
		if(q->coef)
		{
			if(q==p->next)
			{
				if(q->expn==0)
				{
					cout<<q->coef;
				}
				if(q->expn==1)
				{
					if(q->coef==-1)
						cout<<"-";
					cout<<"x";
				}
				if(q->expn>1)
				{
					if(q->coef==-1)
						cout<<"-";
					else if(q->coef!=1)
						cout<<q->coef;
					cout<<"x^"<<q->expn;
				}
			}
			else
			{
				if(q->expn==1)
				{
					if(q->coef==-1)
						cout<<"-";
					else if(q->coef==1)
						cout<<"+";
					else if(q->coef>0)
						cout<<"+"<<q->coef;
					else if(q->coef<0)
						cout<<q->coef;
					cout<<"x";
				}
				if(q->expn>1)
				{
					if(q->coef==-1)
						cout<<"-";
					else if(q->coef==1)
						cout<<"+";
					else if(q->coef>1)
						cout<<"+"<<q->coef;
					else
						cout<<q->coef;
					cout<<"x^"<<q->expn;
				}
			}
			q=q->next;
		}
	}
	cout<<endl;
}
int main()//main()
{
	polynomial *pa,*pb;
	float coe;
	int exp;
	int ii=6;
	cout<<"pa的系数指数依次是: ";
	for(int i=0;i<4;i++)
	{
		if(i!=3)
			cout<<"<"<<coe_a[i]<<","<<exp_a[i]<<">,";
		else
			cout<<"<"<<coe_a[i]<<","<<exp_a[i]<<">\n";
	}
	CreatPolyn(pa,ma,coe_a,exp_a);
	cout<<"polynomial pa is:    ";
	DispPolyn(pa);
	cout<<"pa is Empty?   "<<(PolynEmpty(pa)?"YES\n":"NO\n");
	if(GetElem(pa,ii,coe,exp))//getElem
	{
		cout<<"polynomial pa 第"<<ii<<"元素值是:   "<<coe<<"\t"<<exp<<endl;
	}
	else
	{
		cout<<"the getElem value ii= "<<ii<<" in pa 非法"<<endl;
	}
	if(InsertPolyn(pa,ii,-6,6))//insert the node
	{
		cout<<"the insert pa is:    ";
		DispPolyn(pa);
	}
	else
	{
		cout<<"the insret position ii= "<<ii<<" in pa 非法"<<endl;
	}
	CreatPolyn(pb,mb,coe_b,exp_b);
	cout<<"polynomial pb is:    ";
	DispPolyn(pb);
	if(GetElem(pb,ii,coe,exp))//getElem
	{
		cout<<"polynomial pb 第"<<ii<<"元素值是   :coe="<<coe<<"\texp="<<exp<<endl;
	}
	else
	{
		cout<<"the getElem value ii= "<<ii<<" 非法"<<endl;
	}
	if(InsertPolyn(pb,ii,-6,6))//insert
	{
		cout<<"the insert pb is:    ";
		DispPolyn(pb);
	}
	else
	{
		cout<<"the insret position ii= "<<ii<<" in pb 非法"<<endl;
	}
	if(DeletePolyn(pb,ii,coe,exp))//delete 
	{
		cout<<"the delete node value:   coe="<<coe<<"\t\texp="<<exp<<endl;
		cout<<"the delete pb is:    ";
		DispPolyn(pb);
	}
	else
	{
		cout<<"the insret position ii= "<<ii<<" in pb 非法"<<endl;
	}//	/*
	cout<<"polynomial pa is:    ";
	DispPolyn(pa);
	cout<<"polynomial pb is:    ";
	DispPolyn(pb);
	AddPolyn(pa,pb);//add pa and pb
	cout<<"The Add node pa is:    ";
	DispPolyn(pa);//	*/
	polynomial *d1,*d2,*d3,*d4;
	CreatPolyn(d1,3,coe_d1,exp_d1);
	cout<<"The node d1 is:    ";
	DispPolyn(d1);
	CreatPolyn(d2,3,coe_d2,exp_d2);
	cout<<"The node d2 is:    ";
	DispPolyn(d2);
	MultiplyPolyn(d1,d2,d3);
	cout<<"The Multiply node d3 is:    ";
	DispPolyn(d3);
	SubductionPolyn(d1,d2,d4);
	cout<<"The subduction node d4 is:  ";
	DispPolyn(d4);
	DestroyPolyn(pa);
	DestroyPolyn(pb);
	return 0;
}
	/*
	polynomial *pc;
	AddPolyn(pa,pb,pc);//add pa and pb to pc
	cout<<"The Add node pc is:    ";
	DispPolyn(pc);
	cout<<"the polynomial pc length is:   "<<PolynLength(pc)<<endl;//get Length and output
	*/
	/*
	polynomial *pc;
	MultiplyPolyn(pa,pb,pc);
	cout<<"The Multiply node pc is:    ";
	DispPolyn(pc);	
	*/
//*/
/*
void AddPolyn(polynomial *&pa,polynomial *&pb,polynomial *&pc)//add pa and pb to pc
{
	float coe;
	pc=new polynomial ();
	polynomial *ppa,*ppb,*ppc;
	pc->next=NULL ;
	ppc = pc ;
	while(pa->next  && pb->next )
	{
		ppa=pa->next ;
		ppb=pb->next ;
		if(ppa->expn==ppb->expn)
		{
			coe=ppa->coef +ppb->coef ;
			if(coe!=0)
			{
				polynomial *q=new polynomial();
				q->expn =ppa->expn ;
				q->coef =coe ;
				q->next = ppc->next ;
				ppc->next = q ;
				ppc = q ;
			}
			pa->next =ppa->next ;
			delete ppa;
			ppa = pa->next ;
			pb->next =ppb->next ;
			delete ppb;
			ppb = pb->next ; 
		}
		else if(ppa->expn > ppb->expn )
		{
			polynomial *q=new polynomial();
			q->coef = ppb->coef ;
			q->expn = ppb->expn ;
			q->next = ppc->next ;
			ppc->next = q ;
			ppc = q ;
			pb->next =ppb->next ;
			delete ppb;
			ppb=pb->next ;
		}
		else
		{
			polynomial *q=new polynomial();
			q->coef = ppa->coef ;
			q->expn = ppa->expn ;
			q->next = ppc->next ;
			ppc->next = q ;
			ppc = q ;
			pa->next =ppa->next ;
			delete ppa;
			ppa=pa->next ;
		}
	}
	while(ppb)
	{
		polynomial *q=new polynomial();
		q->coef = ppb->coef ;
		q->expn = ppb->expn ;
		q->next = ppc->next ;
		ppc->next = q ;
		ppc = q ;
		pb->next =ppb->next ;
		delete ppb;
		ppb=pb->next ;
	}
	while(ppa)
	{
		polynomial *q=new polynomial();
		q->coef = ppa->coef ;
		q->expn = ppa->expn ;
		q->next = ppc->next ;
		ppc->next = q ;
		ppc = q ;
		pa->next =ppa->next ;
		delete ppa;
		ppa=pa->next ;
	}
}
*/
/*
void AddPolyn(polynomial *&pa,polynomial *&pb)//add the polynomial,没考虑加起来coef为0
{
	polynomial *ppa=pa->next ,*ppb=pb->next,*p1=pa;//p1->ppa的前一节点
	while(ppa && ppb)
	{
		if(ppa->expn ==ppb->expn )
		{
			ppa->coef=ppa->coef +ppb->coef ;
			p1=ppa;
			ppa = ppa->next ;//ppa 下指
			pb->next = ppb->next ;
			delete ppb;
			ppb = pb->next ;
			
		}
		else if(ppa->expn > ppb->expn )//insert pb into pa
		{
			polynomial *q=new polynomial ();
			q->coef = ppb->coef ;
			q->expn = ppb->expn ;
			pb->next = ppb->next ;
			delete ppb;//delete ppb -> node
			ppb = pb->next ;
			q->next = ppa;//insert the node q
			p1->next = q;
			p1 = p1->next ;
		}
		else
		{
			p1 = ppa;
			ppa = ppa->next ;
		}
	}
	while(ppb)//when is out ,ppa=NULL,so use the p1
	{
		polynomial *q=new polynomial ();
		q->coef = ppb->coef ;
		q->expn = ppb->expn ;
		pb->next = ppb->next ;
		delete ppb;
		ppb=pb->next ;
		q->next = p1->next ;
		p1->next = q ;
		p1 = q ;
	}
	delete pb;
	return;
}
*/
/*
void AddPolyn(polynomial *&pa,polynomial *&pb)//add the polynomial，考虑了coef加起来为0的情况and delete the node
{
	polynomial *ppa=pa->next ,*ppb=pb->next,*p1=pa;//p1->ppa的前一节点
	while(ppa && ppb)
	{
		if(ppa->expn ==ppb->expn )
		{
			ppa->coef=ppa->coef +ppb->coef ;
			if(ppa->coef==0)//delete the coef is zero
			{
				p1->next =ppa->next ;
				delete ppa;
				ppa=p1->next ;
			}
			else
			{
				p1=ppa;
				ppa = ppa->next ;//ppa 下指
			}
			pb->next = ppb->next ;
			delete ppb;
			ppb = pb->next ;
		}
		else if(ppa->expn > ppb->expn )//insert pb into pa
		{
			polynomial *q=new polynomial ();
			q->coef = ppb->coef ;
			q->expn = ppb->expn ;
			pb->next = ppb->next ;
			delete ppb;//delete ppb -> node
			ppb = pb->next ;
			q->next = ppa;//insert the node q
			p1->next = q;
			p1 = p1->next ;
		}
		else
		{
			p1 = ppa;
			ppa = ppa->next ;
		}
	}
	while(ppb)//when is out ,ppa=NULL,so use the p1
	{
		polynomial *q=new polynomial ();
		q->coef = ppb->coef ;
		q->expn = ppb->expn ;
		pb->next = ppb->next ;
		delete ppb;
		ppb=pb->next ;
		q->next = p1->next ;
		p1->next = q ;
		p1 = q ;
	}
	delete pb;
	return;
}
*/
/*
void DispPolyn(polynomial *p)//output the polynomial
{
	p=p->next ;//p->the first node
	while(p->next)
	{
		if(p->coef==0 )
		{
			p=p->next ;//p->the next node
			if(p->next->expn >0)
				cout<<"+";
			else
				cout<<"-";
		}
		else
		{
			if(p->expn)	
			{
				if(p->next->coef>0)
				{
					if(p->coef !=1&&p->expn !=1)
						cout<<p->coef<<"*x^"<<p->expn<<"+";
					else if(p->expn !=1&&p->coef ==1)
						cout<<"x^"<<p->expn <<"+";
					else if(p->coef !=1&&p->expn==1)
						cout<<p->coef<<"x"<<"+";
					else
						cout<<"x+";
				}
				else
					cout<<p->coef<<"*x^"<<p->expn;
			}
			else
				cout<<p->coef<<"+";
			p=p->next ;
		}
	}
	cout<<p->coef<<"*x^"<<p->expn<<endl;
}
*/