#include <iostream>
using namespace std;
/**
	ʹ�þ�̬��Ա������ʵ���ۼ����
*/
class Temp {
public:
	/**
		ÿ�ι�������ʱ���������ۼ����
	*/
	Temp() {
    	++N;
  		Sum += N;
	}
	static void Reset() {
    	N = 0;
    	Sum = 0;
  	}
 	static int GetSum() {
       	return Sum;
	}
private:
	//��̬��Աʵ���ۼ� 
	static int N; 
	static int Sum; 
};

int Temp::N = 0;
int Temp::Sum = 0;

int solution_Sum(int n) {
	Temp::Reset();
	//���ٿռ� 
	Temp *a = new Temp[n];
	delete []a;
	a = NULL;
  	return Temp::GetSum();
}
int main() {
	cout << solution_Sum(100) << endl;
	return 0;  
}