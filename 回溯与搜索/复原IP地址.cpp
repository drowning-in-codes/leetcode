#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<string> cur;
    dfs(s, 0, cur, res);
    return res;
  }

private:
  void dfs(const string &s, int idx, vector<string> &cur, vector<string> &res) {
    if ((int)cur.size() == 4) {
      if (idx == (int)s.size()) {
        res.push_back(cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3]);
      }
      return;
    }
    if (idx >= (int)s.size())
      return;
    int num = 0;
    for (int len = 1; len <= 3 && idx + len <= (int)s.size(); ++len) {
      if (len > 1 && s[idx] == '0')
        break;
      num = num * 10 + (s[idx + len - 1] - '0');
      if (num > 255)
        break;
      cur.push_back(s.substr(idx, len));
      dfs(s, idx + len, cur, res);
      cur.pop_back();
    }
  }
};
