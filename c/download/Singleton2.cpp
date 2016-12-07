#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton& GetInstance() // ���򷵻ص���һ�����ã��������ٴ����µĶ���
    {   
		static Singleton instance; 
        return instance;
    }
    // ��������һ����״̬�ľֲ���̬���󣨵����������ҽ����ڵ�һ�ε��õ�ʱ�򴴽�
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