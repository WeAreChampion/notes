#include <stdio.h>
#include <stdlib.h>
/*
	最大字数组问题的简单描述：给定一个输入的数组，
求解此数组的子数组（元素必须是连续的）中所有元素
和最大的那个子数组。 这个算法最简单也最容易理解的
应该是非递归的方式。 这里看到《算法导论》第3版讲
到“分治”这一章给出的案例，用c语言实现一下，以
加深印象。
	这个算法的分治思路是：给定的输入数组，取中间
元素将数组分为左右连个子数组，那么这个输入数组的
最大子数组可能有3种情况。 分别是，a)完全位于左子
数组中，b)完全位于右子数组中，和c）跨越中点。 那
么问题就成了，求解这3种情况下的最大子数组。而a和
b情况，刚好与求解最初输入数组类似，形成递归。 c情
况则是一个简单问题。由一个单独的函数实现。
*/ 
#define LENGTH(s) (sizeof(s) / sizeof(int))
struct subarray{
    int start;
    int end;
    int sum;
};
  
void find_max_cross(int* array, intstart, int mid, int end, struct subarray *p) {
    int left_sum = 0;
    int left = 0;
    int right_sum = 0;
    int right = 0;
 
    int tmp_sum = 0;
 
    int i = 0;
    for (i = mid; i >= start; i--) {
        tmp_sum = tmp_sum + array[i];
        if (tmp_sum > left_sum) {
            left_sum = tmp_sum;
            left = i;
        }
    }
 
    tmp_sum = 0;
    for (i = mid + 1; i<= end; i++) {
        tmp_sum = tmp_sum + array[i];
        if (tmp_sum > right_sum) {
            right_sum = tmp_sum;
            right = i;
        }
    }
 
    p->start = left;
    p->end = right;
    p->sum = left_sum + right_sum;
}
 
void find_max_subarray(int* array, int start, int end, struct subarray *p) {
    struct subarray sa_left;
    struct subarray sa_right;
    struct subarray sa_cross;
 
    if (start == end) {
        p->start = start;
        p->end = start;
        p->sum = array[start];
        return;
    }
 
    int mid = (start + end) / 2;
 
    find_max_subarray(array, start, mid, &sa_left);
    find_max_subarray(array, mid + 1, end, &sa_right);
    find_max_cross(array, start, mid, end, &sa_cross);
 
    if (sa_left.sum > sa_right.sum && sa_left.sum > sa_cross.sum) {
        p->start = sa_left.start;
        p->end = sa_left.end;
        p->sum = sa_left.sum;
    } else if (sa_right.sum > sa_left.sum && sa_right.sum > sa_cross.sum) {
        p->start = sa_right.start;
        p->end = sa_right.end;
        p->sum = sa_right.sum;
    } else {
        p->start = sa_cross.start;
        p->end = sa_cross.end;
        p->sum = sa_cross.sum;
    }
} 
int main() {
 
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
 
    struct subarray sa;
    
	find_max_subarray(array, 0, LENGTH(array) - 1, &sa);
 
    printf("max subarray : %d - %d, sum : %d", sa.start, sa.end, sa.sum);
    return EXIT_SUCCESS;
}