#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    unordered_set<int> res;
    for (int v : nums2)
      if (s.count(v))
        res.insert(v);
    return vector<int>(res.begin(), res.end());
  }
};
