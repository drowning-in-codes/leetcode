#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    vector<int> cnt(26, 0);
    for (char c : s)
      cnt[c - 'a']++;
    for (char c : t) {
      if (--cnt[c - 'a'] < 0)
        return false;
    }
    return true;
  }
};
