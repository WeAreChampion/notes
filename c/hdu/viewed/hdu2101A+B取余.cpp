#include <iostream>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b) {
        if ((a + b) % 86 == 0) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}