#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int n = sorted.size();
    vector<int> bit(n + 1, 0);
    auto add = [&](int i) {
      while (i <= n) {
        bit[i]++;
        i += i & -i;
      }
    };
    auto sum = [&](int i) {
      int res = 0;
      while (i > 0) {
        res += bit[i];
        i -= i & -i;
      }
      return res;
    };
    long long ans = 0;
    for (int i = (int)nums.size() - 1; i >= 0; --i) {
      int idx = (int)(lower_bound(sorted.begin(), sorted.end(), nums[i]) -
                      sorted.begin()) +
                1;
      ans += sum(idx - 1);
      add(idx);
    }
    return (int)ans;
  }
};
