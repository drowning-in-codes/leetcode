#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses, 0);
    for (auto &e : prerequisites) {
      g[e[1]].push_back(e[0]);
      indeg[e[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (indeg[i] == 0)
        q.push(i);
    vector<int> order;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      order.push_back(u);
      for (int v : g[u])
        if (--indeg[v] == 0)
          q.push(v);
    }
    return (int)order.size() == numCourses ? order : vector<int>();
  }
};
