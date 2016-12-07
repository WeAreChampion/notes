#include<iostream>
#include<set>
#include<string>
using namespace std;
/*
如果一个人从未被打败过 那就是冠军，如果每个人都被一个人打败过
那就没有冠军。当然冠军只有一个.
综上所述，使用set容器最好
*/ 
int main() {
    set<string> all;
    set<string> lose;
    int T;
    while(cin >> T && T) {
        string a,b;
        while(T--) {
            cin >> a >> b;
            all.insert(a); //将两人都插入all中
            all.insert(b);
            lose.insert(b); //失败的人则插入lose
        }
        if(all.size() - lose.size() == 1) { 
			cout << "Yes" << endl;  //若有一人则为冠军
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