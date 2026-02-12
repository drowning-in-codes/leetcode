#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      bool swapped = false;
      for (int j = 1; j < n - i; ++j) {
        if (nums[j - 1] > nums[j]) {
          int t = nums[j - 1];
          nums[j - 1] = nums[j];
          nums[j] = t;
          swapped = true;
        }
      }
      if (!swapped)
        break;
    }
    return nums;
  }
};
