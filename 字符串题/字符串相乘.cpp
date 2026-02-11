#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string multiply(string a, string b) {
    if (a == "0" || b == "0")
      return "0";
    int n = a.size(), m = b.size();
    vector<int> prod(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        int mul = (a[i] - '0') * (b[j] - '0');
        int sum = mul + prod[i + j + 1];
        prod[i + j + 1] = sum % 10;
        prod[i + j] += sum / 10;
      }
    }
    string res;
    int i = 0;
    while (i < n + m && prod[i] == 0)
      ++i;
    for (; i < n + m; ++i)
      res.push_back('0' + prod[i]);
    return res;
  }
};
