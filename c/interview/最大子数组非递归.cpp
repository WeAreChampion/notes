#include <stdio.h>
#include <stdlib.h>
 
#define LENGTH(s) (sizeof(s) / sizeof(int))
/*
	思路是，始终保留6个变量，分别是 result_start, result_end, 
result_sum, curr_start, curr_end, curr_sum. 游标从数组的
第0号元素开始，每经过一个元素，就把它的值加到curr_sum中。
每当发现curr_sum的值大于result_sum时，就把curr的3个变量
的值赋值到result的3个变量中。 但是其中有一点要注意的是，
任何时候，只要curr_sum的值小于0，就要把curr_start游标跳
转到下一个元素，并把curr_sum清零，重新开始计。 因为curr_sum
为0时，就代表之前的所有元素加和小于0.那么后续任何元素与这个
小于0的数相加，肯定都不是最大子数组，应该把边和小于0的元素
去掉。
*/ 
int main(void) {
 
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    //int array[] = {-1, -2, -3};
 
    int result_start = 0, result_end = 0, result_sum = 0;
    int curr_start = 0;
    int curr_end = 0;
    int curr_sum = 0;
 
    int length = LENGTH(array);
 
    int i;
    for (i = 0; i < length; i++) {
        curr_end = i;
        curr_sum = curr_sum + array[i];
 
        if (curr_sum < 0) {
            curr_start = i + 1;
            curr_sum = 0;
            continue;
        }
 
        if (curr_sum > result_sum) {
            result_sum = curr_sum;
            result_start = curr_start;
            result_end = curr_end;
        }
    }
 
    printf("max subarry : %d - %d, sum : %d \n", result_start, result_end, result_sum);
 
    return EXIT_SUCCESS;
}