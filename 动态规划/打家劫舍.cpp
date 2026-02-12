#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int prev2 = 0, prev1 = 0;
    for (int v : nums) {
      int cur = max(prev1, prev2 + v);
      prev2 = prev1;
      prev1 = cur;
    }
    return prev1;
  }
};
