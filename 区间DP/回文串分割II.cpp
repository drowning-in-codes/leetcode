#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]))
          pal[i][j] = true;
      }
    }
    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; ++i)
      dp[i] = i - 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (pal[j][i])
          dp[i + 1] = min(dp[i + 1], dp[j] + 1);
      }
    }
    return dp[n];
  }
};
