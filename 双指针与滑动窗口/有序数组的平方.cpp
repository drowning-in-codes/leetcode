#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    int l = 0, r = n - 1, k = n - 1;
    while (l <= r) {
      int a = nums[l] * nums[l];
      int b = nums[r] * nums[r];
      if (a > b) {
        res[k--] = a;
        ++l;
      } else {
        res[k--] = b;
        --r;
      }
    }
    return res;
  }
};
