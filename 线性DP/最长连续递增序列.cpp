#include <vector>
using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty())
      return 0;
    int ans = 1, cur = 1;
    for (int i = 1; i < (int)nums.size(); ++i) {
      if (nums[i] > nums[i - 1])
        cur++;
      else
        cur = 1;
      if (cur > ans)
        ans = cur;
    }
    return ans;
  }
};
