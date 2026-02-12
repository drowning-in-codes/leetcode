#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); ++fast) {
      if (nums[fast] != 0)
        nums[slow++] = nums[fast];
    }
    for (int i = slow; i < (int)nums.size(); ++i)
      nums[i] = 0;
  }
};
