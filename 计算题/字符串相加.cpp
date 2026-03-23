#include <string>
using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    int i = (int)num1.size() - 1;
    int j = (int)num2.size() - 1;
    int carry = 0;
    string res;

    while (i >= 0 || j >= 0 || carry) {
      int x = i >= 0 ? num1[i] - '0' : 0;
      int y = j >= 0 ? num2[j] - '0' : 0;
      int sum = x + y + carry;
      res.push_back(char('0' + (sum % 10)));
      carry = sum / 10;
      --i;
      --j;
    }

    for (int l = 0, r = (int)res.size() - 1; l < r; ++l, --r) {
      char t = res[l];
      res[l] = res[r];
      res[r] = t;
    }
    return res;
  }
};
