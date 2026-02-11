#include <vector>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &g) {
    int m = g.size(), n = g[0].size();
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == '1') {
          dfs(g, i, j);
          cnt++;
        }
      }
    }
    return cnt;
  }

private:
  void dfs(vector<vector<char>> &g, int i, int j) {
    int m = g.size(), n = g[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || g[i][j] != '1')
      return;
    g[i][j] = '0';
    dfs(g, i + 1, j);
    dfs(g, i - 1, j);
    dfs(g, i, j + 1);
    dfs(g, i, j - 1);
  }
};
