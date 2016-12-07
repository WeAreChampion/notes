#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton& GetInstance() // 程序返回的是一个引用，程序本身不再创建新的对象
    {   
		static Singleton instance; 
        return instance;
    }
    // 程序定义了一个带状态的局部静态对象（单例），并且仅仅在第一次调用的时候创建
    ~Singleton()
    {   
		cout<<"~Singleton ..."<<endl;
    }

private:
    Singleton(const Singleton& other);
    Singleton& operator=(const Singleton& other);
    Singleton()
    {   
		cout<<"Singleton ..."<<endl;
    }
};

int main()
{   Singleton& s1 = Singleton::GetInstance();
    Singleton& s2 = Singleton::GetInstance();
    return 0;
}