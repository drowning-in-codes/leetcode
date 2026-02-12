#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        q.push({"0000", 0});
        vis.insert("0000");
        while (!q.empty()) {
            auto [cur, d] = q.front(); q.pop();
            if (cur == target) return d;
            for (int i = 0; i < 4; ++i) {
                string nxt = cur;
                nxt[i] = (cur[i] == '9') ? '0' : cur[i] + 1;
                if (!dead.count(nxt) && !vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, d + 1});
                }
                nxt = cur;
                nxt[i] = (cur[i] == '0') ? '9' : cur[i] - 1;
                if (!dead.count(nxt) && !vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, d + 1});
                }
            }
        }
        return -1;
    }
};
