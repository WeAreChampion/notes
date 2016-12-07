#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct 
{
    int a;
    int b;
}Rice;
int Compare(const void *ra, const void *rb)
{
    return ((Rice*)ra)->a > ((Rice*)rb)->a ? 1 : -1;//ÉýÐò
}
int main()
{
    int ca, i;
    Rice *rice = new Rice[1001];
    double sum, f;
    cin>>ca;
    while(ca--) {
        int n, m;
        sum = 0;
        cin>>n>>m;
        for(i = 0; i < m; i++) {
            cin>>rice[i].a>>rice[i].b;
        }
        qsort(rice, m, sizeof(Rice), Compare);
        i = 0;
        while(i != m) {
            f = n * 1.0 / rice[i].a;
            if(f <= rice[i].b) {
                sum += f;
                break;
            } else {
                sum += rice[i].b;
                n = n - rice[i].a * rice[i].b;
                if(n <= 0) {
                    break;
                }
            }
            i++;
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}