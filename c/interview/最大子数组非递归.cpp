#include <stdio.h>
#include <stdlib.h>
 
#define LENGTH(s) (sizeof(s) / sizeof(int))
/*
	˼·�ǣ�ʼ�ձ���6���������ֱ��� result_start, result_end, 
result_sum, curr_start, curr_end, curr_sum. �α�������
��0��Ԫ�ؿ�ʼ��ÿ����һ��Ԫ�أ��Ͱ�����ֵ�ӵ�curr_sum�С�
ÿ������curr_sum��ֵ����result_sumʱ���Ͱ�curr��3������
��ֵ��ֵ��result��3�������С� ����������һ��Ҫע����ǣ�
�κ�ʱ��ֻҪcurr_sum��ֵС��0����Ҫ��curr_start�α���
ת����һ��Ԫ�أ�����curr_sum���㣬���¿�ʼ�ơ� ��Ϊcurr_sum
Ϊ0ʱ���ʹ���֮ǰ������Ԫ�ؼӺ�С��0.��ô�����κ�Ԫ�������
С��0������ӣ��϶���������������飬Ӧ�ðѱߺ�С��0��Ԫ��
ȥ����
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