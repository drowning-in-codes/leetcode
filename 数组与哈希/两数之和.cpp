#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)nums.size(); ++i) {
      int need = target - nums[i];
      if (pos.count(need))
        return {pos[need], i};
      pos[nums[i]] = i;
    }
    return {};
  }
};
