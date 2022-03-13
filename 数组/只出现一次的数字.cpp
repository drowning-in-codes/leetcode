// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
// 找出那个只出现了一次的元素

#include<stdio.h>

int main()
{
    
}

int singleNumber(int* nums, int numsSize){
    int result = *nums;
    for(int i = 1;i<numsSize;i++)
    {
        result ^= nums[i];
    }
    return result;
}