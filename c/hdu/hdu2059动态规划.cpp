#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// To get the min value between x and y
#define min(x, y) ((x > y) ? y : x)
/*
	�������ܣ��ܵ���L�ף�������Vr m/s�ٶ��ܣ��ڹ��е綯�����е�ʱ��V1 m/s�ٶ��ܣ�û�е�ʱ���Խŵŵ��ٶ���V2 m/s���ڹ����ܵ���������N�����վ�����һ�ο�����C�ף���Ҫ�ķѳ��ʱ��Ts�����й�N�����վ����i�����վ����ԭ��p[i]�ף��ڹ꾭�����վ����ѡ����Ͳ���硣
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
	    		
	        	if(dis <= C) {// Power is more. �����㹻�ҳ�� 
					time = T + dis / V1;
	        	} else { // ���������ҳ�� 
					time = T + C / V1 + (dis - C) / V2;
	        	}
	      		//printf("P[i]=%.2f P[j]=%.2f  time=%.2f\n",P[i],P[j],time);
	      		// �ճ���ʱ�䲻��Ҫ��� 
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