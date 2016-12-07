#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
const int Stacksize = 100;
const int INCREMENT = 50;
typedef struct
{
    char *top; //�洢�ַ�ֵָ�� 
    char *base;//����
    int stacksize;//ջ�� 
}Stack;
int main()
{
    int a[1000];
    int i, k, count;
    Stack S;
    int n;
    string s1, s2;
    while(cin>>n>>s1>>s2)//����n���ִ� 
    {
        memset(a, 0, sizeof(a));//�������������ֵ 
        S.base = (char*) malloc(Stacksize * sizeof(char));//���ٿռ� 
        //���䲻�ɹ� 
		if(!S.base) {
        	return 0;
		}
        S.top = S.base;//�洢��ֵ 
        S.stacksize = Stacksize;//��ֵ 
        i = k = count = 0;
        while(k < n) {
            if(S.top - S.base >= S.stacksize) {//�洢�ռ䲻������������ 
                S.base = (char *) malloc((S.stacksize + INCREMENT) * sizeof(char)); 
                if(!S.base) { 
                	return 0;
                }
                S.top = S.base + S.stacksize;//�ı���Ӧ��ֵ 
                S.stacksize += INCREMENT;
            }
            if(S.base == S.top) {//��ջΪ�գ���ջ
                *S.top = s1[i];
                a[count++] = 1;	//��� 
                i++;			//ָ������ 
                S.top++;		//����ջ�� 
            } else {
                if(*(S.top - 1) == s2[k]) {//��ջ
                    S.top--;
                    k++;		//k��ָ 
                    count++;	//���� 
                } else {
                    if(i == n) {//���i�Ѿ�����n�˱�ʾ����
                    	break;
                    }
                    *S.top = s1[i];	//else������ջ
                    S.top++;
                    i++;
                    a[count++] = 1;
                }
            }
        }
        if(S.top == S.base) {//ջ�� 
            cout<<"Yes.\n";
            for(i = 0; i < count; i++) {
                if(a[i]) {
                	cout<<"in\n";
                }
                else {
                	cout<<"out\n";
                }
            }
            cout<<"FINISH\n";
        }
        else {
        	cout<<"No.\nFINISH\n";
        }
        free(S.base);//�ͷſռ� 
    }
    return 0;
}
/*
3 123 321
3 123 312
Sample Output
Yes.
in
in
in
out
out
out
FINISH
No.
FINISH
*/