#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    dfs(n, 0, 0, cur, res);
    return res;
  }

private:
  void dfs(int n, int open, int close, string &cur, vector<string> &res) {
    if ((int)cur.size() == 2 * n) {
      res.push_back(cur);
      return;
    }
    if (open < n) {
      cur.push_back('(');
      dfs(n, open + 1, close, cur, res);
      cur.pop_back();
    }
    if (close < open) {
      cur.push_back(')');
      dfs(n, open, close + 1, cur, res);
      cur.pop_back();
    }
  }
};
