/*
	已知上圆半径，下圆半径，杯子中水的体积，二分法求解杯子高度
	水平面的半径u可以根据直角梯形的面积求出：
	(r+u)*h + (u+R)*(H-h) = (r+R)*H
	得出(R-r)*h = (u-r)*H
	得 u = r + (R-r)*h/H
	圆台体积计算公式：V= π*h*( R^2 + R*u + u^2 ) / 3
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
//二分精度需要
#define eps 1e-8

double PI = acos(-1);
double r, R, H, V;

double cal(double x){
    double u = (R - r) * x / H + r;
    return PI * x * (pow(r, 2) + pow(u, 2) + r * u) / 3;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lf%lf%lf%lf", &r, &R, &H, &V);
        double left = 0,right = H;
        double mid;
		
		//二分法求解
        while(right - left > eps){
            mid = (right + left) / 2;
            if(cal(mid) - V > eps)
                right = mid;
            else
                left = mid;
        }
        printf("%.6lf\n", mid);
    }
    return 0;
}