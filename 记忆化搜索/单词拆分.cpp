#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> memo(s.size(), -1);
    return dfs(0, s, dict, memo);
  }

private:
  bool dfs(int i, const string &s, const unordered_set<string> &dict,
           vector<int> &memo) {
    if (i == (int)s.size())
      return true;
    if (memo[i] != -1)
      return memo[i];

    string cur;
    for (int j = i; j < (int)s.size(); ++j) {
      cur.push_back(s[j]);
      if (dict.count(cur) && dfs(j + 1, s, dict, memo)) {
        memo[i] = 1;
        return true;
      }
    }
    memo[i] = 0;
    return false;
  }
};
