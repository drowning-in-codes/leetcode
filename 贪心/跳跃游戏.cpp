#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int far = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (i > far)
        return false;
      if (i + nums[i] > far)
        far = i + nums[i];
    }
    return true;
  }
};
