/*
 * @Author: proaniemr
 * @Date: 2022-03-12 21:18:39
 * @LastEditors: proaniemr
 * @LastEditTime: 2022-03-12 22:00:35
 * @Description: 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
 */

#include<stdio.h>
void moveZeroes(int* nums, int numsSize){
    //双指针
   int count = 0;
    for(int i = 0;i<numsSize;i++)
    {
       if(nums[i]==0)
       {
           count++;
       }
       else if(count!=0)
       {
           nums[i-count] = nums[i];
           nums[i] =0;
       }
        
    }

}
int main()
{
    int nums[] = {0,1,0,3,12};
    moveZeroes(nums,5);
    for(int i =0;i<5;i++)
    {
        printf("%d",nums[i]);
    }
    return 0;

}

