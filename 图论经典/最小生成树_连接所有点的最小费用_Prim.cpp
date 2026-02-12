#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    vector<int> dist(n, 1e9);
    vector<int> vis(n, 0);
    dist[0] = 0;
    int cost = 0;
    for (int i = 0; i < n; ++i) {
      int u = -1;
      for (int j = 0; j < n; ++j) {
        if (!vis[j] && (u == -1 || dist[j] < dist[u]))
          u = j;
      }
      vis[u] = 1;
      cost += dist[u];
      for (int v = 0; v < n; ++v) {
        if (vis[v])
          continue;
        int w =
            abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
        if (w < dist[v])
          dist[v] = w;
      }
    }
    return cost;
  }
};
