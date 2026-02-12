#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, len = 1;
    for (int i = 0; i < n; ++i) {
      expand(s, i, i, start, len);
      expand(s, i, i + 1, start, len);
    }
    return s.substr(start, len);
  }

private:
  void expand(const string &s, int l, int r, int &start, int &len) {
    int n = s.size();
    while (l >= 0 && r < n && s[l] == s[r]) {
      --l;
      ++r;
    }
    int cur = r - l - 1;
    if (cur > len) {
      len = cur;
      start = l + 1;
    }
  }
};
