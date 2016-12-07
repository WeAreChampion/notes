#include<iostream>
using namespace std;
template<class Type>
class Compare
{
private:
	Type x,y;
public:
	Compare(Type a,Type b);
	Compare(Compare &compare);
	Compare();
	~Compare();
	Type getMax();
	Type getMin();
};
template<class Type>
Compare<Type>::Compare(Type a,Type b)
{
	x=a;
	y=b;
}
template<class Type>
Type Compare<Type>::getMax()
{
	return x>y?x:y;
}
template<class Type>
Type Compare<Type>::getMin()
{
	return x<y?x:y;
}
template<class Type>
Compare<Type>::Compare(Compare &compare)
{
	x=compare.x;
	y=compare.y;
}
template<class Type>
Compare<Type>::Compare()
{
	x=y=0;
}
template<class Type>
Compare<Type>::~Compare()
{
	cout<<"存储空间已经释放！"<<endl;
}
int main()
{
	Compare<int> a(1,2);
	cout<<"The max is: "<<a.getMax()<<endl;
	cout<<"The min is: "<<a.getMin()<<endl;
	return 0;
}