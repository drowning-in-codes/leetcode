#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int c : coins) {
        if (i >= c)
          dp[i] = min(dp[i], dp[i - c] + 1);
      }
    }
    return dp[amount] == INF ? -1 : dp[amount];
  }
};
