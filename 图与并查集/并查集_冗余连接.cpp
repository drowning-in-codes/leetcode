#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i)
      parent[i] = i;
    for (auto &e : edges) {
      int a = e[0], b = e[1];
      if (find(a) == find(b))
        return e;
      parent[find(a)] = find(b);
    }
    return {};
  }

private:
  vector<int> parent;
  int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
};
