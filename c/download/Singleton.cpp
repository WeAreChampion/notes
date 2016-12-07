#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton ()//将类构造函数私有，使外界无法通过创建对象的方式直接创建类对象。
    {
		cout<<"Construct Singleton Object"<<endl;   
    }
    ~Singleton()
    {   cout<<"Destruct Singleton Object"<<endl;
    }
    static Singleton* instance;    //静态类型保证唯一单例
    Singleton (const Singleton& other) {};  //将拷贝构造函数声明为私有,并且不提供实现
    Singleton& operator= (const Singleton& other) {};//将赋值运算函数私有化

public:
    
    static Singleton* getInstance()
    {   if (instance == NULL)
        {   
			instance = new Singleton();
        }
        else
            return instance;
    }//保证多次调用该公开成员函数，返回的都是指向同一单例的对象指针
    
    static void free()
    {   
		if (instance != NULL)
            delete instance;
    }
};
Singleton* Singleton::instance;//在类声明外的文件作用域进行静态数据成员定义，申请内存空间
int main()
{   Singleton::getInstance();
    Singleton* Ptr=Singleton::getInstance();	
    Singleton::free();
    
    return 0;
}