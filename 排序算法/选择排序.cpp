#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int minIdx = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[minIdx])
          minIdx = j;
      }
      if (minIdx != i) {
        int t = nums[i];
        nums[i] = nums[minIdx];
        nums[minIdx] = t;
      }
    }
    return nums;
  }
};
