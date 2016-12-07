#include<iostream>
using namespace std;
#define INIT_SIZE 100 
typedef int ElemType;
typedef struct Node
{
	ElemType *data;
	int length;
}Union;
void InitUnion(Union *&u)
{
	u=(Union *) malloc (sizeof(Union));
	u->data = new ElemType[INIT_SIZE];
	u->length = 0;
}
void Destroy(Union *&u) 
{
	delete u->data;
	free(u);
}
bool Find(ElemType elem, Union *u)
{
	bool flag = false;
	for(int i = 0; i < u->length; i++)
	{
		if(u->data[i] == elem)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
void Add(ElemType elem, Union *&u)
{
	bool flag = Find(elem,u);
	if(flag)
	{
		cout << "The elem " << elem << " is exitence!" << endl;
		return;
	}
	cout << "insert " << elem << " in Union!" << endl;
	u->data[u->length++] = elem;
}
void Display(Union *u)
{
	cout << "the length is :" << u->length << endl;
	cout << "The elem in is :" << endl;
	for(int i = 0; i < u->length; i++)
	{
		cout << u->data[i] << " ";
	}
	cout << endl;
}
//save A U B in Union
void Merge(Union *u1, Union * u2, Union *&u3)
{
	for(int i = 0; i < u1->length; i++)
	{
		//add elem from u1 in u3
		u3->data[u3->length++] = u1->data[i];
	}
	for(int j = 0; j < u2->length; j++)
	{
		if(!Find(u2->data[j], u1))
		{
			u3->data[u3->length++] = u2->data[j];
		}
	}
}
void TestMerge(Union *u1, Union *u2)
{
	cout<<"集合并！"<<endl;
	Union *u3;
	InitUnion(u3);
	Merge(u1, u2, u3);
	Display(u3);
	Destroy(u3);
}
//A - B
void Substract(Union *u1, Union * u2, Union *&u3)
{
	for(int i = 0; i< u1->length; i++)
	{
		if(!Find(u1->data[i], u2))
		{
			u3->data[u3->length++] = u1->data[i];
		}
	}
}
void TestSubstract(Union *u1, Union *u2)
{
	cout<<"集合差！"<<endl;
	Union *u3;
	InitUnion(u3);
	Substract(u1,u2,u3);
	Display(u3);
	Destroy(u3);
}
//A ∩B 
void Jiao(Union *u1, Union * u2, Union *&u3)
{
	for(int i = 0; i < u1->length; i++)
	{
		if(Find(u1->data[i], u2))
		{
			u3->data[u3->length++] = u1->data[i];
		}
	}
} 
void TestJiao(Union *u1, Union *u2)
{
	cout<<"集合交！"<<endl;
	Union *u3;
	InitUnion(u3);
	Jiao(u1, u2, u3);
	Display(u3);
	Destroy(u3);
}
void YiHuo(Union *u1, Union * u2, Union *&u3)
{
	Substract(u1, u2, u3);
	Substract(u2, u1, u3);
}
void TestYiHuo(Union *u1, Union *u2)
{
	cout << "集合异或！" << endl;
	Union *u3;
	InitUnion(u3);
	YiHuo(u1, u2, u3);
	Display(u3);
	Destroy(u3);
}
//AB+(1-A)(A-B)
void TongHuo(Union *u1, Union * u2, Union *&u3)
{
	cout << "集合同或！" << endl;
}
void Test()
{
	Union *u;
	InitUnion(u);
	//u
	Add(2,u);
	Add(3,u);
	Add(4,u);
	Add(2,u);
	Add(1,u);
	Union *u2;
	//u2
	InitUnion(u2);
	Add(2,u2);
	Add(5,u2);
	Add(6,u2);
	Add(1,u2);
	//destroy
	cout<<"Union u1:"<<endl;
	Display(u);
	cout<<"Union u2:"<<endl;
	Display(u2);
	
	//Merge
	TestMerge(u,u2); 
	
	//substrcat
	TestSubstract(u,u2);
	
	//Jiao
	TestJiao(u,u2);
	
	//YiHuo
	TestYiHuo(u,u2);
	
	Destroy(u);
	Destroy(u2);
}
int main()
{
	Test();
	return 0;
}