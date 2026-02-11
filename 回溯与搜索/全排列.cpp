#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> cur;
    vector<int> used(nums.size(), 0);
    dfs(nums, used, cur, res);
    return res;
  }

private:
  void dfs(vector<int> &nums, vector<int> &used, vector<int> &cur,
           vector<vector<int>> &res) {
    if (cur.size() == nums.size()) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (used[i])
        continue;
      used[i] = 1;
      cur.push_back(nums[i]);
      dfs(nums, used, cur, res);
      cur.pop_back();
      used[i] = 0;
    }
  }
};
