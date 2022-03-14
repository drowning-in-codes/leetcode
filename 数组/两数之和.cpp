/*
 * @Author: proaniemr
 * @Date: 2022-03-13 21:31:35
 * @LastEditors: proaniemr
 * @LastEditTime: 2022-03-13 21:53:02
 * @Description: 请填写简介
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{

    int *returnarr = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++)
    {
        int j = i + 1;
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                returnarr[0] = i;
                returnarr[1] = j;
                break;
            }
            j++;
        }
    }
    return 0;
}

int main()
{
    
}