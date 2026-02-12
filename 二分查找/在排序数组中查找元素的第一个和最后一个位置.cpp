#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lowerBound(nums, target);
        int right = upperBound(nums, target) - 1;
        if (left <= right && right < (int)nums.size() && nums[left] == target) return {left, right};
        return {-1, -1};
    }

private:
    int lowerBound(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) l = m + 1; else r = m;
        }
        return l;
    }
    int upperBound(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) l = m + 1; else r = m;
        }
        return l;
    }
};
