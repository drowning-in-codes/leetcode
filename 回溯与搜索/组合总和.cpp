#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs(candidates, 0, target, cur, res);
    return res;
  }

private:
  void dfs(vector<int> &c, int idx, int target, vector<int> &cur,
           vector<vector<int>> &res) {
    if (target == 0) {
      res.push_back(cur);
      return;
    }
    for (int i = idx; i < (int)c.size(); ++i) {
      if (c[i] > target)
        continue;
      cur.push_back(c[i]);
      dfs(c, i, target - c[i], cur, res);
      cur.pop_back();
    }
  }
};
