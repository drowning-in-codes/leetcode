#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < n; ++i) {
        int temp = nums[i];
        int j = i;
        while (j >= gap && nums[j - gap] > temp) {
          nums[j] = nums[j - gap];
          j -= gap;
        }
        nums[j] = temp;
      }
    }
    return nums;
  }
};
