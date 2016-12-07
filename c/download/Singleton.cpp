#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton ()//���๹�캯��˽�У�ʹ����޷�ͨ����������ķ�ʽֱ�Ӵ��������
    {
		cout<<"Construct Singleton Object"<<endl;   
    }
    ~Singleton()
    {   cout<<"Destruct Singleton Object"<<endl;
    }
    static Singleton* instance;    //��̬���ͱ�֤Ψһ����
    Singleton (const Singleton& other) {};  //���������캯������Ϊ˽��,���Ҳ��ṩʵ��
    Singleton& operator= (const Singleton& other) {};//����ֵ���㺯��˽�л�

public:
    
    static Singleton* getInstance()
    {   if (instance == NULL)
        {   
			instance = new Singleton();
        }
        else
            return instance;
    }//��֤��ε��øù�����Ա���������صĶ���ָ��ͬһ�����Ķ���ָ��
    
    static void free()
    {   
		if (instance != NULL)
            delete instance;
    }
};
Singleton* Singleton::instance;//������������ļ���������о�̬���ݳ�Ա���壬�����ڴ�ռ�
int main()
{   Singleton::getInstance();
    Singleton* Ptr=Singleton::getInstance();	
    Singleton::free();
    
    return 0;
}