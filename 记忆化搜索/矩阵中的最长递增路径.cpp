#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
      return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, dfs(i, j, matrix, memo));
      }
    }
    return ans;
  }

private:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  int dfs(int x, int y, const vector<vector<int>> &matrix,
          vector<vector<int>> &memo) {
    if (memo[x][y])
      return memo[x][y];

    int m = matrix.size(), n = matrix[0].size();
    int best = 1;
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        continue;
      if (matrix[nx][ny] <= matrix[x][y])
        continue;
      best = max(best, 1 + dfs(nx, ny, matrix, memo));
    }
    memo[x][y] = best;
    return best;
  }
};
