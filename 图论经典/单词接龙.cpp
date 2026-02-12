#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
      return 0;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> vis;
    vis.insert(beginWord);
    while (!q.empty()) {
      auto [w, d] = q.front();
      q.pop();
      if (w == endWord)
        return d;
      for (int i = 0; i < (int)w.size(); ++i) {
        char old = w[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          if (c == old)
            continue;
          w[i] = c;
          if (dict.count(w) && !vis.count(w)) {
            vis.insert(w);
            q.push({w, d + 1});
          }
        }
        w[i] = old;
      }
    }
    return 0;
  }
};
