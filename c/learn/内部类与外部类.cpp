#include <iostream>
using namespace std;
class Outer
{
public:
    Outer()
    {   m_outerInt=0;
    }
private:
    int m_outerInt;
public:
    //�ڲ��ඨ�忪ʼ
    class Inner
    {
    public:
        Inner()
        {   m_innerInt=1;
        }
    private:
        int m_innerInt;
    public:
        void DisplayIn()
        {   cout<<"m_innerInt="<<m_innerInt<<endl;
        }
    } ;
    //End�ڲ���
public:
    void DisplayOut()
    {   cout<<"m_outerInt="<<m_outerInt<<endl;
    }
};

int main()
{   Outer out;
    Outer::Inner in;
    out.DisplayOut();
    in.DisplayIn();

    return 0;
}