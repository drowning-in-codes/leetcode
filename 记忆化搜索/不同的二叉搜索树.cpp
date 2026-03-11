#include <vector>

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
    return dfs(1, n, memo);
  }

private:
  int dfs(int l, int r, vector<vector<int>> &memo) {
    if (l >= r)
      return 1;
    if (memo[l][r] != -1)
      return memo[l][r];

    long long ways = 0;
    for (int root = l; root <= r; ++root) {
      ways += 1LL * dfs(l, root - 1, memo) * dfs(root + 1, r, memo);
    }
    memo[l][r] = (int)ways;
    return memo[l][r];
  }
};
