/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int i=0,j=0;
   
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]>nums2[j])
            {
                num.push_back(nums2[j]);
                j++;
            }
            else
            {
                num.push_back(nums1[i]);
                i++;
               
            }
        }
        while(i<nums1.size())
        {
            num.push_back(nums1[i]);
            i++;
        }
          while(j<nums2.size())
        {
            num.push_back(nums2[j]);
            j++;
        }
        int mid = (nums1.size()+nums2.size())/2;
        double result;
    /**
     * @brief 如果num.size()是偶数,则为中间两个值的均值
     * 否则为中间值
     * 
     */
    int size = num.size();
    if(size%2==0)
    {
        result = (num[mid]+num[mid-1])/2.0;

    }
    else
    {
        result = num[mid];
    }
        return result;
    }
};
// @lc code=end

