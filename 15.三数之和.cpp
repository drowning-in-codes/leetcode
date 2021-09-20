/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        //进行从小到大排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int first, second, third;

        int target;

        for (first = 0; first < nums.size(); first++)
        {

            if (first > 0 && (nums[first] == nums[first - 1]))
                continue; //第一个数字不重复
            target = -nums[first];

            third = nums.size() - 1;
            for (second = first + 1; second < nums.size(); second++)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;//第二个数字不重复

                while(second<third&&nums[second] + nums[third] > target)
                {
                    third--;
                }
                if (second==third)
                {
                    break;
                }
                
                if (nums[second] + nums[third] == target)
                {
                    ans.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end
