#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        for (char c : t) need[(unsigned char)c]++;
        int missing = (int)t.size();
        int l = 0, bestLen = 1e9, bestL = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            if (need[(unsigned char)s[r]] > 0) missing--;
            need[(unsigned char)s[r]]--;
            while (missing == 0) {
                if (r - l + 1 < bestLen) bestLen = r - l + 1, bestL = l;
                need[(unsigned char)s[l]]++;
                if (need[(unsigned char)s[l]] > 0) missing++;
                l++;
            }
        }
        return bestLen == (int)1e9 ? "" : s.substr(bestL, bestLen);
    }
};
