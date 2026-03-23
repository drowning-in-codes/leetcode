#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    int n = (int)num1.size();
    int m = (int)num2.size();
    vector<int> prod(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
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
      res.push_back(char('0' + prod[i]));

    return res.empty() ? "0" : res;
  }
};
