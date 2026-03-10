#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> memo(n, -1);
    return dfs(0, s, memo);
  }

private:
  int dfs(int i, const string &s, vector<int> &memo) {
    if (i == (int)s.size())
      return 1;
    if (s[i] == '0')
      return 0;
    if (memo[i] != -1)
      return memo[i];

    int ways = dfs(i + 1, s, memo);
    if (i + 1 < (int)s.size()) {
      int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
      if (val >= 10 && val <= 26)
        ways += dfs(i + 2, s, memo);
    }
    memo[i] = ways;
    return ways;
  }
};
