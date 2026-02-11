#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = n - 1;
      while (l < r) {
        long long s = (long long)nums[i] + nums[l] + nums[r];
        if (s == 0) {
          res.push_back({nums[i], nums[l], nums[r]});
          int a = nums[l], b = nums[r];
          while (l < r && nums[l] == a)
            ++l;
          while (l < r && nums[r] == b)
            --r;
        } else if (s < 0) {
          ++l;
        } else {
          --r;
        }
      }
    }
    return res;
  }
};
