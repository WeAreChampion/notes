#include<iostream>
#include<set>
#include<string>
using namespace std;
/*
���һ���˴�δ����ܹ� �Ǿ��ǹھ������ÿ���˶���һ���˴�ܹ�
�Ǿ�û�йھ�����Ȼ�ھ�ֻ��һ��.
����������ʹ��set�������
*/ 
int main() {
    set<string> all;
    set<string> lose;
    int T;
    while(cin >> T && T) {
        string a,b;
        while(T--) {
            cin >> a >> b;
            all.insert(a); //�����˶�����all��
            all.insert(b);
            lose.insert(b); //ʧ�ܵ��������lose
        }
        if(all.size() - lose.size() == 1) { 
			cout << "Yes" << endl;  //����һ����Ϊ�ھ�
		} 
        else {
        	cout<<"No"<<endl;
        }
        all.clear();
        lose.clear();
    }
}
/*
Sample Input
3
Alice Bob
Smith John
Alice Smith
5
a c
c d
d e
b e
a d
0


Sample Output
Yes
No


*/ 