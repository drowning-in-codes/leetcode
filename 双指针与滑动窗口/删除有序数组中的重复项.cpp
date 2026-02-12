#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 1;
        for (int fast = 1; fast < (int)nums.size(); ++fast) {
            if (nums[fast] != nums[fast - 1]) nums[slow++] = nums[fast];
        }
        return slow;
    }
};
