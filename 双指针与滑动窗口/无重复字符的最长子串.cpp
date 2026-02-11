#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> last(256, -1);
    int ans = 0, start = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (last[(unsigned char)s[i]] >= start)
        start = last[(unsigned char)s[i]] + 1;
      last[(unsigned char)s[i]] = i;
      ans = max(ans, i - start + 1);
    }
    return ans;
  }
};
