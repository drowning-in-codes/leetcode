#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> ndist = dist;
            for (auto& e : flights) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INF && dist[u] + w < ndist[v]) ndist[v] = dist[u] + w;
            }
            dist.swap(ndist);
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};
