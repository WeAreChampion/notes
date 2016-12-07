//最大子数组跨越中间位置，需进行双向搜索。运行时间为O(n)
find_max_crossing_subarray(int A[], int low, int mid, int hight)
{
    int left_sum = right_sum = -10000;//一个比较小的负数即可
    int sum = 0;
    int i, j;
    for(i=mid; i>= low; i--)
    {
        sum = sum + A[i];
        if(sum > left_sum){
             left_sum = sum;
             //max_left = i; //无需记录位置
        }
    }
    sun = 0;
    for(j=mid+1; j<= hight; j++)
    {
        sum = sum + A[j];
        if(sum > right_sum){
             right_sum = sum;
             //max_right = j;
        }
    }
    return right_sum + left_sum ;
}
//运行时间为O(nlgn);low = 0, 1, ...
find_maximum_subarray(int A[], int low, int high)
{
   int left_sum = right_sum = cross_sum = 0;
   int mid;
   if(low == high)
        return A[low];
   else{
        mid = (low + high)/2;
        left_sum  = find_maximum_subarray(A, low, mid);
        right_sum = find_maximum_subarray(A, mid + 1, high);
        cross_sum = find_max_crossing_subarray(A, low, mid, high);
        if(left_sum >= right_sum && left_sum >= cross_sum)
            return left_sum;
        else if(right_sum >= left_sum && right_sum >= cross_sum)
            return right_sum;
        return cross_sum;
   }
}