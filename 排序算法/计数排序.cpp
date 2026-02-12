#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (nums.empty())
      return nums;
    int minv = *min_element(nums.begin(), nums.end());
    int maxv = *max_element(nums.begin(), nums.end());
    int range = maxv - minv + 1;
    vector<int> cnt(range, 0);
    for (int v : nums)
      cnt[v - minv]++;
    int idx = 0;
    for (int i = 0; i < range; ++i) {
      while (cnt[i]-- > 0)
        nums[idx++] = i + minv;
    }
    return nums;
  }
};
