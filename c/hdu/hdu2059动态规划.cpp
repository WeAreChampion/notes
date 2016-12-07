#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// To get the min value between x and y
#define min(x, y) ((x > y) ? y : x)
/*
	龟兔赛跑，跑道长L米，兔子以Vr m/s速度跑，乌龟有电动车，有电时以V1 m/s速度跑，没有电时，以脚蹬的速度跑V2 m/s。乌龟在跑道上设置了N个充电站，充电一次可以跑C米，需要耗费充电时间Ts；其中共N个充电站，第i个充电站距离原点p[i]米；乌龟经过充电站可以选择充电和不充电。
*/
int main()
{
	int i,j,N;
	float time, Min, dp[101], L, C, T, Vr, V1, V2, P[101];

  	while(scanf("%f", &L) != EOF) {
	    scanf("%d%f%f%f%f%f", &N, &C, &T, &Vr, &V1, &V2);
	    // The distance from start to the i-st power station
	    for(i = 1; i <= N; i++) {
	    	scanf("%f", &P[i]);
	    }
		
		// To init the distance start and end	
	    P[0] = 0;
	    P[i] = L;
	    
	    // To init the dp
	    dp[0] = 0;
	    for(i = 1; i <= N + 1; i++) {
			dp[i] = 100000000.0;
	    }
	    
	    // For each
	    for(i = 1; i <= N + 1; i++) {
	    	for(j = 0; j <= i - 1; j++) {
	    		double dis = P[i] - P[j];
	    		
	        	if(dis <= C) {// Power is more. 电量足够且充电 
					time = T + dis / V1;
	        	} else { // 电量不够且充电 
					time = T + C / V1 + (dis - C) / V2;
	        	}
	      		//printf("P[i]=%.2f P[j]=%.2f  time=%.2f\n",P[i],P[j],time);
	      		// 刚出发时间不需要充电 
	        	if( j == 0) {
					time -= T;
	        	}
	        	// To get the min
	       		Min = dp[j] + min( time , dis / V2 );
				//printf("time=%.2f dp[j]=%.2f  %d~%d     Min=%.2f   \n",time,dp[j],j,i,Min);
	   			if( dp[i]> Min) {
				 	dp[i] = Min;
	   			}
	   			
	      	}
	    	//printf(" dp[%d]=%.2f\n",i,dp[i]);
	   	}
	  	//printf("~%.2f   %.2f\n",dp[N+1],L/Vr*1.0);
	    if(dp[N + 1] < L / Vr * 1.0) {
	    	printf("What a pity rabbit!\n");
	    }
		else {
			printf("Good job,rabbit!\n");
		}
  	}
  	return 0;
}

/**
Sample Input

100
3 20 5
5 8 2
10 40 60
100
3 60 5
5 8 2
10 40 60


Sample Output

Good job,rabbit!
What a pity rabbit!
*/