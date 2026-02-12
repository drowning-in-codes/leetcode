#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto &e : times)
      g[e[0]].push_back({e[1], e[2]});
    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    dist[k] = 0;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, k});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d != dist[u])
        continue;
      for (auto &[v, w] : g[u]) {
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.push({dist[v], v});
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      ans = max(ans, dist[i]);
    return ans == INF ? -1 : ans;
  }
};
