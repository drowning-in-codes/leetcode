#include <vector>
using namespace std;

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> dp(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = n; j >= 1; --j) {
        if (nums1[i - 1] == nums2[j - 1])
          dp[j] = dp[j - 1] + 1;
        else
          dp[j] = 0;
        if (dp[j] > ans)
          ans = dp[j];
      }
    }
    return ans;
  }
};
