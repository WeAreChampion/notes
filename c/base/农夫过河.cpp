#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STEP 20
/*
	1.index: 0－狼，1－羊，2－菜，3－农夫
	2.value：0－本岸，1－对岸
	3.农夫过河，狼吃羊，羊吃菜，一次只能携带一种，
		求无损解决方案。 
	4.a[i][j]取值为0 或者 1，表示第i次过河时j所在的位置。
	5.b[i]表示第i次过河时船上携带的东西。，农夫每次都必须
		在船上，所有不用记录，除非船上只有农夫一个人。 
		
	所以，是否全部过河的问题就转化为判断a[i][0], a[i][1],
		a[i][2],a[i][3]是否全为1，即相加之和是否为4；而四
		者中的两者能否在一起就将转化它们各自的a[i][j]是否
		相等的问题了。 
*/
int a[MAX_STEP][4];
int b[MAX_STEP];
//携带的物品 
char *name[] = 
{
	"空手",
	"带狼",
	"带羊",
	"带菜"
};
//iStep 表示递归深度. 
void search(int iStep)
{
	int i;
 	//都到达对岸，递归结束，并输出可行解 
 	if(a[iStep][0] + a[iStep][1] + a[iStep][2] + a[iStep][3] == 4){
  		for(i = 0; i < iStep; i++) {
  			//标志位，为0则表示到对岸去，同时输出携带的东西 
   			if(a[i][3] == 0) {
    			printf("%s到对岸\n", name[b[i] + 1]);
   			} else {//为1则表示回本岸
    			printf("%s回本岸\n", name[b[i] + 1]);
   			}
  		}
  		printf("\n");
  		return;
 	}
 	//过河过程是否出现过，出现过则直接结束 
 	for(i = 0; i < iStep; i++) {
  		if(memcmp(a[i], a[iStep], sizeof(a[i])) == 0) {
   			return;
  		}
 	}
 	//羊不和农夫一起且羊和菜一起或者狼和羊一起
 	//	递归结束。
	 
 	if(a[iStep][1] != a[iStep][3] 
	 	&& (a[iStep][2] == a[iStep][1] 
	 	|| a[iStep][0] == a[iStep][1])) {
  		return;
 	}
 	//没有出现过，则将过河后抵达另一岸的结果记录下来， 
 	//并进行下一次搜索。
 	//该运输情况以前是否执行过（即两岸以及船上
	//	的东西以及各自位置和以前完全相同）
	for(i = -1; i <= 2; i++) {
	  	b[iStep] = i;
	  	//改变各自的状态，回本岸或者去对岸 
	  	//copy array a[iStep] -> a[iStep + 1]
	  	memcpy(a[iStep + 1], a[iStep], sizeof(a[iStep + 1]));
	  	
	  	//change a[iStep + 1][3] value = 1 - a[iStep + 1][3];
	  	a[iStep + 1][3] = 1 - a[iStep + 1][3];
	  	//i == -1时，进行下一步搜索 
 		if (i == -1) {
	   		search(iStep + 1);
	  	} else if (a[iStep][i] == a[iStep][3]) {//农夫和当前物品一起过河 
   			//两者状态相同 
			a[iStep + 1][i] = a[iStep + 1][3];
			//下一步 
			search(iStep + 1);
  		}
 	}
}
int main()
{
	search(0);
	return 0;
}