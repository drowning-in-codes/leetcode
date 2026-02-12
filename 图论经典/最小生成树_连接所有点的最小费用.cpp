#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        edges.reserve(n * (n - 1) / 2);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, w});
            }
        }
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w < b.w; });
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        int cost = 0, used = 0;
        for (auto& e : edges) {
            if (find(e.u) != find(e.v)) {
                parent[find(e.u)] = find(e.v);
                cost += e.w;
                if (++used == n - 1) break;
            }
        }
        return cost;
    }

private:
    struct Edge { int u; int v; int w; };
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
};
