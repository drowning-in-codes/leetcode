#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int cand = 0, cnt = 0;
    for (int v : nums) {
      if (cnt == 0)
        cand = v;
      cnt += (v == cand) ? 1 : -1;
    }
    return cand;
  }
};
