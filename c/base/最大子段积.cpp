#include<iostream>
using namespace std;
/*
	1.��һ�����������У�ȡ���˻������е�ֵ��
���� -2.5��4��0��3��0.5��8��-1����ȡ������
��˻�������Ϊ3��0.5��8��
	2.��Ҫ�������������������ǰλ�����е���
��˻�����С�˻�.
	3.Ȼ����Ҫ�Ƚ����Σ�һ�������˻�����
С�˻��Ƿ���Ҫ����������һ���ǲ���ֻѡ��ǰ
λ�þ�����õ�.
*/
/*
	��������������Ϊa[]��ֱ�����ö�������⣬����
�����ܴ��ڸ����������������Max[i]����ʾ��a[i]��β
��������������еĳ˻�ֵ����Min[i]��ʾ��a[i]��β��
��С�����������еĳ˻�ֵ����ô״̬ת�Ʒ���Ϊ��
   	Max[i] = max{a[i], Max[i - 1] * a[i], Min[i - 1] * a[i]};
   	Min[i] = min{a[i], Max[i - 1] * a[i], Min[i - 1] * a[i]};
��ʼ״̬ΪMax[1] = Min[1] = a[1]���������£�

	����һ���������飬�����и�����0���������,�����±��1����
��������������г˻��������������У������������г˻�Ϊ
��������ô�����-1
	��Max[i]��ʾ��a[i]��β�˻���������������
	��Min[i]��ʾ��a[i]��β�˻���С�����������У���Ϊ�и���������
��������Ǳ����
*/

int startPos;
int endPos;
double maxMulti(double v[], int n) {
	double maxt = 1;
    double mint = 1;
    //save the multiply's max value
    double maxv = v[0];
    //for each the array
    for(int i = 0; i < n; ++i) {
  		//v[i] is 0 then reset the value
        if(v[i] == 0) {
            maxt = 1;
            mint = 1;
            if (v[i] > maxv) { 
                maxv = 0;
                startPos = i;
            } 
        } else{
			double oriMint = mint;
            double oriMaxt = maxt;
            //To calculate v[i] * mint
            double minrst = mint * v[i];
            //To calculate v[i] * maxt
            double maxrst = maxt * v[i];
            //To get the max
            maxt = maxrst > minrst ? maxrst : minrst;
            //To get the min
            mint = maxrst > minrst ? minrst : maxrst;
            //If the maxt < v[i] then save the max value v[i] into maxt
            if (maxt < v[i]) { 
                maxt = v[i];
                endPos = i;
            }
            //If the mint > v[i] then save the min value v[i] into mint
            if (mint > v[i]) { 
                mint = v[i];
                startPos = i - 1;
            }
            //If the maxt > maxv then save into maxv
            if (maxv < maxt) { 
                maxv = maxt;
                endPos = i;
            } 
        }
    }
    //return the max multiple value
	return maxv;
}
int main()
{
	int length, i, j, m, n;
	double array[100]; 
	while(cin >> length) {
		for(i = 0; i < length; i++) {
			cin >> array[i];
		}
		cout << maxMulti(array, length) << endl;
		cout << "startPos = " << startPos << endl;
		cout << "endPos = " << endPos << endl;
	}
}
/*
7
-2.5 4 0 -3 -0.5 8 -1
7
-2.5 4 0 -3 -0.5 -8 -1
4
-1 1000 -0.1 15
3
12 0.1 15
5
-1 -2 0 1 2
*/