// 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；
// 如果数组中每个元素互不相同，返回 false

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bool containsDuplicate(int* nums, int numsSize){
//     //一般两层循环  可能超时
//     for(int i = 0;i<numsSize-1;i++)
//     {
//         for(int j = i+1;j<numsSize;j++)
//         {
//             if(nums[i] == nums[j])
//             {
//                 return true;
//             }
//         }
//     }
//     return false;

// }

int main()
{
    class Solution
    {
    public:
        bool containsDuplicate(vector<int> &nums)
        {
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size()-1;i++)
            {
                
                    if(nums[i] == nums[i+1])
                    {
                        return true;
                    }
                
            }
            return false;
        }
    };
}