#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  // 示例：n 个点，边列表 (u, v, w)，返回任意两点最短路矩阵
  vector<vector<int>> floyd(int n, vector<vector<int>> &edges) {
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
      dist[i][i] = 0;
    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];
      dist[u][v] = min(dist[u][v], w);
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        if (dist[i][k] == INF)
          continue;
        for (int j = 0; j < n; ++j) {
          if (dist[k][j] == INF)
            continue;
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    return dist;
  }
};
