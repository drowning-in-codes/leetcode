#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1)
      return nums;
    int minv = *min_element(nums.begin(), nums.end());
    int maxv = *max_element(nums.begin(), nums.end());
    int bucketCount = max(1, (int)sqrt(n));
    int bucketSize = max(1, (maxv - minv) / bucketCount + 1);
    vector<vector<int>> buckets(bucketCount);
    for (int v : nums) {
      int idx = (v - minv) / bucketSize;
      if (idx >= bucketCount)
        idx = bucketCount - 1;
      buckets[idx].push_back(v);
    }
    int k = 0;
    for (auto &b : buckets) {
      sort(b.begin(), b.end());
      for (int v : b)
        nums[k++] = v;
    }
    return nums;
  }
};
