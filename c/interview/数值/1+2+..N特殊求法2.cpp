#include <iostream>
using namespace std;
/**
	使用静态成员变量来实现累加求和
*/
class Temp {
public:
	/**
		每次构建对象时，即进行累加求和
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
	//静态成员实现累加 
	static int N; 
	static int Sum; 
};

int Temp::N = 0;
int Temp::Sum = 0;

int solution_Sum(int n) {
	Temp::Reset();
	//开辟空间 
	Temp *a = new Temp[n];
	delete []a;
	a = NULL;
  	return Temp::GetSum();
}
int main() {
	cout << solution_Sum(100) << endl;
	return 0;  
}