#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, v, w, p[100];
    int i;
    float density;
    int count;
    int sum_den;
    int ca;
    cin >> ca;
    while(ca--) {
	    scanf("%d %d %d", &n, &v, &w);
		for(i = 0; i < n; i++) {
  			scanf("%d", &p[i]);
     	}
     	//sort the array p from small to big
	   	sort(p, p + n);
	   	/*
	   	cout << "The array p is :" << endl;
	   	for(int i = 0; i <n; i++) {
	   		cout << p[i] <<" ";
	   	}
	   	cout << endl;
	   	*/
	 	if(p[0] > w) {
	      	printf("0 0.00\n");
	    	continue;
	 	}
	 	count = 0;
		density = 0.0;
  		sum_den = 0;
	  	do {
	  		//每次添加相应的体积和相应的溶度，
		  	//若不超过结果，则表明还可以添加
			//否则还可以添加(体积相同的情况下) 
	      	sum_den += p[count];
	      	//w * (count + 1) * v >= sum_den * v
	       	//这里有可能相等,一定要尽可能转化成整数的比较，如果是浮点数，就麻烦了
	      	if(w * (count + 1) >= sum_den) {
	         	count++;
	         	density = sum_den * 1.0 / count ;
	      	} else { 
	          	  break;
	       	} 
	  	} while(count < n);
	  	//输出相应的体积和 和 浓度% 
	 	printf("%d %.2f\n", count * v, density / 100);
	}
    return 0;
}
/*
Sample Input
3
1 100 10
100
2 100 24
20 30
3 100 24
20 30 20
 

Sample Output
0 0.00
100 0.20
300 0.23

*/ 